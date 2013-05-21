#include<iostream>
class Rectangle
{
    double width;
    double length;
public:
    Rectangle()
    {
        width = 0.0;
        length = 0.0;    
    }
    Rectangle(double w, double l)
    {
        width = w;
        length = l;    
    }  
    Rectangle(Rectangle &r)
    {
        width = r.width;
        length = r.length;    
    }
    double C()
    {
        return 2*(width+length);    
    }
    double S()
    {
        return width*length;    
    }
    void change(double w, double l)
    {
        width = w;
        length = l;            
    }
};
