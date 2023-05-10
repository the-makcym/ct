#pragma GCC optimize("O3")

#include <vector>
#include <string>
#include "radon.h"
#include "area_generator.h"
#include "utilities.h"

using namespace std;


int main() {
    // конфигурация из файла config.env
    Config config = Config();

    // название теста для файлов .dat, .jpg вида `_shepplogan_400_628`
    string suffix("_shepplogan_"), filename;
    suffix = (suffix + to_string(config.n_rho)).append("_") + to_string(config.n_phi);

    // создание области
    auto area = area_head();
    Matrix area_giv = area.image(config);
    filename = string("area_giv") + suffix;
    // запись в файл `area_giv{suffix}` значений области и ее изображения
    make_jpg_dat(filename, area_giv);

    // расчет преобразования Радона в заданной области
    Matrix radon_im = radon(area, config);
    filename = string("radon_im") + suffix;
    // запись в файл `radon_im{suffix}` значений преобразования Радона и ее его изображения
    make_jpg_dat(filename, radon_im);

    // расчет обращения преобразования Радона
    Matrix area_obt = inv_radon(radon_im, config);
    filename = string("area_obt") + suffix;
    // запись в файл `area_obt{suffix}` значений обращения преобразования Радона и восстановленного изображения
    make_jpg_dat(filename, area_obt);

    filename = string("sd") + suffix;
    // расчет среднеквадратичного отклонения и запись в файл `sd{suffix}`
    real sd = standard_deviation(filename, area_giv, area_obt);

    return 0;
}
