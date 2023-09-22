# Python-like range in C++17
Motivated by [cpp11-range](https://github.com/klmr/cpp11-range), this header-only C++ iterator template acts like Python's range functions.
cpp17-range can be used with std::execution, e.g. in std::for_each, unlike cpp11-range which does not define a forward_iterator but only a input_iterator.  

Examples (see the [full code](./example/main.cpp)), :
```cpp
// print the numbers from 0 up to and including 9 in non-sequential order
size_t n = 10;
auto range = utils::range(n);
std::for_each(std::execution::par, range.begin(), range.end(), [&](const auto i) {
    std::cout << i << "\n";
});

// print the numbers from 2 up to and including 7 in sequential order and ask for range type info
for(const auto num : utils::range(2, 8))
    std::cout << num << " ";
std::cout << range.typeinfo() <<  "\n";

```

With C++20 you might use the [ranges](https://en.cppreference.com/w/cpp/ranges) library, if you do not need to specify an execution policy:
```cpp
std::ranges::for_each(std::views::iota(0, 10), [](const auto i){
    std::cout << i << "\n";
});
```

## Performance
Both these snippets compile to the same code, check it out [with compiler explorer](https://godbolt.org/z/nMY79eEhb):
```cpp
auto range = utils::range(10);
for(const auto& num : range)
    std::cout << num << " ";

for (int i = 0; i < 10; ++i)
    std::cout << i << " ";
```

## Miscellaneous

Other resources: 
- https://github.com/VinGarcia/Simple-Iterator-Template
- https://isocpp.org/blog/2020/12/writing-a-custom-iterator-in-modern-cpp