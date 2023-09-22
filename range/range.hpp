// SPDX-License-Identifier: MIT
// A corresponding LICENSE.txt file is located in the root directory of this source tree 
// Copyright (C) 2023 Alexander Vieth 

#ifndef UTIL_RANGE_HPP
#define UTIL_RANGE_HPP

#include <type_traits>
#include <iterator>
#include <cstddef>

namespace utils {

    template <typename T>
    struct range {
        static_assert(std::is_integral<T>::value, "Integral type required.");

        // see https://en.cppreference.com/w/cpp/iterator/iterator_traits
        struct range_iter
        {
            using iterator_category = std::forward_iterator_tag;    // c++17 style, c++20 would use std::forward_iterator
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using pointer = value_type*;
            using reference = value_type&;

            range_iter() : _val(0) {}
            range_iter(value_type val) : _val(val) {}

            reference operator*() { return _val; }
            pointer operator->() { return &_val; }

            range_iter& operator++() { _val++; return *this; }                                // prefix increment
            range_iter  operator++(int) { range_iter tmp = *this; ++(*this); return tmp; }    // postfix increment

            friend bool operator== (const range_iter& a, const range_iter& b) { return a._val == b._val; };
            friend bool operator!= (const range_iter& a, const range_iter& b) { return a._val != b._val; };

        private:
            value_type _val;
        };

        range(T end) : _begin(0), _end(end) { }
        // if end < begin, don't throw an exception but instead don't iterate at all
        range(T begin, T end) : _begin(begin), _end(end) { if (end < begin) _end = _begin; }

        range_iter begin() { return _begin; }
        range_iter end() { return _end; }

        const char* typeinfo() const { return typeid(T).name(); }

    private:
        range_iter _begin;
        range_iter _end;
    };

}

#endif
