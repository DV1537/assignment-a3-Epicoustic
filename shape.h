#ifndef SHAPE_H
#define SHAPE_H
#include "vector2.h"

class Shape{
    public:
        virtual const char* getType();
		virtual float area() = 0;
        virtual float circumference();
        virtual Vertices position();
        virtual bool isConvex();      
        virtual float distance(Shape &s);
    private:
};


#endif