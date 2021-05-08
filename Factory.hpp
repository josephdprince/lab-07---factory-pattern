#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <string>
#include "base.hpp"

class Factory {
	public:
		Base* parse(char** input, int length) {
			Base* prev = null;
			string exp = input[1];
			if((exp.at(0).isdigit() == 0) || exp.at(length - 1).isdigit() == 0)
				return null;
			for(unsigned i = 0; i < length-1; i++) {
				char cur = exp.at(i);
				char next = exp.at(i+1);
				if((cur.isdigit() == 0) ||
					(cur != "+") || (cur != "-") ||
					(cur != "*") || (cur != "/")) {
					return null;
				}
				if((cur == "+") || (cur == "/") || (cur == "-")) {
					if(next.isdigit() == 0)
						return null;
				}
				if(cur == "*") {
					if((next.isdigit() == 0) || (next != "*"))
						return null;
					if(next == "*") {
						if(exp.at(i+2) == "*")
							return null;
					}
				} 
			}
			/*
			for(unsigned i = 0; i < length; i+=2) {
				if(exp.at(i).isdigit() != 0) {
				
				} else {
				
				}	
			}
			*/
		}
};

#endif
