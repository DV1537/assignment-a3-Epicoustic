#include "vector2.h"
#include "shape.h"
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "polygon.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>

float roundedArea(float n);

int main(int argc, const char *argv[]){
	std::ifstream myReadFile(argv[1]);
	std::string line = "";
	
	Vector2 firstVertices;
	Vector2 secondVertices;

	while (!(myReadFile.eof())){
		bool shapeRead = false;
		//reads line by line
		while (getline(myReadFile, line)){
			std::stringstream ss(line);
			if (!(shapeRead)){
				if(!(firstVertices.readVertices(ss))){
					std::cout << "Invalid input";
					return 1;
				}
				shapeRead = true;
			}
			else {
				if(!(secondVertices.readVertices(ss))){
					std::cout << "Invalid input";
					return 1;
				}
			}
		}
	}
	
	Vector2 combinedVertices;
	combinedVertices = firstVertices + secondVertices;

	int verticeAmount = combinedVertices.getSize();
	Vertices *arrPtr;
	arrPtr = combinedVertices.getArrPointer();
	Shape* shape;

	if(verticeAmount == 1){
		Point pointObj(arrPtr);
		std::cout << pointObj.area() << " area " << std::endl;
		shape = &pointObj;
	}

	if(verticeAmount == 2){
		Line lineObj(arrPtr,verticeAmount);
		std::cout << lineObj.area() << " area " << std::endl;
		shape = &lineObj;
	}

	if(verticeAmount == 3){
		Triangle triObj(arrPtr,verticeAmount);
		std::cout << roundedArea(triObj.area()) << " area " << std::endl;
		shape = &triObj;
	}

	if(verticeAmount >= 4){
		Polygon polyObj(arrPtr,verticeAmount);
		std::cout << roundedArea(polyObj.area()) << " area " << std::endl;
		shape = &polyObj;
	}

	myReadFile.close();
	std::cin.get();
}

float roundedArea(float n){
		float roundedArea = roundf(n * 1000) / 1000;
		return roundedArea;
}