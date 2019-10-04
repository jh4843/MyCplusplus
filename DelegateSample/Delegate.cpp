#include <iostream>

using namespace std;

class Animal;

class AnimalDelegate {
public:
	virtual void onSound(Animal* pSender) = 0;
	virtual void onWalk(Animal* pSender) = 0;
};

class Animal {
private:
	AnimalDelegate* delegate;

public:

	Animal() {
		this->delegate = NULL;
	}

	void setDelegate(AnimalDelegate* delegate) {
		this->delegate = delegate;
	}

	void sound() {
		if (this->delegate) {
			this->delegate->onSound(this);
		}
	}

	void walk() {
		if (this->delegate) {
			this->delegate->onWalk(this);
		}
	}
};



//�� : Delegate�� ���ο� ���� ����
class Dog :public Animal, public AnimalDelegate {
public:
	Dog() {
		this->setDelegate(this);
	}

	void onSound(Animal* pSender) {
		cout << "Dog: �۸�!" << endl;
	}

	void onWalk(Animal* pSender) {
		cout << "Dog: ���� �ȴ´�" << endl;
	}
};

//����� Delegate
class CatDelegate :public AnimalDelegate {
public:
	void onSound(Animal* pSender) {
		cout << "Cat: �߿�~" << endl;
	}

	void onWalk(Animal* pSender) {
		cout << "Cat: ����̰� �ȴ´�" << endl;
	}
};

//�����
class Cat :public Animal {};


void main() {

	Dog dog;
	Cat cat;

	dog.sound();
	dog.walk();

	CatDelegate cdel;

	cat.setDelegate(&cdel);
	cat.sound();
	cat.walk();

	getchar();
}

