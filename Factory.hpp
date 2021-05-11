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
using namespace std;
class Factory {
	private:
		bool InputCheck(std::string exp, int length) {
			//get length of the string
			int expSize = exp.size();

			//checks if string starts with a digit or negative sign
			if((isdigit(exp.at(0)) == 0) && (exp.at(0) != '-')) {
				//IMPORTANT: Input may still be valid if first index is a neg sign
				return 0;
			}
			//checks if string does not end with a digit
			if(isdigit(exp.at(expSize - 1)) == 0) {
				return 0;
			}

			//iterating through string
			for(unsigned i = 0; i < expSize-1; i++) {
				char cur = exp.at(i);
				char next = exp.at(i+1);

				//if index is not a digit or an operation
				if((isdigit(cur) == 0) && (cur != '+') && (cur != '-') && (cur != '*') && (cur != '/') && (cur != '.')) {
					return 0;
				}

				//if we have a deciaml point
				if (cur == '.') {
					//check if index before a decimal point is a digit
					if (isdigit(exp.at(i-1)) == 0) {
						return 0;
					}
				}

				//if our current index is an operation
				if((cur == '+') || (cur == '/') || (cur == '-')) {
					//if the next index after an operation is not a digit
					if(isdigit(next) == 0)
						return 0;
				}

				//if out current index is a mult operation
				if(cur == '*') {
					//if the next index is not a digit and not another mult operation
					if((isdigit(next) == 0) && (next != '*'))
						return 0;
					//if the next index is a mult operation
					if(next == '*') {
						//make sure that we don't have a 3rd mult op
						if(exp.at(i+2) == '*')
							return 0;
					}
				} 
			}
			return 1;	
		}

	public:
		Base* parse(char** input, int length) {
			///if command length does not have an argument or has too large of an argument
			if (length != 2) {
				return nullptr;
			}
			std::string exp = input[1];
			
			//perform input check using helper function
			if (InputCheck(exp, length) == 0) {
				return nullptr;
			}

			std::vector<Base*> operands(0);
			std::vector<char> operations(0);
			int negKey = 0;
			int count = 0;

			if (exp.at(0) == '-') {
				negKey = 1;
			}			

			//Fill the vectors	
			for(unsigned i = negKey; i < exp.size(); i++) {
				unsigned j = i;
				double num = 0.0;
				double rhs = 0.0;
				double factor = 10;
				count += 1;
				
				//while our index is a digit or a decimal point
				while((isdigit(exp.at(j)) != 0) || (exp.at(j) == '.')) {
					//if the index is a decimal point then we need to operate on rhs
					if (exp.at(j) == '.') {
						if(isdigit(exp.at(j+1)) != 0) {
							j++;
							rhs += ((exp.at(j) - 48) / factor);
							factor *= 10; 	
						}
					}
					//index is a digit, not a decimal point
					else {
						//lets us add the next digit
						num *= 10;
					
						//turns character into an int
						num += exp.at(j) - 48;
					}

					//if we are at the last index of our vector we need to stop the loop
					if (j == exp.size() - 1) {
						break;
					}	
					j++;
				}
				//this is needed so we can tell if we had a digit or an operation.
				//If num is not zero then we know that we were operating on a digit instead of an operation
				if (num != 0) {
					double val = num + rhs;
					if (count == 1 && negKey == 1) {
						val *= -1;
					}
					Op* temp = new Op(val);
					operands.push_back(temp);
					//puts the for loop index where the while loop stopped
					i = j; 
				}
				//Must be an operation
				if(isdigit(exp.at(i)) == 0) {
					//if we have 2 mult ops then push back a pow sign
					if (exp.at(i+1) == '*') {
						operations.push_back('^');
						i += 1;
					}
					//else push back the sign in the string
					else {
						operations.push_back(exp.at(i));
					}
				}
			}

			unsigned i = 0;			
			//iterate through the operations vector
			//each operation should take in 2 vector indicies
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
