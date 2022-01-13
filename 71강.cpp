#include <iostream>
#include <string>
using namespace std;

class Vector2 {
public:
	Vector2() : x(0), y(0) {}
	Vector2(float x, float y) : x(x), y(y) {}
	float GetX() const { return x; }
	float GetY() const { return y; }

	Vector2& operator+=(const Vector2& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

private:
	float x, y;
};

template<typename T>
T getArraySum(const T arr[], int n) {
	T sum = arr[0];
	for (int i = 1; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {
	int iarr[5] = { 3, 1, 4, 1, 5 };
	float farr[5] = { 3.1, 1.2, 4.3, 1.4, 5.5 };
	Vector2 varr[3] = { Vector2(1,2), Vector2(3,4), Vector2(5,6) };
	string sarr[3] = { "hello", "world", "doodle" };

	int isum = getArraySum(iarr, 5);
	float fsum = getArraySum<float>(farr, 5);
	Vector2 vsum = getArraySum<Vector2>(varr, 3);
	string ssum = getArraySum(sarr, 3);

	cout << isum << endl;
	cout << fsum << endl;

	cout << vsum.GetX() << "," << vsum.GetY() << endl;
	cout << ssum << endl;
}