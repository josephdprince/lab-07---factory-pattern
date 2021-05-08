#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <string>
#include "base.hpp"
#include "op.hpp"

class Factory {
	public:
		Base* parse(char** input, int length) {
			if(length < 2)
				return nullptr;
			Base* prev = nullptr;
			std::string exp = input[1];
			int expSize = exp.size();
			if((isdigit(exp.at(0)) == 0) || isdigit(exp.at(expSize-1)) == 0)
				return nullptr;
			for(unsigned i = 0; i < expSize-1; i++) {
				char cur = exp.at(i);
				char next = exp.at(i+1);
				if((isdigit(cur) == 0) && (cur != '+') && (cur != '-') && (cur != '*') && (cur != '/')) {
					return nullptr;
				}
				if((cur == '+') || (cur == '/') || (cur == '-')) {
					if(isdigit(next) == 0)
						return nullptr;
				}
				if(cur == '*') {
					if((isdigit(next) == 0) && (next != '*'))
						return nullptr;
					if(next == '*') {
						if(exp.at(i+2) == '*')
							return nullptr;
					}
				} 
			}
			/*
			for(unsigned i = 0; i < expSize; i+=2) {
				if(exp.at(i).isdigit() != 0) {
				
				} else {
				
				}	
			}
			*/
		}
};

#endif
