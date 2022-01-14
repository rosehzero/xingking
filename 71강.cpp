#include <iostream>
#include <string>
using namespace std;

int fact(int n) {
	if (n < 0) throw to_string(n) + ": 음수입니다.";
	if (n == 0) return 1;
	return n * fact(n - 1);
}

int comb(int n, int r) {
	int a = fact(n);
	int b = fact(r);
	int c = fact(n - r);
	return a / b / c;
}

int main() {
	int n, r;

	try {
		throw 12.3;
	}
	catch (const string& e) {
		cout << e << endl;
	}
	catch (int e) {
		cout << e << endl;
	}
	catch (...) {
		cout << "알 수 없는 예외 발생" << endl;
	}
}