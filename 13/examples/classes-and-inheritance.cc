#include <iostream>
using namespace std;

#define NAME_SIZE 50

class Person {
	int id; // all members are private by default
	char name[NAME_SIZE];

	public: 
		virtual void aboutMe() {
			cout << "I am a person.";
		}
};

class Student : public Person {
	public:
		void aboutMe() {
			cout << "I am  a student.";
		}
};

int main() {
	Student *p = new Student();
	p->aboutMe(); // prints "I am a student"
	Person *p2 = new Student();
	p2->aboutMe();
	delete p; // Important! Make sure to delete allocated memory.
	return 0;
}
