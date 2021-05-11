#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
    private:
	Base* val1;
	Base* val2;
    public:
	Sub(Base* val1, Base* val2) : Base() {
		this->val1 = val1;
		this->val2 = val2;
	}

	virtual ~Sub() {
	        delete val1;
	   	delete val2;
	}

	virtual double evaluate() { return val1->evaluate() - val2->evaluate(); }
	virtual std::string stringify() { return "(" + val1->stringify() + "-" + val2->stringify() + ")"; }
};

#endif
