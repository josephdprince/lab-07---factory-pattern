#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <sstream>
#include <iomanip>

class Op : public Base {
    private:
	double value;   
    public:
        Op(double value) : Base() { this->value = value; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() {
		std::ostringstream out;
		out << std::setprecision(6) << value;
		return out.str();
	}
}; 

#endif //__OP_HPP__
