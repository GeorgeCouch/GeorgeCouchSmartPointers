#include <string>
#include <iostream>
#include <memory>
using namespace std;

class Entity
{
public:
	Entity()
	{
		cout << "Created Entity!" << endl;
	}

	~Entity()
	{
		cout << "Destroyed Entity!" << endl;
	}

	void Print() {}
};

int main()
{
	string contChoosing = "y";
	while (contChoosing == "y")
	{
		cout << "Which pointer would you like to learn about?" << endl;
		cout << "shared_ptr | weak_ptr | unique_ptr (1/2/3)" << endl;
		int ptrChoice;
		cin >> ptrChoice;
		switch (ptrChoice)
		{
		case 1:
			cout << "Info about shared_ptr" << endl;
			break;
		case 2:
			cout << "Info about weak_ptr" << endl;
			break;
		case 3:
			cout << "Info about weak_ptr" << endl;
			break;
		default:
			break;
		}
		cout << "Would you like to continue learning? (y/n)" << endl;
		getline(cin >> ws, contChoosing);
	}

	// Constructs, runs print, and then destructs
	// Destructor is called when unique_ptr goes out of scope
	// This is essentially an object with good memory allocation
	unique_ptr<Entity> entity = make_unique<Entity>();
	entity->Print();
}