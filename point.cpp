#include "point.h"
#include <iostream>


Point::Point(Vertices *sentCoord)
{
	x = sentCoord[0].x;
	y = sentCoord[0].y;
}

const char* Point::getType(){
	return "Point";
}

float Point::area(){
	return -1;
}

float Point::circumference(){
	return 0;
}

Vertices Point::position(){
	Vertices centroid;
	centroid.x = x;
	centroid.y = y;
	return centroid;
}

bool Point::isConvex(){
	return false;
}