#pragma once
#include <array>


/// @class Curve
/// @brief ����������� ����� ��� ������������� 3D-������.
class Curve 
{
public:
    virtual ~Curve() = default;

    /// @brief ���������� ���������� ����� �� ������ � ����������� �� ��������� t.
    /// @param t �������� ��� ���������� ����� (�������).
    /// @return ������ ��������� {x, y, z}.
    virtual std::array<double, 3> point(double t) const = 0;

    /// @brief ���������� ������ ����������� ������ �� ������ � ����������� �� ��������� t.
    /// @param t �������� ��� ���������� ����������� (�������).
    /// @return ������ ����������� {dx/dt, dy/dt, dz/dt}.
    virtual std::array<double, 3> derivative(double t) const = 0;
};
