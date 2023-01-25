#include "Curve.h"

Coordinates Circle::getCoordinates(double t)
{
    Coordinates coordinate;
    coordinate.x = R*cos(t);
    coordinate.y = R*sin(t);
    coordinate.z = z;
    return coordinate;
}

Coordinates Circle::getDerivate(double t)
{
    Coordinates coordinate;
    if(sin(t) == 0)
    {
        coordinate.x = 0;
        coordinate.y = 1;
        coordinate.z = z;
    }
    else
    {
        double dy_dx = -(cos(t))/(sin(t));
        coordinate.x = cos(atan(dy_dx));
        coordinate.y = sin(atan(dy_dx));
        coordinate.z = z;
    }
    return coordinate;
}

void Circle::printCoordinatesPoint(double t)
{
    Coordinates coord = getCoordinates(t);
    std::cout<<"Координаты точки на окружности при t = "<<t<<" ";
    std::cout<<"{"<<coord.x<<","<<coord.y<<","<<coord.z<<"}"<<std::endl;
}

void Circle::printCoordinatesDerivate(double t)
{
    Coordinates coord = getDerivate(t);
    std::cout<<"Координаты единичного вектора производной при t = "<<t<<" ";
    std::cout<<"{"<<coord.x<<","<<coord.y<<","<<coord.z<<"}"<<std::endl;
}

Figures Circle::getType()
{
    return Figures::CIRCLE;
}

bool operator< (const Circle& c1, const Circle& c2)
{
    return c1.R < c2.R;
}

Coordinates Ellipse::getCoordinates(double t)
{
    Coordinates coordinate;
    coordinate.x = Rx*cos(t);
    coordinate.y = Ry*sin(t);
    coordinate.z = z;
    return coordinate;
}

Coordinates Ellipse::getDerivate(double t)
{
    Coordinates coordinate;
    if(sin(t) == 0)
    {
        coordinate.x = 0;
        coordinate.y = 1;
        coordinate.z = z;
    }
    else
    {
        double dy_dx = -(Ry*cos(t))/(Rx*sin(t));
        coordinate.x = cos(atan(dy_dx));
        coordinate.y = sin(atan(dy_dx));
        coordinate.z = z;
    }
    return coordinate;
}

void Ellipse::printCoordinatesPoint(double t)
{
    Coordinates coord = getCoordinates(t);
    std::cout<<"Координаты точки на эллипсе при t = "<<t<<" ";
    std::cout<<"{"<<coord.x<<","<<coord.y<<","<<coord.z<<"}"<<std::endl;
}

void Ellipse::printCoordinatesDerivate(double t)
{
    Coordinates coord = getDerivate(t);
    std::cout<<"Координаты единичного вектора производной при t = "<<t<<" ";
    std::cout<<"{"<<coord.x<<","<<coord.y<<","<<coord.z<<"}"<<std::endl;
}

Figures Ellipse::getType()
{
    return Figures::ELLIPSE;
}

Coordinates Helix::getCoordinates(double t)
{
    Coordinates coordinate;
    coordinate.x = R*cos(t);
    coordinate.y = R*sin(t);
    coordinate.z = (h*t)/(2*M_PI);
    return coordinate;
}

Coordinates Helix::getDerivate(double t)
{
    Coordinates coordinate;
    if(sin(t) == 0)
    {
        coordinate.x = 0;
        coordinate.y = 1;
        coordinate.z = (h*t)/(2*M_PI);
    }
    else
    {
        double dy_dx = -(cos(t))/(sin(t));
        double dy_dz = (R*cos(t)*2*M_PI)/h;
        coordinate.x = cos(atan(dy_dx));
        coordinate.y = sin(atan(dy_dx));
        coordinate.z = sin(atan(dy_dz));
    }
    return coordinate;
}

void Helix::printCoordinatesPoint(double t)
{
    Coordinates coord = getCoordinates(t);
    std::cout<<"Координаты точки на спирали при t = "<<t<<" ";
    std::cout<<"{"<<coord.x<<","<<coord.y<<","<<coord.z<<"}"<<std::endl;
}

void Helix::printCoordinatesDerivate(double t)
{
    Coordinates coord = getDerivate(t);
    std::cout<<"Координаты единичного вектора производной при t = "<<t<<" ";
    std::cout<<"{"<<coord.x<<","<<coord.y<<","<<coord.z<<"}"<<std::endl;
}

Figures Helix::getType()
{
    return Figures::HELIX;
}
