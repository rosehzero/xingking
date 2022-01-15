//�����������

#include <iostream>
#include <memory>
using namespace std;


// unique_ptr, shared_ptr, weak_prt


class Test {
public:
	Test(int x) : x(x) { cout << "������" << endl; }
	~Test() { cout << "�Ҹ���" << endl; }
	int GetX() const { return x; }
private:
	int x;
};

int main() {
	shared_ptr<Test> a(new Test(5));
	{
		shared_ptr<Test> b = a;
		cout << a.use_count() << endl;
		cout << b.use_count() << endl;
	}
	cout << a.use_count() << endl;
}