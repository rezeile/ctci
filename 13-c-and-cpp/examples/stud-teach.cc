#include <iostream>
#define NAME_SIZE 50
using namespace std;


class Person {
	int id;
	char name[NAME_SIZE];

	public:
		virtual void aboutMe() {
			cout << "I am a person." << endl;
		}
		virtual bool addCourse(string s) = 0;
};

class Student : public Person {
	public:
		void aboutMe() {
			cout << "I am a student." << endl;
		}

		bool addCourse(string s) {
			cout << "Added course " << s << "to student." << endl;
			return true;
		}
};

int main() {
	
}
