#pragma once
#include "Curve.h"
#include <cmath>


/// @class Circle
/// @brief Класс для представления окружности на плоскости.
class Circle : public Curve 
{
private:
    /// @brief Радиус окружности
    double mRadius;

public:
    /// @brief Конструктор по умолчанию.
    Circle() : mRadius(0.0) {}

    /// @brief Конструктор с параметром.
    /// @param radius Радиус окружности.
    Circle(double radius) : mRadius(radius) {}

    /// @brief Конструктор копирования.
    /// @param other Другой объект `Circle` для копирования.
    Circle(const Circle& other) : mRadius(other.mRadius) {}

    /// @brief Возвращает координаты точки на окружности.
    /// @param t Параметр для вычисления точки (радианы).
    /// @return Массив координат {x, y, z}.
    std::array<double, 3> point(double t) const override { return { mRadius * cos(t), mRadius * sin(t), 0 }; }

    /// @brief Возвращает первый производный вектор окружности.
    /// @param t Параметр для вычисления производной (радианы).
    /// @return Массив производных {dx/dt, dy/dt, dz/dt}.
    std::array<double, 3> derivative(double t) const override { return { -mRadius * sin(t), mRadius * cos(t), 0 }; }

    /// @brief Получить радиус окружности.
    /// @return Радиус окружности.
    double getRadius() const { return mRadius; }

    /// @brief Установить новый радиус окружности.
    /// @param radius Новый радиус.
    void setRadius(double radius) { mRadius = radius; }
};
