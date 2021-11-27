#include <iostream>

using namespace std;

class String {
public:
	String() {
		cout << "String() : " << this << endl;
		// ����
	}
	String(const char* str) {
		cout << "String(const char*) : " << this << endl;
		// ����
	}
	String(const String& rhs) {
		cout << "String(const String&) : " << this << endl;
		// ����
	}

	~String() {
		cout << "~String() : " << this << endl;
		// ����
	}

	String& operator=(const String& rhs) {
		cout << "String &operator=(const String&) : " << this << endl;
		// ����
		return *this;
	}

	char* GetStrData() const {
		return strData;
	}
	int GetLen() const {
		return len;
	}
	void SetStrData(const char* str) {
		// ����
	}

private:
	void alloc(int len) {
		strData = new char[len + 1];
		cout << "strData allocated : " << (void*)strData << endl;
	}
	void release() {
		delete[] strData;
		if (strData) cout << "strData released : " << (void*)strData << endl;
	}

	char* strData;
	int len;
};

String getName() {
	cout << "===== 2 =====" << endl;
	String res("Doodle");
	cout << "===== 3 =====" << endl;
	return res;
}

int main() {
	String a;
	cout << "===== 1 =====" << endl;
	a = getName();
	cout << "===== 4 =====" << endl;
}