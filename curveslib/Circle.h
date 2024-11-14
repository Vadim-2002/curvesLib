#pragma once
#include "Curve.h"
#include <cmath>


/// @class Circle
/// @brief ����� ��� ������������� ���������� �� ���������.
class Circle : public Curve 
{
private:
    /// @brief ������ ����������
    double mRadius;

public:
    /// @brief ����������� �� ���������.
    Circle() : mRadius(0.0) {}

    /// @brief ����������� � ����������.
    /// @param radius ������ ����������.
    Circle(double radius) : mRadius(radius) {}

    /// @brief ����������� �����������.
    /// @param other ������ ������ `Circle` ��� �����������.
    Circle(const Circle& other) : mRadius(other.mRadius) {}

    /// @brief ���������� ���������� ����� �� ����������.
    /// @param t �������� ��� ���������� ����� (�������).
    /// @return ������ ��������� {x, y, z}.
    std::array<double, 3> point(double t) const override { return { mRadius * cos(t), mRadius * sin(t), 0 }; }

    /// @brief ���������� ������ ����������� ������ ����������.
    /// @param t �������� ��� ���������� ����������� (�������).
    /// @return ������ ����������� {dx/dt, dy/dt, dz/dt}.
    std::array<double, 3> derivative(double t) const override { return { -mRadius * sin(t), mRadius * cos(t), 0 }; }

    /// @brief �������� ������ ����������.
    /// @return ������ ����������.
    double getRadius() const { return mRadius; }

    /// @brief ���������� ����� ������ ����������.
    /// @param radius ����� ������.
    void setRadius(double radius) { mRadius = radius; }
};
