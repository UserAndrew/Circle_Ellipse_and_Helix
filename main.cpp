#include "Curve.h"
#include <random>
#include <vector>
#include <memory>
#include <cassert>
#include <algorithm>

enum figure
{
    circle = 1,
    ellipse,
    helix
};

std::random_device rd;
std::mt19937 gen(rd());

int random(int low, int high)
{
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

int main()
{
    int N;
    std::cout << "Введите количество объектов: " << std::endl;
    std::cin >> N;
    std::vector<int> curves(N);
    std::vector<std::shared_ptr<ICurve>> lines;
    std::vector<std::shared_ptr<Circle>> circles;
    for(int i = 0; i < N; ++i)
    {
        curves.push_back(random(1, 3));
    }

    for(size_t i = 0; i < curves.size(); ++i)
    {
        if(curves[i] == figure::circle)
        {
            double x = random(-30,30);
            double y = random(-30,30);
            double R = random(1,30);
            assert(R > 0 && "Радиус окружности не может быть отрицательным числом или нулём");
            lines.emplace_back(new Circle(x,y,R));
        }
        else if(curves[i] == figure::ellipse)
        {
            double x = random(-30,30);
            double y = random(-30,30);
            double Rx = random(1,30);
            double Ry = random(1,30);
            assert(Rx > 0 && "Полуось не может быть отрицательным числом или нулём");
            assert(Ry > 0 && "Полуось не может быть отрицательным числом или нулём");
            lines.emplace_back(new Ellipse(x,y,Rx,Ry));
        }
        else if(curves[i] == figure::helix)
        {
            double x = random(-30,30);
            double y = random(-30,30);
            double h = random(1,15);
            double R = random(1,30);
            assert(R > 0 && "Радиус спирали не может быть отрицательным числом или нулём");
            lines.emplace_back(new Helix(x,y,h,R));
        }
    }

    double t = M_PI/4;
    for(auto &elem : lines)
    {
        elem->printCoordinatesPoint(t);
        elem->printCoordinatesDerivate(t);
        if(elem->getType() == Figures::CIRCLE)
        {
            circles.push_back(std::dynamic_pointer_cast<Circle>(elem));
        }
    }

    std::sort(circles.begin(), circles.end());

    double sum = 0;
    for(auto &elem : circles)
    {
        double radius = (*elem).getR();
        sum += radius;
    }

    std::cout << "Общая сумма радиусов равна " << sum << std::endl;

    for(size_t i = 0; i < circles.size(); ++i)
    {
        std::cout << circles[i]->getR()<<'\t';
    }
    return 0;
}
