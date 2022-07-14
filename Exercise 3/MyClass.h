//MyClass.h

#ifndef MYCLASS_H
#define MYCLASS_H


class MyClass{
	public:
		void myFunction();
	private:
		double increase[10000];
		double decrease[10000];	
};

inline void MyClass::myFunction(){
	for(int i = 0; i < 10000; i++){
		increase[i] = 100 + i;
		decrease[i] = 10099 - i;
		std::cout << increase[i] * decrease[i] << std::endl;
	}
}

#endif