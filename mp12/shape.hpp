//partners jaejin2, thomasp6

#ifndef SHAPE_H_
#define SHAPE_H_
 
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<list>
#include<fstream>
#include <iomanip>   
  
using namespace std;
 
//Base class
//Please implement Shape's member functions
//constructor, getName()
class Shape{
public:
   //Base class' constructor should be called in derived classes'
   //constructor to initizlize Shape's private variable
   Shape(string name) {
         name_ = name;
   }
  
   string getName() {
         return name_;
   }
  
   virtual double getArea() const = 0;
   virtual double getVolume() const = 0;
  
private:
 string name_;
 
 
};
 
//Rectangle
//Please implement the member functions of Rectangle:
//constructor, getArea(), getVolume(), operator+, operator-
 
template <class T>
class Rectangle : public Shape{
public:
   Rectangle<T>(T width = 0, T length = 0):Shape("Rectangle") {
         width_ = width;
         length_ = length;
   }
  
   double getArea() const {
         return width_*length_;
   }
  
   double getVolume() const {
         return 0;
 
   }
  
   Rectangle<T> operator + (const Rectangle<T>& rec) {
       return Rectangle(width_+rec.width_,length_+rec.length_);
   }
  
   Rectangle<T> operator - (const Rectangle<T>& rec) {
       T w,l;
       if(width_-rec.width_>0){
           w = width_-rec.width_;
       }
       else{
           w=0;
       }
       if(length_-rec.length_>0){
           l = length_-rec.length_;
       }
       else{
           l = 0;
       }
       return Rectangle(w,l);
   }
  
   T getWidth() const {
       return width_; 
   }
  
   T getLength() const {
       return length_;
  
   }
private:
   T width_;
   T length_;
 
};
 
//Circle
//Please implement the member functions of Circle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here
 
class Circle : public Shape{
public:
   Circle(double radius):Shape("Circle") {
         radius_ = radius;
   }
  
   double getArea() const{
         return M_PI*radius_*radius_;
   }
  
   double getVolume() const{
        return 0;
   }
  
   Circle operator + (const Circle& cir){
         return Circle(radius_+cir.radius_);
   }
  
   Circle operator - (const Circle& cir){
       if(radius_-cir.radius_>0){
           return Circle(radius_-cir.radius_);
       }
   }
 
   double getRadius() const {
       return radius_;
   }
  
private:
   double radius_;
 
};
 
 
 
//Sphere
//Please implement the member functions of Sphere:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here
 
class Sphere : public Shape{
public:
   Sphere(double radius):Shape("Sphere") {
         radius_ = radius;
   }
 
   double getVolume() const {
         return 4*M_PI*radius_*radius_*radius_/3.0;
   }  
  
   double getArea() const {
         return 4*M_PI*radius_*radius_;
   }
 
   Sphere operator + (const Sphere& sph) {
       return Sphere(radius_+sph.radius_);
   }
 
   Sphere operator - (const Sphere& sph) {
       if(radius_-sph.radius_>0){
           return Sphere(radius_-sph.radius_);
       }
 
   }
  
   double getRadius() const {
       return radius_;
   }
 
private:
   double radius_;
 
};
 
//Rectprism
//Please implement the member functions of RectPrism:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here
class RectPrism : public Shape{
public:
   RectPrism(double width, double length, double height):Shape("RectPrism") {
         width_ = width;
         length_ = length;
         height_ = height;
   }
  
   double getVolume() const {
         return width_*length_*height_;
 
   }
  
   double getArea() const {
       return 2.0*(width_*length_+height_*length_+height_*width_);
 
   }
  
   RectPrism operator + (const RectPrism& rectp){
       return RectPrism(width_+rectp.width_,length_+rectp.length_,height_+rectp.height_);
   }
  
   RectPrism operator - (const RectPrism& rectp){
       if(width_-rectp.width_>0 && length_-rectp.length_>0 && height_-rectp.height_>0){
           return RectPrism(width_-rectp.width_,length_-rectp.length_,height_-rectp.height_);
       }
   }  
  
   double getWidth() const {
       return width_;
   }
  
   double getLength() const {
       return length_;
   }
  
   double getHeight() const {
       return height_;
   }
private:
   double length_;
   double width_;
   double height_;
 
};
 
// Read shapes from test.txt and initialize the objects
// Return a vector of pointers that points to the objects
static list<Shape*> CreateShapes(char* file_name) {
   //@@Insert your code here
  
   return list<Shape*>(0, NULL);;
}
 
// call getArea() of each object
// return the max area
static double MaxArea(list<Shape*> shapes){
   double max_area = 0;
   //@@Insert your code here
   list<Shape*>:: iterator iterate;
   iterate = shapes.begin();
   while(iterate!=shapes.end())
   {
	   if (((*iterate)->getArea())>max_area)
	   {
		   max_area= (*iterate)->getArea();
	   }
	   iterate++;
   }
  
   return max_area;
}
 
// call getVolume() of each object
// return the max volume
static double MaxVolume(list<Shape*> shapes){
   double max_volume = 0;
   //@@Insert your code here
	list<Shape*>:: iterator iterate;
   iterate = shapes.begin();
   while(iterate!=shapes.end())
   {
	   if (((*iterate)->getVolume())>max_volume)
	   {
		   max_volume= (*iterate)->getVolume();
	   }
	   iterate++;
   }
  
   return max_volume;
}
 
#endif
 
 
 
 
 
