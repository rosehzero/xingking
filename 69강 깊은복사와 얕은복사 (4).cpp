#include <iostream>

using namespace std;

class String {
public:
	String() {
		cout << "String() : " << this << endl;
		strData = NULL;
		len = 0;
	}
	String(const char* str) {
		cout << "String(const char*) : " << this << endl;
		len = strlen(str);
		alloc(len);
		strcpy(strData, str);
	}

	//복사 생성자
	String(const String& rhs) {
		cout << "String(const String&) : " << this << endl;
		len = rhs.len;
		alloc(len);
		strcpy(strData, rhs.strData);
	}

	//이동생성자
	String(String&& rhs) {
		cout << "String(String&&) : " << this << endl;
		len = rhs.len;
		strData = rhs.strData;

		rhs.strData = NULL;
	}

	~String() {
		cout << "~String() : " << this << endl;
		release();
		strData = NULL;
	}


	// 복사 대입 연산자
	String& operator=(const String& rhs) {
		cout << "String &operator=(const String&) : " << this << endl;
		if (this != &rhs) {
			release();
			len = rhs.len;
			alloc(len);
			strcpy(strData, rhs.strData);
		}
		return *this;
	}

	//이동 대입 연산자 
	String& operator=(String&& rhs) {
		cout << "String &operator=(String&&) : " << this << endl;
		len = rhs.len;
		strData = rhs.strData;

		rhs.strData = NULL;
		return *this;

	}


	char* GetStrData() const {
		return strData;
	}
	int GetLen() const {
		return len;
	}
	void SetStrData(const char* str) {
		cout << "void SetStrData(const char*) : " << this << ", " << str << endl;
		len = strlen(str);
		alloc(len);
		strcpy(strData, str);
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

int f() { return 5; }


int main() {
	String a;
	cout << "===== 1 =====" << endl;
	a = getName();
	cout << "===== 4 =====" << endl;


	String&& r = getName();

	// 임시객체는 r - value !! 
}