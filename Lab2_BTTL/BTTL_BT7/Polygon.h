#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include "Diem.h"
using namespace std;

class Polygon {
private:
	Diem* Point;
	int n;

public:
	Polygon();
	~Polygon();
	
	void Nhap();

	float DienTich();

};

#endif // !POLYGON_H
