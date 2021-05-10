#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
	private:
		Base* val1;
		Base* val2;
	public:
		Div(Base* op1, Base* op2) : Base() {
			this->val1 = op1;
			this->val2 = op2;
		}

		virtual ~Div() {
			delete val1;
			delete val2;
		}	

		virtual double evaluate() {
			return val1->evaluate() / val2->evaluate();
		}
		virtual std::string stringify() {
			return "(" + val1->stringify() + "/" + val2->stringify() + ")";
		}
};

#endif
