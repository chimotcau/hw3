#include <iostream>
#include <cmath>
// Define class Figure
class Figure{  
    public:
        // virtual parameter
        virtual double getarea() const =0;     
        virtual double getperimeter() const =0;
};
// Define class Triangle
class Triangle : public Figure{ 
    public:
        double sideA, sideB, sideC; 
        double a, p;
    Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {
        this->a = 0.0;
        this->p = 0.0;
    }
        double getarea() const override{
            return a;
        }
        void setarea(double sideA, double sideB, double sideC) {
            double s = (sideA + sideB + sideC) / 2;
            this->a = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
        }
        double getperimeter()const override{
            return p;           
        }
        void setperimeter(double sideA, double sideB, double sideC){
            this-> p= sideA + sideB + sideC;
        }
};
// Define class Rectangle  
class Rectangle : public Figure{
    public :
        double length, width;
        double a,p;
    Rectangle(double length, double width){
        this->a = 0.0;
        this->p = 0.0;
    }
        double getarea()const override{
            return a;
        }
        void setarea(double length, double width){
            this->a= length*width;
        }
        double getperimeter()const override{
            return p;
        } 
        void setperimeter(double length, double width){
            this->p= 2*(width + length);
        }   
}; 
// Define class Circle
class Circle: public Figure{
    public :
        double radius;
        double a,p;
    Circle(double radius){
        this->a = 0.0;
        this->p = 0.0;
    }
        double getarea()const override{
            return a ;
        }
        void setarea(double radius){
            this->a= M_PI*radius*radius;
        } 
        double getperimeter()const override{
            return p;
        }
        void setperimeter(double radius){
            this->p= 2*M_PI*radius;
        }
};
int main(){
    Triangle triangle(2,3,4);
    triangle.setarea(2,3,4);
    triangle.setperimeter(2,3,4);
    std::cout<<"The area of triangle is "<<triangle.getarea()<<"     ||     "<<"The perimeter of triangle is "<<triangle.getperimeter()<<'\n';
    Rectangle rectangle(2,3);
    rectangle.setarea(2,3);
    rectangle.setperimeter(2,3);
    std::cout<<"The area of rectangle is "<<rectangle.getarea()<<"          ||     "<<"The perimeter of rectangle is "<<rectangle.getperimeter()<<'\n';
    Circle circle(4);
    circle.setarea(4);
    circle.setperimeter(4);
    std::cout<<"The area of circle is "<<circle.getarea()<<"       ||     "<<"The perimeter of circle is "<<circle.getperimeter();
    return 0;
}
    

