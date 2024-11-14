#pragma once
#include "Curve.h"
#include <cmath>


/// @class Ellipse
/// @brief Класс для представления эллипса на плоскости.
class Ellipse : public Curve 
{
private:
    /// @brief Полуось вдоль оси X
    double mX;
    /// @brief Полуось вдоль оси Y
    double mY;

public:
    /// @brief Конструктор по умолчанию.
    Ellipse() : mX(0.0), mY(0.0) {}

    /// @brief Конструктор с параметрами.
    /// @param x Полуось вдоль оси X.
    /// @param y Полуось вдоль оси Y.
    Ellipse(double x, double y) : mX(x), mY(y) {}

    /// @brief Конструктор копирования.
    /// @param other Другой объект `Ellipse` для копирования.
    Ellipse(const Ellipse& other) : mX(other.mX), mY(other.mY) {}

    /// @brief Возвращает координаты точки на эллипсе.
    /// @param t Параметр для вычисления точки (радианы).
    /// @return Массив координат {x, y, z}.
    std::array<double, 3> point(double t) const override { return { mX * cos(t), mY * sin(t), 0 }; }

    /// @brief Возвращает первый производный вектор эллипса.
    /// @param t Параметр для вычисления производной (радианы).
    /// @return Массив производных {dx/dt, dy/dt, dz/dt}.
    std::array<double, 3> derivative(double t) const override { return { -mX * sin(t), mY * cos(t), 0 }; }

    /// @brief Получить значение полуоси X.
    double getX() const { return mX; }

    /// @brief Получить значение полуоси Y.
    double getY() const { return mY; }

    /// @brief Установить новое значение для полуоси X.
    void setX(double x) { mX = x; }

    /// @brief Установить новое значение для полуоси Y.
    void setY(double y) { mY = y; }
};
