#include <iostream>

using namespace std;

bool compare(int a, int b) {
	return a == b;
}

int main() {
	bool(*fp)(int, int) = compare;

	bool res = fp(2, 3); // (*fp) »ý·« 


	cout << res << endl;
}