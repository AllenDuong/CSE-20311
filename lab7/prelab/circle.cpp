#include "circle.h"
#define PI 3.14159

Circle::Circle(){
	radius = 1;
}

Circle::Circle(float r){
	radius = r;
}

Circle::~Circle(){}

float Circle::getRadius(){
	return radius;
}

void Circle::setRadius(float nr){
	radius = nr;
}

float Circle::circumference(){
	return (2 * PI * radius);
} 

float Circle::area(){
	return (PI * radius * radius);
}
