#ifndef PRAV_PIRAMIDA_H
#define PRAV_PIRAMIDA_H

#include "piramida.h"
#include <cmath>
#include <iostream>

class Prav_Piramida : public Piramida {
public:
    Prav_Piramida() : Piramida() {}

    Prav_Piramida(float edge, float baseSide) {
        edge1 = edge2 = edge3 = edge;
        base1 = base2 = base3 = baseSide;
    }

    void changeEdge(float value) {
        edge1 = edge2 = edge3 = value;
    }

    void changeBaseSide(float value) {
        base1 = base2 = base3 = value;
    }

    float surfaceArea() const override {
        float baseArea = (sqrt(3) / 4) * base1 * base1;
        float sideHeight = sqrt(edge1 * edge1 - (base1 * base1 / 12));
        float sideArea = (3 * base1 * sideHeight) / 2;
        return baseArea + sideArea;
    }

    float lateralSurfaceArea() const {
        float sideHeight = sqrt(edge1 * edge1 - (base1 * base1 / 12));
        return (3 * base1 * sideHeight) / 2;
    }

    bool exists() const {
        // Проверяем, что ребра и стороны основания положительные и не равны нулю
        if (edge1 <= 0 || base1 <= 0) return false;

        // Поскольку основание правильный треугольник, проверяем только > 0

        // Проверяем, что подкоренное выражение для высоты боковой грани >= 0
        // sideHeight = sqrt(edge1^2 - (base1^2 / 12))
        float underRoot = edge1 * edge1 - (base1 * base1 / 12);
        if (underRoot < 0) return false;

        return true;
    }

    void show() const override {
        getEdges();
        getBase();
        if (exists())
            std::cout << "Правильная пирамида существует." << std::endl;
        else
            std::cout << "Правильная пирамида НЕ существует." << std::endl;
    }
};

#endif
