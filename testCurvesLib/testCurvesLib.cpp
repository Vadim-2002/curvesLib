#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <algorithm>
#include <numeric>
#include <random>
#include <omp.h>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"


/// @brief Функция для генерации случайных кривых с использованием std::random
/// @param n Количество кривых для генерации
/// @return Вектор указателей на сгенерированные кривые
std::vector<std::shared_ptr<Curve>> generateRandomCurves(int n)
{
    // Настройка генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());

    // Для выбора типа кривой
    std::uniform_int_distribution<> distType(0, 2);
    // Для радиуса окружностей и эллипсов
    std::uniform_int_distribution<> distRadius(1, 10);
    // Для высоты спирали
    std::uniform_int_distribution<> distHeight(1, 5);

    std::vector<std::shared_ptr<Curve>> curves;
    for (int i = 0; i < n; ++i)
    {
        int type = distType(gen);
        if (type == 0) {
            // Генерация окружности
            double radius = distRadius(gen);
            curves.push_back(std::make_shared<Circle>(radius));
        }
        else if (type == 1) {
            // Генерация эллипса
            double a = distRadius(gen);
            double b = distRadius(gen);
            curves.push_back(std::make_shared<Ellipse>(a, b));
        }
        else {
            // Генерация спирали
            double radius = distRadius(gen);
            double height = distHeight(gen);
            curves.push_back(std::make_shared<Helix>(radius, height));
        }
    }

    return curves;
}

/// @brief Функция для вычисления суммы радиусов окружностей
/// @param circles Список окружностей
/// @return Сумма радиусов
double computeTotalRadius(const std::list<std::shared_ptr<Circle>>& circles) 
{
    double totalRadius = 0.0;

    #pragma omp parallel for reduction(+:totalRadius)
    for (auto it = circles.begin(); it != circles.end(); ++it) 
    {
        totalRadius += (*it)->getRadius();
    }

    return totalRadius;
}


int main() 
{
    const int numCurves = 10;
    auto curves = generateRandomCurves(numCurves);

    // Фильтрация окружностей
    std::list<std::shared_ptr<Circle>> circles;
    for (const auto& curve : curves) 
    {
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve))
        {
            circles.push_back(circle);
           }
    }

    // Сортировка окружностей по радиусу
    circles.sort([](const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) {
        return a->getRadius() < b->getRadius();
        });

    // Вычисление суммы радиусов
    double totalRadius = computeTotalRadius(circles);
    std::cout << "Total sum of radus: " << totalRadius << std::endl;

    const double PI = 3.14;
    const double t = PI / 4;
    std::cout << "\nCoordinates for each curve at t = " << t << ":\n";

    for (const auto& curve : curves)
    {
        auto coords = curve->point(t);
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve))
        {
            std::cout << "Circle: \n";
        }
        else if (auto ellipse = std::dynamic_pointer_cast<Ellipse>(curve))
        {
            std::cout << "Ellipse: \n";
        }
        else if (auto helix = std::dynamic_pointer_cast<Helix>(curve))
        {
            std::cout << "Helix: \n";
        }

        
        std::cout << "\tPoint(" << coords[0] << ", " << coords[1] << ", " << coords[2] << ")\n";

        auto deriv = curve->derivative(t);
        std::cout << "\tDerivative(" << deriv[0] << ", " << deriv[1] << ", " << deriv[2] << ")\n\n";
    }

    return 0;
}
