#include <iostream>

using namespace std;

class Square {
public:
    Square(double a) : a(a) {}
private:
    double a;
};

class Rectangle : public Square {
public:
    Rectangle(double a, double b) : Square(a), b(b) {}

private:
    double b;
};

int main() {
    Rectangle* r = new Square(10;)
}