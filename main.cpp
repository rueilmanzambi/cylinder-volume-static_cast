// Programmer: Rueil Manzambi  
// MST username: rnm8cm
// Instructor: Johnathan Dunker
// Section: 301
// Date: 02/23/2021
// File: lab6.cpp
// Description: This program calcultes the volume of a cylinder, the areas of a circle and rectangle using random double values. And it sorts those answers from the smallest to the largest
 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constant declaration
const float PI = 3.1416;

// Functions prototypes
double circleArea(const double radius);
double rectArea(const double length, const double width);
double cylinderVolume(const double radius, const double height);
void sortValues(double & value1, double & value2, double & value3);
double randDouble(int precision);


int main()
{
  // Variables declarations
  double radiusCircle;
  double lengthRectangle;
  double widthRectangle;
  double radiusCylinder;
  double heightCylinder;
  double value1;
  double value2;
  double value3;
  int precision = 2;


  srand(time(0)); // seeding for random number


  /* Function calling and output */

  radiusCircle = 6 + static_cast<double> (rand())/(static_cast<double>(RAND_MAX/(5))); // getting random number between 6 and 11 inclusive
  value1 = circleArea(radiusCircle);
  cout << "r: "<< radiusCircle <<", Circle: "<<value1<<endl;


  lengthRectangle = 10 + static_cast<double> ((rand())/static_cast<double>(RAND_MAX/(5))); // getting random number between 10 and 15 inclusive
  widthRectangle = 10 + static_cast<double> ((rand())/static_cast<double>(RAND_MAX/(15))); // getting random number between 10 and 25 inclusive
  value2 = rectArea (lengthRectangle, widthRectangle);
  cout << "(" << lengthRectangle <<","<< widthRectangle<< "): rect:   "<< value2 << endl;


  radiusCylinder = 3 + static_cast<double> ((rand())/static_cast<double>(RAND_MAX/(2))); // getting random number between 3 and 5 inclusive
  heightCylinder = 3 + static_cast<double> ((rand())/static_cast<double>(RAND_MAX/(2)));
  value3 = cylinderVolume(radiusCylinder, heightCylinder);
  cout <<"("<<radiusCylinder<< ","<< heightCylinder<< "): cyl:    " << value3 << endl;

   
  sortValues(value1, value2, value3); // sorting numbers from the smallest to the largest
  cout << "value 1: " << value1 << endl;
  cout << "value 2: " << value2 << endl;
  cout << "value 3: " << value3 << endl;

  randDouble(precision); // calling the function to get a random number between 0 and 1 with respect to the precision passed

  return 0;

}

/* Functions definitions */


// Description: Computes and returns the area of a circle
// Pre: radius must be positive
// Post: returns the area of a circle
double circleArea(const double radius)
{
  return (PI * radius * radius);
}


// Description: computes and returns the area of a rectangle
// Pre: length and width must be positive nonzero
// Post: returns the area of a rectangle
double rectArea(const double length, const double width)
{
  return (length * width);
}


// Description: computes and returns the volume of a cylinder
// Pre: radius and height must be positive nonzero
// Post: returns the volume of a cylinder
double cylinderVolume(const double radius, const double height)
{
  return (PI * radius * radius * height);
}


// Description: sort value1, value2 and value3 by reference from the smallest to the largest
// Pre: value1, value2 and value3 must exist in main()
// Post: returns nothing, assigns the smallest value to value1, the next smallest to value2 and the largest to value3
void sortValues(double & value1, double & value2, double & value3)
{
  double sort_helper; // to facilitate the sorting
  
  if (value1 < value2 && value1 < value3) // executes when value1 is the smallest value
  {
    if (value2 < value3)
      return;
    else // executes when value2 is the biggest
    {
      sort_helper = value2;
      value2 = value3;
      value3 = sort_helper;
      return;
    }
  }
  if (value2 < value1 && value2 < value3) // executes when value2 is the smallest
  {
    if (value1 < value3)
    {
      sort_helper = value1;
      value1 = value2;
      value2 = sort_helper;
      return;
    }
    else // executes when value1 is the biggest
    {
      sort_helper = value1;
      value1 = value2;
      value2 = sort_helper;
      sort_helper = value3;
      value3 = value2;
      value2 = sort_helper;
      return;
    }    
  }
  if (value3 < value1 && value3 < value2) // executes when value3 is the smallest
  {
    if (value1 < value2)
    {
      sort_helper = value2;
      value2 = value1;
      value1 = value3;
      value3 = sort_helper;
      return;
    }
    else // executes when value1 is the biggest
    {
      sort_helper = value1;
      value1 = value3;
      value3 = sort_helper;
      return;
    }
  }
}



// Description: get a random number between 0 and 1 and returns it depending on the value of precision
// Pre: None
// Post: returns a whole number (o or 1) if precision is 0. if precision is a negative value, it returns the exact random number.
//       If precision is more than 0, it rounds the random with decimal the number of decimals equal to the value of precision
//       and returns it to main 
double randDouble(int precision)
{
  // variable declaration
  double rand_number;
  
  static bool first = true; // seeds to time(0) only the first time the function is called
  if (first)
  {
    srand(time(0));
    first = false;
  }

  if (precision > 0) // rounds and returns with decimals with respect to precision if condition is true
  {
    rand_number = static_cast <double>(rand()) / static_cast <double>(RAND_MAX);
    for (int i=0; i < precision; i++)
      rand_number *= 10;
    rand_number = static_cast <double> (static_cast<int>(rand_number + 0.5));
    for (int i = 0; i < 2; i++)
      rand_number /= 10;
    return rand_number;
  }
  else if (precision < 0) // return the exact random number if condition is true
  {
    rand_number = static_cast <double>(rand()) / static_cast <double>(RAND_MAX);
    return rand_number;
  }       
  else // return a whole number (1 or 0) when precision is 0
  {
    rand_number = static_cast <double>(rand()) / static_cast <double>(RAND_MAX);
    rand_number *= 10;
    rand_number = static_cast<double>(static_cast<int>(rand_number));
    if (rand_number >= 5)
      return 1;
    else
       return 0;
  }
}
