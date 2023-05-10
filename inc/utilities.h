#pragma once

#include <vector>
#include <string>
#include "globals.h"

using namespace std;


// Класс конфигурационной информации
class Config {
public:
    int n_rho, n_phi, n_x, n_y;
    bool intersections;

    Config();
};

// расчет среднеквадратичного отклонения и запись его в файл
real standard_deviation(string &filename, Matrix &exact, Matrix &model);

// запись данной матрицы в файл .dat и ее визуализации в .jpg
void make_jpg_dat(string &filename, Matrix &data);
