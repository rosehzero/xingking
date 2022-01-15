//ÇÔ¼ö°´Ã¼

#include <iostream>

using namespace std;

class Equals {
public:
	Equals(int value) : value(value) {}
	bool operator()(int x) const {
		return x == value;
	}

private:
	int value;
};


int main() {
	Equals eq(123), eq2(234);

	cout << eq(123) << endl;
	cout << eq2(234) << endl;
}