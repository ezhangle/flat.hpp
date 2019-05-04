/*******************************************************************************
 * This file is part of the "https://github.com/blackmatov/flat.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2019, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#define CATCH_CONFIG_FAST_COMPILE
#include "catch.hpp"

#include "flat_map.hpp"
using namespace flat_hpp;

namespace
{
    template < typename T >
    class dummy_allocator {
    public:
        using value_type = T;

        T* allocate(std::size_t n) {
            (void)n;
            return nullptr;
        }

        void deallocate(T* p, std::size_t n) {
            (void)p;
            (void)n;
        }
    };
}

TEST_CASE("flat_map") {
    SECTION("types") {
        using map_t = flat_map<int, unsigned>;

        static_assert(
            std::is_same<map_t::key_type, int>::value,
            "unit test static error");
        static_assert(
            std::is_same<map_t::mapped_type, unsigned>::value,
            "unit test static error");
        static_assert(
            std::is_same<map_t::value_type, std::pair<int, unsigned>>::value,
            "unit test static error");

        static_assert(
            std::is_same<map_t::size_type, std::size_t>::value,
            "unit test static error");
        static_assert(
            std::is_same<map_t::difference_type, std::ptrdiff_t>::value,
            "unit test static error");

        static_assert(
            std::is_same<map_t::reference, std::pair<int, unsigned>&>::value,
            "unit test static error");
        static_assert(
            std::is_same<map_t::const_reference, const std::pair<int, unsigned>&>::value,
            "unit test static error");

        static_assert(
            std::is_same<map_t::pointer, std::pair<int, unsigned>*>::value,
            "unit test static error");
        static_assert(
            std::is_same<map_t::const_pointer, const std::pair<int, unsigned>*>::value,
            "unit test static error");
    }
    SECTION("ctors") {
        using alloc_t = dummy_allocator<
            std::pair<int,unsigned>>;

        using map_t = flat_map<
            int,
            unsigned,
            std::less<int>,
            alloc_t>;

        {
            auto s0 = map_t();
            auto s1 = map_t(alloc_t());
            auto s2 = map_t(std::less<int>());
            auto s3 = map_t(std::less<int>(), alloc_t());
        }

        {
            std::vector<std::pair<const int,unsigned>> v;
            auto s0 = map_t(v.cbegin(), v.cend());
            auto s1 = map_t(v.cbegin(), v.cend(), alloc_t());
            auto s2 = map_t(v.cbegin(), v.cend(), std::less<int>());
            auto s3 = map_t(v.cbegin(), v.cend(), std::less<int>(), alloc_t());
        }

        {
            auto s0 = map_t({{0,1}, {1,2}});
            auto s1 = map_t({{0,1}, {1,2}}, alloc_t());
            auto s2 = map_t({{0,1}, {1,2}}, std::less<int>());
            auto s3 = map_t({{0,1}, {1,2}}, std::less<int>(), alloc_t());
        }
    }
    SECTION("capacity") {
        using map_t = flat_map<int, unsigned>;
        map_t s0;
        s0.empty();
        s0.size();
        s0.max_size();
    }
    SECTION("inserts") {
        struct obj_t {
            obj_t(int i) : i(i) {}
            int i;
        };

        using map_t = flat_map<int, obj_t>;

        {
            map_t s0;
            s0.insert(std::make_pair(1, 42));
            s0.insert(std::make_pair(2, obj_t(42)));
            s0.insert(s0.cend(), std::make_pair(3, 84));
            s0.insert(s0.cend(), std::make_pair(4, obj_t(84)));
            s0.emplace(5, 100500);
            s0.emplace_hint(s0.cend(), 6, 100500);
        }
    }
    SECTION("erasers") {
        using map_t = flat_map<int, unsigned>;
        map_t s0;
        s0.clear();
        s0.erase(s0.begin());
        s0.erase(s0.cbegin());
        s0.erase(s0.begin(), s0.end());
        s0.erase(s0.cbegin(), s0.cend());
        s0.erase(42);
        map_t s1;
        s0.swap(s1);
        swap(s0, s1);
    }
}
