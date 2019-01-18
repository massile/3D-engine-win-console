
namespace Utils {
	template<typename T>
	void Swap(T& x, T& y) {
		T tmp = x;
		x = y;
		y = tmp;
	}
}