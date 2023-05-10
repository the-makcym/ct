#pragma once

#include "globals.h"
#include "geometry.h"

using namespace std;


// Область с константой внутри
Area area_const() {
    Area area = Area(CONST_ATTEN(1));
    return area;
}

// Фантом Шеппа-Логана
Area area_head() {
    vector<Ellipse> ellipses = {
            Ellipse(Pnt(0, 0), 0.69, 0.92, 0, CONST_ATTEN(1.65)),
            Ellipse(Pnt(0, -0.0184), 0.6624, 0.874, 0, CONST_ATTEN(-1.25)),
            Ellipse(Pnt(0.22, 0), 0.11, 0.31, -PI / 10, CONST_ATTEN(-0.35)),
            Ellipse(Pnt(-0.22, 0), 0.16, 0.41, PI / 10, CONST_ATTEN(-0.35)),
            Ellipse(Pnt(0, 0.35), 0.21, 0.25, 0, CONST_ATTEN(0.15)),
            Ellipse(Pnt(0, 0.1), 0.046, 0.046, 0, CONST_ATTEN(0.15)),
            Ellipse(Pnt(0, -0.1), 0.046, 0.046, 0, CONST_ATTEN(0.15)),
            Ellipse(Pnt(-0.08, -0.605), 0.046, 0.023, 0, CONST_ATTEN(0.15)),
            Ellipse(Pnt(0, -0.605), 0.023, 0.023, 0, CONST_ATTEN(0.15)),
            Ellipse(Pnt(0.06, -0.605), 0.023, 0.046, 0, CONST_ATTEN(0.15)),
    };
    Area area = Area(CONST_ATTEN(0), ellipses);
    return area;
}

// Область с одним треугольник и одним эллипс
Area area_0() {
    vector<Ellipse> ellipses = {Ellipse(Pnt(0.25, -0.25), 0.5, 0.25, PI / 4, INV_RADIUS_ATTEN(255))};
    array<Pnt, 3> vertices = {Pnt(-0.5, 0), Pnt(0, 0.5), Pnt(-0.5, -0.5)};
    vector<Polygon> polygons = {Polygon(vertices, RADIUS_ATTEN(200))};
    Area area = Area(CONST_ATTEN(100), ellipses, polygons);
    return area;
}

// Область с одним эллипсом
Area area_1() {
    vector<Ellipse> ellipses = {Ellipse(Pnt(0.25, -0.25), 0.5, 0.25, PI / 4, RADIUS_ATTEN(255))};
    Area area = Area(CONST_ATTEN(100), ellipses);
    return area;
}
