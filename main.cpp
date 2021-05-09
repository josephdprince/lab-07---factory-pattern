#include <iostream>
using namespace std;

#include "Factory.hpp"

int main(int argc, char** argv) {
	
	Factory obj;
	Base* tree = obj.parse(argv, argc);
	if (tree == nullptr) {
		cout << "Error: Undefined Input" << endl;
	}
	else { 
		cout << tree->stringify() << " = " << tree->evaluate() << endl;
	}

return 0;
}
