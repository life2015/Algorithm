#include<iostream>

using namespace std;

class Count {
    static int count;
public:
    Count() { count++; }

    static int getCount() { return count; }

    ~Count() {
        count--;
    }

};

int Count::count = 1;

class Animal {
public:
    virtual void speak() = 0;
};

class Bird : public Animal {
public:
    void speak() override { cout << "I‘m a bird." << endl; }
};

class Duck : public Bird {
public:
    void speak() override { cout << "quack quack quack" << endl; }
};

int main() {
    Count c1, c2;
    cout << Count::getCount() << endl;
    {
        Count c[3];
        cout << Count::getCount() << endl;
    }
    cout << Count::getCount() << endl;

//    Animal animals[] = {Bird(), Duck()};
    Bird birds[] = {Bird(), Duck()};
    Animal *pAnimals[] = {new Bird, new Duck};
    pAnimals[0]->speak(); //所以说这个货多态必须要用指针，用普通对象是不行的
    pAnimals[1]->speak();
    birds[1].speak();

//    const int& r1 = value1; value1 = 3; cout << value1 << "," << r1 << endl;

}
