#ifndef PIRAMIDA_H
#define PIRAMIDA_H

#include <iostream>
using namespace std;

class Piramida {
protected:
    float edge1, edge2, edge3;  // рёбра от вершины к основанию
    float base1, base2, base3;  // стороны основания (треугольника)

public:
    Piramida() : edge1(1), edge2(1), edge3(1), base1(1), base2(1), base3(1) {}

    Piramida(float e1, float e2, float e3, float b1, float b2, float b3)
        : edge1(e1), edge2(e2), edge3(e3), base1(b1), base2(b2), base3(b3) {}

    ~Piramida() {}

    void setEdges(float e1, float e2, float e3) {
        edge1 = e1; edge2 = e2; edge3 = e3;
    }

    void setBase(float b1, float b2, float b3) {
        base1 = b1; base2 = b2; base3 = b3;
    }

    void getEdges() const {
        cout << "Edges: " << edge1 << ", " << edge2 << ", " << edge3 << endl;
    }

    void getBase() const {
        cout << "Base sides: " << base1 << ", " << base2 << ", " << base3 << endl;
    }

    virtual void show() const {
        getEdges();
        getBase();
        if (exists())
            cout << "Pyramid exists." << endl;
        else
            cout << "Pyramid does NOT exist." << endl;
    }

    virtual void changeEdge(int num, float value) {
        if (num == 1) edge1 = value;
        else if (num == 2) edge2 = value;
        else if (num == 3) edge3 = value;
    }

    virtual void changeBaseSide(int num, float value) {
        if (num == 1) base1 = value;
        else if (num == 2) base2 = value;
        else if (num == 3) base3 = value;
    }

    virtual float surfaceArea() const {
        return base1 + base2 + base3 + edge1 + edge2 + edge3;
    }

    // Проверка существования пирамиды и отсутствие нулевых сторон/рёбер
    bool exists() const {
        // Проверка, что все стороны и рёбра положительны и не равны нулю
        if (edge1 <= 0 || edge2 <= 0 || edge3 <= 0) return false;
        if (base1 <= 0 || base2 <= 0 || base3 <= 0) return false;

        // Проверка, что основание — треугольник (сумма любых двух сторон > третьей)
        if (base1 + base2 <= base3) return false;
        if (base2 + base3 <= base1) return false;
        if (base3 + base1 <= base2) return false;

        return true;
    }
};

#endif
