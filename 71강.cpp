#include <iostream>

using namespace std;

template<typename T>
class Vector2 {
public:
	Vector2() : x(0), y(0) {}
	Vector2(T x, T y) : x(x), y(y) {}
	T GetX() const { return x; }
	T GetY() const { return y; }
	Vector2 operator+(const Vector2<T>& rhs) const {
		return Vector2(x + rhs.x, y + rhs.y);
	}
	Vector2 operator-(const Vector2& rhs) const {
		return Vector2(x - rhs.x, y - rhs.y);
	}

	Vector2& operator+=(const Vector2& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	Vector2 operator-=(const Vector2& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

private:
	T x, y;
};

int main() {
	Vector2<float> v1(2, 3);
	Vector2<float> v2(4, 5);
	Vector2<float> v3 = v1 + v2;

}
