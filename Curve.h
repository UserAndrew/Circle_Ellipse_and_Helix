#ifndef CURVE_H
#define CURVE_H

#include <iostream>
#include <cmath>

struct Coordinates
{
    double x;
    double y;
    double z;
};

enum class Figures
{
    CIRCLE,
    ELLIPSE,
    HELIX
};

struct ICurve
{
    virtual Coordinates getCoordinates(double) = 0;
    virtual Coordinates getDerivate(double) = 0;
    virtual void printCoordinatesPoint(double) = 0;
    virtual void printCoordinatesDerivate(double) = 0;
    virtual Figures getType() = 0;
    virtual ~ICurve(){}
};

struct Circle : ICurve
{
    Circle(double x_, double y_, double R_) : x{x_}, y{y_}, R{R_}
    {
    }
    Coordinates getCoordinates(double) override;
    Coordinates getDerivate(double) override;
    void printCoordinatesPoint(double) override;
    void printCoordinatesDerivate(double) override;
    Figures getType() override;
    double getR() {return R;}

    friend bool operator< (const Circle& c1, const Circle& c2);

private:
    double x;
    double y;
    const double z = 0;
    double R;
};

struct Ellipse : ICurve
{
    Ellipse(double x_, double y_, double Rx_, double Ry_)
        : x{x_}, y{y_}, Rx{Rx_}, Ry{Ry_}
    {
    }
    Coordinates getCoordinates(double) override;
    Coordinates getDerivate(double) override;
    void printCoordinatesPoint(double) override;
    void printCoordinatesDerivate(double) override;
    Figures getType() override;
private:
    double x;
    double y;
    const double z = 0;
    double Rx;
    double Ry;
};

struct Helix : ICurve
{
    Helix(double x_, double y_, double h_, double R_)
        : x{x_}, y{y_}, h{h_}, R{R_}
    {
    }
    Coordinates getCoordinates(double) override;
    Coordinates getDerivate(double) override;
    void printCoordinatesPoint(double) override;
    void printCoordinatesDerivate(double) override;
    Figures getType() override;
private:
    double x;
    double y;
    const double z = 0;
    double h;
    double R;
};

#endif // CURVE_H
