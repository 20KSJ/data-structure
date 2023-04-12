#pragma once
#include <cstdio>
#include <vector>
#include <iostream>
#define MAX_DEGREE 100
using namespace std;

class PolynomialV {
	vector <float> coef;
public:
	int degree() {
		return coef.size();
	}
	void read() {
		int deg;
		float value;
		printf("다항식의 최고 차수를 입력하세요: ");
		scanf_s("%d", &deg);
		printf("각 항의 계수를 입력하세요 (총 %d개): ", deg + 1);
		for (int i = 0; i <= deg; i++)
		{
			scanf_s("%f", &value);
			coef.push_back(value);
		}
	}
};


class Polynomial {
	int degree;		
	float coef[MAX_DEGREE];

public:
	// 생성자 (Constructor)
	Polynomial() {
		degree = 0;		
		coef[0] = 0.0f;	
	}

	void read() {
		printf("다항식의 최고 차수를 입력하세요: ");
		scanf_s("%d", &degree);		
		printf("각 항의 계수를 입력하세요 (총 %d개): ", degree + 1);
		for (int i = 0; i <= degree; i++)
		{
			scanf_s("%f", coef + i);
		}
	}
	void display(const char* str = "Poly = ") {
		printf("\t%s", str);
		for (int i = 0; i < degree; i++)
			printf("%5.1f x^%d + ", coef[i], degree - i);

		printf("%4.1f\n", coef[degree]);
	}
	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {
			*this = a;	
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {
			*this = b;	
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
	}
	bool isZero() {
		return degree == 0;
	}
	void negate() {
		for (int i = 0; i < degree; i++)
			coef[i] = -coef[i];
	}

};
