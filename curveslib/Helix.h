#pragma once
#include "Curve.h"
#include <cmath>


/// @class Helix
/// @brief ����� ��� ������������� 3D-�������.
class Helix : public Curve 
{
private:
    /// @brief ������ �������
    double mRadius;
    /// @brief ��� �������
    double mStep;

public:
    /// @brief ����������� �� ���������.
    Helix() : mRadius(0.0), mStep(0.0) {}

    /// @brief ����������� � �����������.
    /// @param radius ������ �������.
    /// @param step ��� �������.
    Helix(double radius, double step) : mRadius(radius), mStep(step) {}

    /// @brief ����������� �����������.
    /// @param other ������ ������ `Helix` ��� �����������.
    Helix(const Helix& other) : mRadius(other.mRadius), mStep(other.mStep) {}

    /// @brief ���������� ���������� ����� �� �������.
    /// @param t �������� ��� ���������� ����� (�������).
    /// @return ������ ��������� {x, y, z}.
    std::array<double, 3> point(double t) const override { return { mRadius * cos(t), mRadius * sin(t), mStep * t }; }

    /// @brief ���������� ������ ����������� ������ �������.
    /// @param t �������� ��� ���������� ����������� (�������).
    /// @return ������ ����������� {dx/dt, dy/dt, dz/dt}.
    std::array<double, 3> derivative(double t) const override { return { -mRadius * sin(t), mRadius * cos(t), mStep }; }

    /// @brief �������� ������ �������.
    double getRadius() const { return mRadius; }

    /// @brief �������� ��� �������.
    double getStep() const { return mStep; }

    /// @brief ���������� ������ �������.
    void setRadius(double radius) { mRadius = radius; }

    /// @brief ���������� ��� �������.
    void setStep(double step) { mStep = step; }
};
