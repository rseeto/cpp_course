//MovieInfo.h

#ifndef MOVIEINFO_H
#define MOVIEINFO_H
#include<string>


class MovieInfo{
 public:
 	void setTitle(std::string);
 	void setRank(std::string);
 	void setGross(std::string);
 	void setYear(std::string);
 	void setTomatometer(std::string);
 	void setAvailable(std::string);
 	std::string getTitle();
 	int getAvailable();
 	void rtrn();
 	void rnt();
 	void print();
 private:
 	std::string title;
 	std::string rank;
 	std::string gross;
 	std::string year;
 	std::string tomatometer;
  	int available;
};

#endif