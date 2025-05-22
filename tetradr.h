#ifndef TETRADR_H
#define TETRADR_H

#include "piramida.h"
#include <cmath>
#include <iostream>

class Tetradr : public Piramida {
public:
    Tetradr() : Piramida() {}

    Tetradr(float side) {
        edge1 = edge2 = edge3 = base1 = base2 = base3 = side;
    }

    void changeEdge(float value) {
        edge1 = edge2 = edge3 = base1 = base2 = base3 = value;
    }

    float surfaceArea() const override {
        return sqrt(3) * base1 * base1;
    }

    float lateralSurfaceArea() const {
        return surfaceArea();
    }

    float volume() const {
        return pow(base1, 3) / (6 * sqrt(2));
    }

    bool exists() const {
        // Проверяем, что сторона положительна и не равна нулю
        if (base1 <= 0) return false;

        // Проверяем, что все ребра равны стороне основания
        if (!(edge1 == base1 && edge2 == base1 && edge3 == base1)) return false;

        return true;
    }

    void show() const override {
        getEdges();
        getBase();
        if (exists())
            std::cout << "Правильный тетраэдр существует." << std::endl;
        else
            std::cout << "Правильный тетраэдр НЕ существует." << std::endl;
    }
};

#endif
