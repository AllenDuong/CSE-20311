// Part 2: Quadrants and Polar Coordinates
//		polar.cpp
// prompts the user for the x and y coordinates for a point in a Cartesian coordinate system
// displays :
//		the point's corresponding polar coordinates
//		the quadrant that the point is in; or the axis it is on; or the origin, as the case may be

#include<iostream>
#include<cmath>

using namespace std;

#define PI 3.14159265

// Prototype Functions
double radiusConvert(double xCoord, double yCoord);
double thetaConvert(double xCoord, double yCoord);
void findQuad(double xCoord, double yCoord);


int main(){
	double xCoord = 0;
	double yCoord = 0;
	double radius = 0;
	double theta = 0;

	// Get Input
	cout << "CARTESIAN TO POLAR CONVERTER" << endl;
	cout << "Enter the X Location of the Point in Cartesian Coords: ";
	cin >> xCoord;
	cout << "Enter the X Location of the Point in Cartesian Coords: ";
	cin >> yCoord;


	// Call Funtions
	radius = radiusConvert(xCoord, yCoord);
	theta = thetaConvert(xCoord, yCoord);

	// Output Results
	cout << endl << "The Entered Point in Polar Coords (r,theta in degrees) is: ";
	cout << "(" << radius << ", " << theta << ") " << endl;

	// Find and Output Quadrant
	findQuad(xCoord, yCoord);

	return 0;
}

// Find Radius from Standard Formula
double radiusConvert(double xCoord, double yCoord){

	double radius = 0;

	radius = sqrt((pow(xCoord, 2) + pow(yCoord, 2)));	

	return radius;
}

// Find Theta using Stadnard Formula
double thetaConvert(double xCoord, double yCoord){

	double theta = 0;

	theta = atan2(yCoord, xCoord) * 180 / PI; // Calculates theta in degrees between -180 and 180

	return theta;
}

// Determine Location and Output
// Checks X Coordinate First then determines location using nested if statements
void findQuad(double xCoord, double yCoord){

	if (xCoord == 0){

		if (yCoord == 0){
			cout << "The Point is on the Origin" << endl;
		}
		else if (yCoord > 0){
			cout << "The Point is on the Positive Y-Axis" << endl;
		}
		else if (yCoord < 0){
			cout << "The Point is on the Negative Y-Axis" << endl;
		}

	}

	else if (xCoord > 0){

		if (yCoord == 0){
			cout << "The Point is on the Positive X-Axis" << endl;
		}
		else if (yCoord > 0){
			cout << "The Point is in the First Quadrant" << endl;
		}
		else if (yCoord < 0){
			cout << "The Point is in the Fourth Quadrant" << endl;
		}

	}

	else if (xCoord < 0){

		if (yCoord == 0){
			cout << "The Point is on the Negative X-Axis" << endl;
		}
		else if (yCoord > 0){
			cout << "The Point is in the Second Quadrant" << endl;
		}
		else if (yCoord < 0){
			cout << "The Point is in the Third Quadrant" << endl;
		}

	}



}