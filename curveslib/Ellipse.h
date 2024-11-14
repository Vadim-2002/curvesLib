#pragma once
#include "Curve.h"
#include <cmath>


/// @class Ellipse
/// @brief ����� ��� ������������� ������� �� ���������.
class Ellipse : public Curve 
{
private:
    /// @brief ������� ����� ��� X
    double mX;
    /// @brief ������� ����� ��� Y
    double mY;

public:
    /// @brief ����������� �� ���������.
    Ellipse() : mX(0.0), mY(0.0) {}

    /// @brief ����������� � �����������.
    /// @param x ������� ����� ��� X.
    /// @param y ������� ����� ��� Y.
    Ellipse(double x, double y) : mX(x), mY(y) {}

    /// @brief ����������� �����������.
    /// @param other ������ ������ `Ellipse` ��� �����������.
    Ellipse(const Ellipse& other) : mX(other.mX), mY(other.mY) {}

    /// @brief ���������� ���������� ����� �� �������.
    /// @param t �������� ��� ���������� ����� (�������).
    /// @return ������ ��������� {x, y, z}.
    std::array<double, 3> point(double t) const override { return { mX * cos(t), mY * sin(t), 0 }; }

    /// @brief ���������� ������ ����������� ������ �������.
    /// @param t �������� ��� ���������� ����������� (�������).
    /// @return ������ ����������� {dx/dt, dy/dt, dz/dt}.
    std::array<double, 3> derivative(double t) const override { return { -mX * sin(t), mY * cos(t), 0 }; }

    /// @brief �������� �������� ������� X.
    double getX() const { return mX; }

    /// @brief �������� �������� ������� Y.
    double getY() const { return mY; }

    /// @brief ���������� ����� �������� ��� ������� X.
    void setX(double x) { mX = x; }

    /// @brief ���������� ����� �������� ��� ������� Y.
    void setY(double y) { mY = y; }
};
