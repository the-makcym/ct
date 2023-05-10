#pragma once

#include <functional>
#include "globals.h"

using namespace std;


// вид квадратурной формулы
enum class QuadFormula {
    Rect, Trapeze, Simpson, Gauss2, Gauss3, Gauss4,
};

// реализация квадратурной формулы
real quad_formula(function<real(real)> &func, real lb, real rb, QuadFormula formula = QuadFormula::Gauss2);

// разбиение отрезка на +- равные подотрезки для интегрирования указанного порядка
Vector splitting(Array(2) inv, int order);

// итеративный расчет квадратуры
real quadrature(function<real(real)> &func, Vector spltng, QuadFormula formula = QuadFormula::Gauss2);

// рекурсивный расчет квадратуры
real quadrature(function<real(real)> &func, Array(2) inv, int order = 12, QuadFormula formula = QuadFormula::Gauss2);
