#pragma once
#include <cstdio>
#include <cstring>

class Car {
private:	

protected:		
	int		speed;		
	char	name[40];		

public:			
	int		gear;

	Car() :speed(0), gear(0), name("") {}
	~Car() {}								
	Car(int s, int g, const char* n)
		: speed(s), gear(g) {
		strcpy_s(name, n);	
	}

	void changeGear(int g) {
		gear = g;
	}
	void speedUp() {
		speed += 5;
	}
	void display() {
		printf("[%s] : 기어=%d단, 속도=%dkmph\n", name, gear, speed);
	}
	void whereAmI() {
		printf("객체 주소 = %p\n", this);
	}
}; 
