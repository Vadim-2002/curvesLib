#pragma once
#include <array>


/// @class Curve
/// @brief јбстрактный класс дл€ представлени€ 3D-кривых.
class Curve 
{
public:
    virtual ~Curve() = default;

    /// @brief ¬озвращает координаты точки на кривой в зависимости от параметра t.
    /// @param t ѕараметр дл€ вычислени€ точки (радианы).
    /// @return ћассив координат {x, y, z}.
    virtual std::array<double, 3> point(double t) const = 0;

    /// @brief ¬озвращает первый производный вектор на кривой в зависимости от параметра t.
    /// @param t ѕараметр дл€ вычислени€ производной (радианы).
    /// @return ћассив производных {dx/dt, dy/dt, dz/dt}.
    virtual std::array<double, 3> derivative(double t) const = 0;
};
