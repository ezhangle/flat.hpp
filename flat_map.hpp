/*******************************************************************************
 * This file is part of the "https://github.com/blackmatov/flat.hpp"
 * For conditions of distribution and use, see copyright notice in LICENSE.md
 * Copyright (C) 2019, by Matvey Cherevko (blackmatov@gmail.com)
 ******************************************************************************/

#pragma once

#include <vector>
#include <memory>
#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>
#include <type_traits>
#include <initializer_list>

namespace flat_hpp
{
    template < typename Key
             , typename Value
             , typename Compare = std::less<Key>
             , typename Allocator = std::allocator<std::pair<Key, Value>> >
    class flat_map final {
        using data_type = std::vector<std::pair<Key, Value>, Allocator>;
    public:
        using key_type = Key;
        using mapped_type = Value;
        using value_type = typename data_type::value_type;

        using size_type = typename data_type::size_type;
        using difference_type = typename data_type::difference_type;

        using key_compare = Compare;
        using allocator_type = Allocator;

        using reference = typename data_type::reference;
        using const_reference = typename data_type::const_reference;
        using pointer = typename data_type::pointer;
        using const_pointer = typename data_type::const_pointer;

        using iterator = typename data_type::iterator;
        using const_iterator = typename data_type::const_iterator;
        using reverse_iterator = typename data_type::reverse_iterator;
        using const_reverse_iterator = typename data_type::const_reverse_iterator;

        class value_compare final : public std::binary_function<value_type, value_type, bool> {
        public:
            bool operator()(const value_type& l, const value_type& r) const {
                return compare_(l.first, r.first);
            }
        private:
            friend class flat_map;
            explicit value_compare(const key_compare& compare)
            : compare_(compare) {}
        private:
            key_compare compare_;
        };

        static_assert(
            std::is_same<typename allocator_type::value_type, value_type>::value,
            "Allocator::value_type must be same type as value_type");
    public:
        explicit flat_map(
            const Allocator& a)
        : data_(a) {}

        explicit flat_map(
            const Compare& c = Compare(),
            const Allocator& a = Allocator())
        : data_(a)
        , compare_(c) {}

        template < typename InputIter >
        flat_map(
            InputIter first,
            InputIter last,
            const Allocator& a)
        : data_(a) {
            insert(first, last);
        }

        template < typename InputIter >
        flat_map(
            InputIter first,
            InputIter last,
            const Compare& c = Compare(),
            const Allocator& a = Allocator())
        : data_(a)
        , compare_(c) {
            insert(first, last);
        }

        flat_map(
            std::initializer_list<value_type> il,
            const Allocator& a)
        : data_(a) {
            insert(il.begin(), il.end());
        }

        flat_map(
            std::initializer_list<value_type> il,
            const Compare& c = Compare(),
            const Allocator& a = Allocator())
        : data_(a)
        , compare_(c) {
            insert(il.begin(), il.end());
        }

        iterator begin() noexcept { return data_.begin(); }
        const_iterator begin() const noexcept { return data_.begin(); }
        const_iterator cbegin() const noexcept { return data_.cbegin(); }

        iterator end() noexcept { return data_.end(); }
        const_iterator end() const noexcept { return data_.end(); }
        const_iterator cend() const noexcept { return data_.cend(); }

        reverse_iterator rbegin() noexcept { return data_.rbegin(); }
        const_reverse_iterator rbegin() const noexcept { return data_.rbegin(); }
        const_reverse_iterator crbegin() const noexcept { return data_.crbegin(); }

        reverse_iterator rend() noexcept { return data_.rend(); }
        const_reverse_iterator rend() const noexcept { return data_.rend(); }
        const_reverse_iterator crend() const noexcept { return data_.crend(); }

        bool empty() const noexcept {
            return data_.empty();
        }

        size_type size() const noexcept {
            return data_.size();
        }

        size_type max_size() const noexcept {
            return data_.max_size();
        }

        template < typename P
                 , typename = std::enable_if_t<std::is_constructible<value_type, P>::value> >
        std::pair<iterator, bool> insert(P&& p) {
            //TODO(BlackMat): implme
            return std::make_pair(end(), false);
        }

        template < typename P
                 , typename = std::enable_if_t<std::is_constructible<value_type, P>::value> >
        std::pair<iterator, bool> insert(const_iterator hint, P&& p) {
            //TODO(BlackMat): implme
            return std::make_pair(end(), false);
        }

        template < typename InputIter >
        void insert(InputIter first, InputIter last) {
            for ( auto iter = first; iter != last; ++iter ) {
                insert(*iter);
            }
        }

        template < typename... Args >
        std::pair<iterator, bool> emplace(Args&&... args) {
            //TODO(BlackMat): implme
            return insert(value_type(std::forward<Args>(args)...));
        }

        template < typename... Args >
        std::pair<iterator, bool> emplace_hint(const_iterator hint, Args&&... args) {
            //TODO(BlackMat): implme
            return insert(value_type(std::forward<Args>(args)...));
        }

        void clear() noexcept {
            data_.clear();
        }

        iterator erase(const_iterator iter) {
            //TODO(BlackMat): implme
            return end();
        }

        iterator erase(const_iterator first, const_iterator last) {
            //TODO(BlackMat): implme
            return end();
        }

        iterator erase(const key_type& key) {
            //TODO(BlackMat): implme
            return end();
        }

        void swap(flat_map& other) {
            //TODO(BlackMat): implme
        }

        size_type count(const key_type& key) const {
            const auto iter = find(key);
            return iter != end() ? 1 : 0;
        }

        iterator find(const key_type& key) {
            //TODO(BlackMat): implme
            return end();
        }

        const_iterator find(const key_type& key) const {
            //TODO(BlackMat): implme
            return end();
        }

        std::pair<iterator, iterator> equal_range(const key_type& key) {
            //TODO(BlackMat): implme
            return {end(), end()};
        }

        std::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
            //TODO(BlackMat): implme
            return {end(), end()};
        }

        iterator lower_bound(const key_type& key) {
            //TODO(BlackMat): implme
            return end();
        }

        const_iterator lower_bound(const key_type& key) const {
            //TODO(BlackMat): implme
            return end();
        }

        iterator upper_bound(const key_type& key) {
            //TODO(BlackMat): implme
            return end();
        }

        const_iterator upper_bound(const key_type& key) const {
            //TODO(BlackMat): implme
            return end();
        }

        key_compare key_comp() const {
            return compare_;
        }

        value_compare value_comp() const {
            return value_compare(compare_);
        }
    private:
        data_type data_;
        key_compare compare_;
    };

    template < typename Key
             , typename Value
             , typename Compare
             , typename Allocator >
    void swap(
        flat_map<Key, Value, Compare, Allocator>& l,
        flat_map<Key, Value, Compare, Allocator>& r)
    {
        l.swap(r);
    }
}
