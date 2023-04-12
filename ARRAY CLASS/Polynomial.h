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
		printf("���׽��� �ְ� ������ �Է��ϼ���: ");
		scanf_s("%d", &deg);
		printf("�� ���� ����� �Է��ϼ��� (�� %d��): ", deg + 1);
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
	// ������ (Constructor)
	Polynomial() {
		degree = 0;		
		coef[0] = 0.0f;	
	}

	void read() {
		printf("���׽��� �ְ� ������ �Է��ϼ���: ");
		scanf_s("%d", &degree);		
		printf("�� ���� ����� �Է��ϼ��� (�� %d��): ", degree + 1);
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