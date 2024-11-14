#pragma once
#include "Curve.h"
#include <cmath>


/// @class Helix
/// @brief Класс для представления 3D-спирали.
class Helix : public Curve 
{
private:
    /// @brief Радиус спирали
    double mRadius;
    /// @brief Шаг спирали
    double mStep;

public:
    /// @brief Конструктор по умолчанию.
    Helix() : mRadius(0.0), mStep(0.0) {}

    /// @brief Конструктор с параметрами.
    /// @param radius Радиус спирали.
    /// @param step Шаг спирали.
    Helix(double radius, double step) : mRadius(radius), mStep(step) {}

    /// @brief Конструктор копирования.
    /// @param other Другой объект `Helix` для копирования.
    Helix(const Helix& other) : mRadius(other.mRadius), mStep(other.mStep) {}

    /// @brief Возвращает координаты точки на спирали.
    /// @param t Параметр для вычисления точки (радианы).
    /// @return Массив координат {x, y, z}.
    std::array<double, 3> point(double t) const override { return { mRadius * cos(t), mRadius * sin(t), mStep * t }; }

    /// @brief Возвращает первый производный вектор спирали.
    /// @param t Параметр для вычисления производной (радианы).
    /// @return Массив производных {dx/dt, dy/dt, dz/dt}.
    std::array<double, 3> derivative(double t) const override { return { -mRadius * sin(t), mRadius * cos(t), mStep }; }

    /// @brief Получить радиус спирали.
    double getRadius() const { return mRadius; }

    /// @brief Получить шаг спирали.
    double getStep() const { return mStep; }

    /// @brief Установить радиус спирали.
    void setRadius(double radius) { mRadius = radius; }

    /// @brief Установить шаг спирали.
    void setStep(double step) { mStep = step; }
};
