#include <iostream>
using namespace std;

#include "Factory.hpp"

int main(int argc, char** argv) {
	
	Factory obj;
	Base* tree = obj.parse(argv, argc);
	if (tree == nullptr) {
		cout << "Error" << endl;
	}
	else { 
		cout << tree->evaluate() << endl;
		cout << tree->stringify() << endl;
	}

return 0;
}
