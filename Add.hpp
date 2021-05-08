#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base {
    private:
	Base* value1;
	Base* value2;
    public:
	Add(Base* value1, Base* value2) : Base() {
		this->value1 = value1;
		this->value2 = value2;	
}
	
	virtual double evaluate() { return value1->evaluate() + value2->evaluate(); }
	virtual std::string stringify() { return "(" + value1->stringify() + "+" + value2->stringify() + ")"; }

};

#endif
