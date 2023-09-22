#include "range.hpp"

#include <execution>
#include <algorithm>
#include <iostream>

template<typename T>
void myFunction(T val) {
	std::cout << val << "\n";
}

int main()
{
	size_t n = 25;
	auto range = utils::range(n);
	std::for_each(std::execution::par, range.begin(), range.end(), [&](const auto i) {
		myFunction(i);
		});

	return 0;
}
