#include <list>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

class Animal {
	public:
		Animal(string name) {
			this->name = name;
		}
		void setOrder(int ord) {
			order = ord;
		}
		int getOrder() {
			return order;
		}
		bool isOlderThan(Animal a) {
			return this->order < a.getOrder();
		}

		virtual void introduceSelf() = 0;
	private:
		int order;
	protected:
		string name;
};

class Dog : public Animal {
	public:
		Dog(string name) : Animal(name) {}
		void introduceSelf() {
			cout << "Hi my name is " << this->name << " and I am a dog." << endl;
		}
};

class Cat : public Animal {
	public:
		Cat(string name) : Animal(name) {}
		void introduceSelf() {
			cout << "Hi my name is " << this->name << " and I am a cat." << endl;
		}

};

class AnimalShelter {
	list<Dog> dogs;
	list<Cat> cats;
	int order = 0;

	public:
		void enqueue(Animal a);
		Animal dequeueAny();
		Dog dequeueDog();
		Cat dequeueCat();
};

void AnimalShelter::enqueue(Animal a) {
	try {
		Dog& d = dynamic_cast<Dog&>(a);
		d.setOrder(order);
		order += 1;
		dogs.push_back(d);
	} catch(bad_cast exp) {
		Cat& c = dynamic_cast<Cat&>(a);
		c.setOrder(order);
		order += 1;
		cats.push_back(c);
	}
}

Animal AnimalShelter::dequeueAny() {
	assert(dogs.size() != 0 || cats.size() != 0);
	if(dogs.size() == 0) {
		Dog d = dogs.front();
		dogs.pop_front();
		return d;
	} else if(cats.size() == 0) {
		Cat c = cats.front();
		cats.pop_front();
		return c;
	} else {
		Cat c = cats.front();
		Dog d = dogs.front();
		if(c.isOlderThan(d)) {
			cats.pop_front();
			return c;
		} else {
			dogs.pop_front();
			return d;
		}
	}
}

Dog AnimalShelter::dequeueDog() {
	assert(dogs.size() != 0);
	Dog d = dogs.front();
	dogs.pop_front();
	return d;
}

Cat AnimalShelter::dequeueCat() {
	assert(cats.size() != 0);
	Cat c = cats.front();
	cats.pop_front();
	return c;
}
