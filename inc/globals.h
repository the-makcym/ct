#pragma once

#include <limits>

// для быстрой замены точности значений с плавающей точкой
#define real double

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923

// название файла с конфигурацией
#define CONFIG_FILE "config.env"

// для сравнения чисел с плавающей точкой
#define EPSILON std::numeric_limits<real>::epsilon()
#define real_eq(lhs, rhs) (std::abs(lhs - rhs) < EPSILON)

// статический массив чисел с плавающей точкой
#define Array(len) std::array<real, len>
// динамический массив чисел с плавающей точкой
#define Vector std::vector<real>
// динамическая матрица чисел с плавающей точкой
#define Matrix std::vector<std::vector<real>>
