#include <iostream>

using namespace std;



struct IPerson {
	virtual ~IPerson() {}
	virtual void Eat() = 0;
	virtual int GetAge() = 0;
};

struct IStudent : virtual IPerson {
	virtual void Study() = 0;
};
struct Student : IStudent {
	void Eat() {
		cout << "냠냠..." << endl;
	}

	void Study() {
		cout << "공부한다..." << endl;
	}
	int GetAge() { return age; }
	int age;
};

struct IWorker : virtual IPerson {
	virtual void Work() = 0;
};
struct Worker : IWorker {
	void Work() {
		cout << "일한다..." << endl;
	}

	void Study() {
		cout << "공부한다..." << endl;
	}
};

struct Researcher : IStudent, IWorker {
	void Eat() {
		cout << "먹는다..." << endl;
	}
	void Study() {
		cout << "공부한다..." << endl;
	}
	void Work() {
		cout << "일한다..." << endl;
	}
	int GetAge() { return age; }
	int age;
};

int main() {
	IPerson* p = new Researcher;
	p->GetAge();

	delete p;

	p = new Student;
	p->GetAge();

	delete p;

	Student s;
	s.Study();
	Researcher r;
	r.Study();
	r.Work();



}