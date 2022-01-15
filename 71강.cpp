// ��ũ������



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
	weak_ptr<Test> b;
	{
		shared_ptr<Test> a(new Test(5));
		b = a;
		cout << a.use_count() << endl;
		cout << b.use_count() << endl;
		if (!b.expired()) {
			cout << b.lock()->GetX() << endl;
		}
	}
	cout << b.use_count() << endl;
	if (!b.expired()) {
		cout << b.lock()->GetX() << endl;
	}


}