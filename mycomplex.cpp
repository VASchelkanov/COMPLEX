#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

Complex::Complex(double aRe, double aIm) {                         // ����������� ������ Complex,
    Re = aRe;                                                      // �������������� �������������� � ������ �����
    Im = aIm;
}

Complex ::  Complex(const Complex& aRval) {                        // ����������� �����������, ������� �����
    Re = aRval.Re;                                                 // ������ Complex �� ������ �������������
    Im = aRval.Im;
}

Complex::~Complex() {                                              // ���������� ������ Complex, �������� �������������� � ������ �����
    Re = 0.0;
    Im = 0.0;
}

void Complex::Set(double aRe,double aIm) {                         // ����� ��� ��������� �������� �������������� � ������ ������
    Re = aRe;
    Im = aIm;
}

Complex::operator double() {                                       // �������� ���������� � ���� double,
                                                                   // ���������� ������ ������������ �����
    return abs();
}

double Complex::abs() {                                            // ����� ��� ���������� ������ ������������ �����
    return sqrt(Re * Re + Im * Im);
}

Complex Complex::operator+(const Complex& aRval) {                 // ������ ������� ��� ����������� ������
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

Complex Complex::operator-(const Complex& aRval) {
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

Complex Complex::operator+(const double& aRval) {
    Complex result;
    result.Re = Re + aRval;
    result.Im = Im;
    return result;
}

Complex Complex::operator-(const double& aRval) {
    Complex Result(*this);
    Result.Re = Re - aRval;
    return Result;
}

Complex Complex::operator*(const Complex& aRval) {
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

Complex Complex::operator*(const double& aRval) {
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}

Complex Complex::operator/(const double& aRval) {
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

Complex& Complex::operator+=(const Complex& aRval) {
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

Complex& Complex::operator-=(const Complex& aRval) {
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

Complex& Complex::operator*=(const Complex& aRval) {
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

Complex& Complex::operator+=(const double& aRval) {
    Re += aRval;
    return *this;
}

Complex& Complex::operator-=(const double& aRval) {
    Re -= aRval;
    return *this;
}

Complex& Complex::operator*=(const double& aRval) {
    Re *= aRval;
    Im *= aRval;
    return *this;
}

Complex& Complex::operator/=(const double& aRval) {
    Re /= aRval;
    Im /= aRval;
    return *this;
}

Complex& Complex::operator=(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

Complex& Complex::operator=(const double& aRval) {
    Re = aRval;
    Im = 0.0;
    return *this;
}

istream& operator>>(istream& stream, Complex& a) {
    char tmp[256];
    stream >> a.Re >> a.Im >> tmp;
    return stream;
}

ostream& operator<<(ostream& stream, Complex& a) {
    stream << a.Re;
    if (!(a.Im < 0)) stream << '+';
    stream << a.Im << 'i';
    return stream;
}

Complex operator+(const double& aRval, const Complex& aRval) {
    Complex Result;
    Result.Re= aLval+aRval.Re;
    Result. Im=  aRval.Im;
    return Result;
}

Complex operator-(const double& aRval, const Complex& aRval) {
    Complex Result;
    Result.Re = aRval - aRval.Re;
    Result.Im = -aRval.Im;
    return Result;
}

Complex operator*(const double& aRval, const Complex& a) {
    Complex r;
    r.Re =aRval * a.Re;
    r.Im =aRval * a.Im;
    return r;
}
                                                                   // ����� ������� ��� ����������� ������
