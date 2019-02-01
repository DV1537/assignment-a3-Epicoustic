#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vector2.h"
#include "shape.h"
#include "line.h"

class Triangle : public Shape
{
public:
    Triangle(Vertices *sentCoord,const int size);
    const char* getType();
    float area();
    float circumference();
    Vertices position();
    bool isConvex();
private:
    Vertices tempVector[3];
    int arrSize;
};

#endif