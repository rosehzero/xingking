//함수포인터 > 함수객체 변환

#include <iostream>
#include <functional>

using namespace std;

class Square {
public:
	int operator()(int n) { return n * n; }
} square;

class MyFunc {
public:
	int operator()(int n) { return n * (n - 15) / 2; }
} myFunc;



template<typename T>
int arrFnMin(const int arr[], int n, T f) {
	int min = f(arr[0]);
	for (int i = 1; i < n; i++) {
		if (f(arr[i]) < min) {
			min = f(arr[i]);
		}
	}
	return min;
}



int main() {
	int arr[7] = { 3, 1, -4, 1, 5, 9, -2 };
	cout << arrFnMin<Square>(arr, 7, square) << endl;
	cout << arrFnMin<MyFunc>(arr, 7, myFunc) << endl;
}