/* Block Comment Header
Name George Couch and Brett Smitch
Date 09/26/2021
Our smart pointer assignment that teaches the user about smart pointers! We didn't feel the need to comment things out due to the fact the cout describes most
of everything immediately above the code
*/
#include <string>
#include <iostream>
#include <memory>
using namespace std;

class Circle
{
private:
	double radius;

public:
	Circle(double r)
	{
		radius = r;
		cout << "Constructed Ptr" << endl;
	}

	~Circle()
	{
		cout << "Destructed Ptr" << endl;
	}
	
	void getArea()
	{
		cout << "Using passed parameter to calculate the area." << endl;
		double area = pow((3.14 * radius), 2);
		cout << area << endl;
	}
};

void unqPtrScope()
{
	cout << "It's best to use a unique pointer when you only want 1 pointer\n" << endl;
	system("pause");
	unique_ptr<Circle> unqPtr1(new Circle(6));
	unqPtr1->getArea();
	cout << "Normally this would be all that you would want to do with a unique pointer, but there is also the move function." << endl;
	system("pause");
	unique_ptr<Circle> unqPtr2;
	unqPtr2 = move(unqPtr1);
	cout << "Below is another pointer to the same address as the first pointer." << endl;
	unqPtr2->getArea();
}

void sharedPtrScope()
{
	cout << "It's best to use a shared pointer when you need multiple pointers.\n" << endl;
	system("pause");
	cout << "\n";
	shared_ptr<Circle> shrdPtr1(new Circle(5));
	shrdPtr1->getArea();
	cout << "\n";
	system("pause");
	cout << "\nAnd a second pointer..." << endl;
	shared_ptr<Circle> shrdPtr2;
	shrdPtr2 = shrdPtr1;
	shrdPtr2->getArea();
	cout << "\n";
	system("pause");
	cout << "\nOne of the big differences between shared pointers and unique pointers is that you don't have to use \nthe move function to make another pointer." << endl;
	cout << "With shared pointers you can also see how many pointers are using an \naddress by using the use_count function from any pointer.\n" << endl;
	system("pause");
	cout << "First pointer." << endl;
	int ptrNum1 = shrdPtr1.use_count();
	cout << ptrNum1 << endl;
	cout << "\n";
	cout << "Second pointer" << endl;
	int ptrNum2 = shrdPtr2.use_count();
	cout << ptrNum1 << endl;
}

void weakPtrScope()
{
	cout << "It's best to use a weak pointer when you need to have multiple pointers, but you don't want \nto keep track of how many are accessing the memory address.\n" << endl;
	system("pause");
	cout << "\n";
	cout << "Here I'll create a shared pointer and a weak pointer immediately after." << endl;
	shared_ptr<Circle> shrdPtr(new Circle(8));
	shrdPtr->getArea();
	weak_ptr<Circle> wkPtr1;
	wkPtr1 = shrdPtr;
	cout << "\n";
	system("pause");
	cout << "\nWe can't create a pointer object using weak pointers, so we just set the address equal to that of the shared ptr." << endl;
	cout << "Here you can see that when using use_count from either pointer, only 1 is found." << endl;
	cout << "\nShared" << endl;
	int ptrNum = shrdPtr.use_count();
	cout << ptrNum << endl;
	cout << "\nWeak" << endl;
	int ptrNum2 = wkPtr1.use_count();
	cout << ptrNum2 << endl;
	cout << "\n";
	system("pause");
	cout << "\nBecause I created a shared ptr within this scope, we didn't need to use the lock \nfunction which locks the pointer in place so that a shared pointer can be created to access it." << endl;
}

int main()
{
	cout << "\tSmart pointers are pointers that delete themselves from memory when they fall out of scope." << endl;
	cout << "\tIn the upcoming examples, each pointer is created within it's own function." << endl;
	cout << "\tThis is so that the pointers will run their constructors and destructors after you make each choice.\n" << endl;
	string contChoosing = "y";
	while (contChoosing == "y")
	{
		cout << "Which pointer would you like to learn about?" << endl;
		cout << " unique_ptr | shared_ptr | weak_ptr (1/2/3)" << endl;
		int ptrChoice;
		cin >> ptrChoice;
		switch (ptrChoice)
		{
		case 1:
			cout << "\nInfo about unique_ptr...\n" << endl;
			unqPtrScope();
			break;
		case 2:
			cout << "\nInfo about shared_ptr...\n" << endl;
			sharedPtrScope();
			break;
		case 3:
			cout << "\nInfo about weak_ptr...\n" << endl;
			weakPtrScope();
			break;
		default:
			break;
		}
		cout << "\nWould you like to continue learning? (y/n)" << endl;
		getline(cin >> ws, contChoosing);
	}
}