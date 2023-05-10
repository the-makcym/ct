#pragma once

#include "globals.h"
#include "geometry.h"

using namespace std;


// расчет преобразования Радона в общем случае
Matrix radon(Area &area, Config &config);

// расчет преобразования Радона в случае константы
Matrix radon_const(Area &area, Config &config);

// свертка функции с фильтром высоких частот
Matrix convolution(Matrix &radon_im, Config &config);

// обратная проекция
real backprojection(Pnt &pnt, Matrix &conv, Config &config);

// обращение преобразования Радона
Matrix inv_radon(Matrix &radon_im, Config &config);
