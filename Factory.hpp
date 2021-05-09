#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <iostream>
#include <string>
#include <vector>
#include "base.hpp"
#include "op.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Pow.hpp"

class Factory {
	private:
		bool InputCheck(std::string exp, int length) {
			if(length != 2)
				return 0;
			int expSize = exp.size();
			if((isdigit(exp.at(0)) == 0) || isdigit(exp.at(expSize-1)) == 0)
				return 0;
			for(unsigned i = 0; i < expSize-1; i++) {
				char cur = exp.at(i);
				char next = exp.at(i+1);
				if((isdigit(cur) == 0) && (cur != '+') && (cur != '-') && (cur != '*') && (cur != '/')) {
					return 0;
				}
				if((cur == '+') || (cur == '/') || (cur == '-')) {
					if(isdigit(next) == 0)
						return 0;
				}
				if(cur == '*') {
					if((isdigit(next) == 0) && (next != '*'))
						return 0;
					if(next == '*') {
						if(exp.at(i+2) == '*')
							return 0;
					}
				} 
			}
			return 1;	
		}

	public:
		Base* parse(char** input, int length) {
			std::string exp = input[1];
			if (InputCheck(exp, length) == 0) {
				return nullptr;
			}

			std::vector<Base*> operands(0);
			std::vector<char> operations(0);
			
			//Fill the vectors	
			for(unsigned i = 0; i < exp.size(); i++) {
				unsigned j = i;
				int num = 0;
				while(isdigit(exp.at(j)) != 0) {
					num *= 10;
					num += exp.at(j) - 48;
					if (j == exp.size() - 1) {
						break;
					}	
					j++;
				}
				if (num != 0) {
					Op* temp = new Op(num);
					operands.push_back(temp);
					i = j; 
				}
				//Must be an operation
				if(isdigit(exp.at(i)) == 0) {
					if (exp.at(i+1) == '*') {
						operations.push_back('^');
						i += 1;
					}
					else {
						operations.push_back(exp.at(i));
					}
				}
			}
			unsigned i = 0;			
			for (unsigned j = 0; j < operations.size(); j++) {
				if (operations.at(j) == '+') {
					Add* temp = new Add(operands.at(i), operands.at(i+1));
					i += 1;
					operands.at(i) = temp;
				}

				else if (operations.at(j) == '-') {
					Sub* temp = new Sub(operands.at(i), operands.at(i+1));
					i += 1;
					operands.at(i) = temp;
                                }

				else if (operations.at(j) == '*') {
					Mult* temp = new Mult(operands.at(i), operands.at(i+1));
					i += 1;
					operands.at(i) = temp;
                                }

				else if (operations.at(j) == '/') {
					Div* temp = new Div(operands.at(i), operands.at(i+1));
					i += 1;
					operands.at(i) = temp;
                                }

				else if (operations.at(j) == '^') {
					Pow* temp = new Pow(operands.at(i), operands.at(i+1));
					i += 1;
					operands.at(i) = temp;
                                }
			
			}
			return operands.at(operands.size() - 1);
		}
};

#endif
