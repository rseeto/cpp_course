//Text.h

#ifndef TEXT_H
#define TEXT_H
#include <string>


class Text{
	public:
		Text();
		Text(std::string x);
		std::string contents();
	private:
		std::string stringObj;	
};

#endif