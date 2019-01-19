#pragma once

namespace Utils {
	template<typename T>
	void Swap(T& x, T& y) {
		T tmp = x;
		x = y;
		y = tmp;
	}

	template<typename T>
	struct Tuple {
		T first;
		T second;
		
		Tuple(T first, T second) : first(first), second(second) {}
	};
}