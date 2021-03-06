# flat.hpp

[![travis][badge.travis]][travis]
[![appveyor][badge.appveyor]][appveyor]
[![codecov][badge.codecov]][codecov]
[![language][badge.language]][language]
[![license][badge.license]][license]
[![paypal][badge.paypal]][paypal]

[badge.travis]: https://img.shields.io/travis/BlackMATov/flat.hpp/master.svg?logo=travis
[badge.appveyor]: https://img.shields.io/appveyor/ci/BlackMATov/flat-hpp/master.svg?logo=appveyor
[badge.codecov]: https://img.shields.io/codecov/c/github/BlackMATov/flat.hpp/master.svg?logo=codecov
[badge.language]: https://img.shields.io/badge/language-C%2B%2B14-red.svg
[badge.license]: https://img.shields.io/badge/license-MIT-blue.svg
[badge.paypal]: https://img.shields.io/badge/donate-PayPal-orange.svg?logo=paypal&colorA=00457C

[travis]: https://travis-ci.org/BlackMATov/flat.hpp
[appveyor]: https://ci.appveyor.com/project/BlackMATov/flat-hpp
[codecov]: https://codecov.io/gh/BlackMATov/flat.hpp
[language]: https://en.wikipedia.org/wiki/C%2B%2B14
[license]: https://en.wikipedia.org/wiki/MIT_License
[paypal]: https://www.paypal.me/matov

[flat]: https://github.com/BlackMATov/flat.hpp

## Installation

[flat.hpp][flat] is a header only library. All you need to do is copy the header files (`flat_set.hpp` and `flat_map.hpp`) into your project and include them.

## API
- [Flat Set](#flat-set)
- [Flat Map](#flat-map)
- [Flat Multiset](#flat-multiset)
- [Flat Multimap](#flat-multimap)

## Flat Set

```cpp
template < typename Key
         , typename Compare = std::less<Key>
         , typename Allocator = std::allocator<Key>
         , typename Container = std::vector<Key, Allocator> >
class flat_set;
```

### Member types

| Member type              | Definition                          |
|--------------------------|-------------------------------------|
| `key_type`               | `Key`                               |
| `value_type`             | `Key`                               |
| `size_type`              | `Container::size_type`              |
| `difference_type`        | `Container::difference_type`        |
| `key_compare`            | `Compare`                           |
| `value_compare`          | `Compare`                           |
| `allocator_type`         | `Allocator`                         |
| `container_type`         | `Container`                         |
| `reference`              | `Container::reference`              |
| `const_reference`        | `Container::const_reference`        |
| `pointer`                | `Container::pointer`                |
| `const_pointer`          | `Container::const_pointer`          |
| `iterator`               | `Container::iterator`               |
| `const_iterator`         | `Container::const_iterator`         |
| `reverse_iterator`       | `Container::reverse_iterator`       |
| `const_reverse_iterator` | `Container::const_reverse_iterator` |

### Member functions

```cpp
explicit flat_set(
    const Allocator& a);

explicit flat_set(
    const Compare& c = Compare(),
    const Allocator& a = Allocator());

template < typename InputIter >
flat_set(
    InputIter first,
    InputIter last,
    const Allocator& a);

template < typename InputIter >
flat_set(
    InputIter first,
    InputIter last,
    const Compare& c = Compare(),
    const Allocator& a = Allocator());

flat_set(
    std::initializer_list<value_type> ilist,
    const Allocator& a);

flat_set(
    std::initializer_list<value_type> ilist,
    const Compare& c = Compare(),
    const Allocator& a = Allocator());

flat_set(flat_set&& other);
flat_set(const flat_set& other)

flat_set& operator=(flat_set&& other);
flat_set& operator=(const flat_set& other);
flat_set& operator=(std::initializer_list<value_type> ilist);

allocator_type get_allocator() const;
```

### Iterators

```cpp
iterator begin() noexcept;
const_iterator begin() const noexcept;
const_iterator cbegin() const noexcept;

iterator end() noexcept;
const_iterator end() const noexcept;
const_iterator cend() const noexcept;

reverse_iterator rbegin() noexcept;
const_reverse_iterator rbegin() const noexcept;
const_reverse_iterator crbegin() const noexcept;

reverse_iterator rend() noexcept;
const_reverse_iterator rend() const noexcept;
const_reverse_iterator crend() const noexcept;
```

### Capacity

```cpp
bool empty() const noexcept;
size_type size() const noexcept;
size_type max_size() const noexcept;
size_type capacity() const noexcept;
void reserve(size_type ncapacity);
void shrink_to_fit();
```

### Modifiers

```cpp
std::pair<iterator, bool> insert(value_type&& value);
std::pair<iterator, bool> insert(const value_type& value);

iterator insert(const_iterator hint, value_type&& value);
iterator insert(const_iterator hint, const value_type& value);

template < typename InputIter >
void insert(InputIter first, InputIter last);
void insert(std::initializer_list<value_type> ilist);

template < typename... Args >
std::pair<iterator, bool> emplace(Args&&... args);
template < typename... Args >
iterator emplace_hint(const_iterator hint, Args&&... args);

void clear() noexcept;
iterator erase(const_iterator iter);
iterator erase(const_iterator first, const_iterator last);
size_type erase(const key_type& key);

void swap(flat_set& other);
```

### Lookup

```cpp
size_type count(const key_type& key) const;

iterator find(const key_type& key);
const_iterator find(const key_type& key) const;

std::pair<iterator, iterator> equal_range(const key_type& key);
std::pair<const_iterator, const_iterator> equal_range(const key_type& key) const;

iterator lower_bound(const key_type& key);
const_iterator lower_bound(const key_type& key) const;

iterator upper_bound(const key_type& key);
const_iterator upper_bound(const key_type& key) const;
```

### Observers

```cpp
key_compare key_comp() const;
value_compare value_comp() const;
```

### Non-member functions

```cpp
template < typename K, typename C, typename A >
void swap(
    flat_set<K, C, A>& l,
    flat_set<K, C, A>& r);

template < typename K, typename C, typename A >
bool operator==(
    const flat_set<K, C, A>& l,
    const flat_set<K, C, A>& r);

template < typename K, typename C, typename A >
bool operator!=(
    const flat_set<K, C, A>& l,
    const flat_set<K, C, A>& r);

template < typename K, typename C, typename A >
bool operator<(
    const flat_set<K, C, A>& l,
    const flat_set<K, C, A>& r);

template < typename K, typename C, typename A >
bool operator>(
    const flat_set<K, C, A>& l,
    const flat_set<K, C, A>& r);

template < typename K, typename C, typename A >
bool operator<=(
    const flat_set<K, C, A>& l,
    const flat_set<K, C, A>& r);

template < typename K, typename C, typename A >
bool operator>=(
    const flat_set<K, C, A>& l,
    const flat_set<K, C, A>& r);
```

## Flat Map

```cpp
template < typename Key
         , typename Value
         , typename Compare = std::less<Key>
         , typename Allocator = std::allocator<std::pair<Key, Value>>
         , typename Container = std::vector<std::pair<Key, Value>, Allocator> >
class flat_map;
```

### Member types

| Member type              | Definition                          |
|--------------------------|-------------------------------------|
| `key_type`               | `Key`                               |
| `mapped_type`            | `Value`                             |
| `value_type`             | `Container::value_type`             |
| `size_type`              | `Container::size_type`              |
| `difference_type`        | `Container::difference_type`        |
| `key_compare`            | `Compare`                           |
| `allocator_type`         | `Allocator`                         |
| `container_type`         | `Container`                         |
| `reference`              | `Container::reference`              |
| `const_reference`        | `Container::const_reference`        |
| `pointer`                | `Container::pointer`                |
| `const_pointer`          | `Container::const_pointer`          |
| `iterator`               | `Container::iterator`               |
| `const_iterator`         | `Container::const_iterator`         |
| `reverse_iterator`       | `Container::reverse_iterator`       |
| `const_reverse_iterator` | `Container::const_reverse_iterator` |

### Member classes

```cpp
class value_compare;
```

### Member functions

```cpp
explicit flat_map(
    const Allocator& a);

explicit flat_map(
    const Compare& c = Compare(),
    const Allocator& a = Allocator());

template < typename InputIter >
flat_map(
    InputIter first,
    InputIter last,
    const Allocator& a);

template < typename InputIter >
flat_map(
    InputIter first,
    InputIter last,
    const Compare& c = Compare(),
    const Allocator& a = Allocator());

flat_map(
    std::initializer_list<value_type> ilist,
    const Allocator& a);

flat_map(
    std::initializer_list<value_type> ilist,
    const Compare& c = Compare(),
    const Allocator& a = Allocator());

flat_map(flat_map&& other);
flat_map(const flat_map& other);

flat_map& operator=(flat_map&& other);
flat_map& operator=(const flat_map& other);
flat_map& operator=(std::initializer_list<value_type> ilist);

allocator_type get_allocator() const;
```

### Iterators

```cpp
iterator begin() noexcept;
const_iterator begin() const noexcept;
const_iterator cbegin() const noexcept;

iterator end() noexcept;
const_iterator end() const noexcept;
const_iterator cend() const noexcept;

reverse_iterator rbegin() noexcept;
const_reverse_iterator rbegin() const noexcept;
const_reverse_iterator crbegin() const noexcept;

reverse_iterator rend() noexcept;
const_reverse_iterator rend() const noexcept;
const_reverse_iterator crend() const noexcept;
```

### Capacity

```cpp
bool empty() const noexcept;
size_type size() const noexcept;
size_type max_size() const noexcept;
size_type capacity() const noexcept;
void reserve(size_type ncapacity);
void shrink_to_fit();
```

### Element access

```cpp
mapped_type& operator[](key_type&& key);
mapped_type& operator[](const key_type& key);

mapped_type& at(const key_type& key);
const mapped_type& at(const key_type& key) const;
```

### Modifiers

```cpp
std::pair<iterator, bool> insert(value_type&& value);
std::pair<iterator, bool> insert(const value_type& value);

iterator insert(const_iterator hint, value_type&& value);
iterator insert(const_iterator hint, const value_type& value);

template < typename InputIter >
void insert(InputIter first, InputIter last);
void insert(std::initializer_list<value_type> ilist);

template < typename... Args >
std::pair<iterator, bool> emplace(Args&&... args);
template < typename... Args >
iterator emplace_hint(const_iterator hint, Args&&... args);

void clear() noexcept;
iterator erase(const_iterator iter);
iterator erase(const_iterator first, const_iterator last);
size_type erase(const key_type& key);

void swap(flat_map& other)
```

### Lookup

```cpp
size_type count(const key_type& key) const;

iterator find(const key_type& key);
const_iterator find(const key_type& key) const;

std::pair<iterator, iterator> equal_range(const key_type& key);
std::pair<const_iterator, const_iterator> equal_range(const key_type& key) const;

iterator lower_bound(const key_type& key);
const_iterator lower_bound(const key_type& key) const;

iterator upper_bound(const key_type& key);
const_iterator upper_bound(const key_type& key) const;
```

### Observers

```cpp
key_compare key_comp() const;
value_compare value_comp() const;
```

### Non-member functions

```cpp
template < typename K, typename V, typename C, typename A >
void swap(
    flat_map<K, V, C, A>& l,
    flat_map<K, V, C, A>& r);

template < typename K, typename V, typename C, typename A >
bool operator==(
    const flat_map<K, V, C, A>& l,
    const flat_map<K, V, C, A>& r);

template < typename K, typename V, typename C, typename A >
bool operator!=(
    const flat_map<K, V, C, A>& l,
    const flat_map<K, V, C, A>& r);

template < typename K, typename V, typename C, typename A >
bool operator<(
    const flat_map<K, V, C, A>& l,
    const flat_map<K, V, C, A>& r);

template < typename K, typename V, typename C, typename A >
bool operator>(
    const flat_map<K, V, C, A>& l,
    const flat_map<K, V, C, A>& r);

template < typename K, typename V, typename C, typename A >
bool operator<=(
    const flat_map<K, V, C, A>& l,
    const flat_map<K, V, C, A>& r);

template < typename K, typename V, typename C, typename A >
bool operator>=(
    const flat_map<K, V, C, A>& l,
    const flat_map<K, V, C, A>& r);
```

## Flat Multiset

> coming soon!

## Flat Multimap

> coming soon!

## [License (MIT)](./LICENSE.md)
