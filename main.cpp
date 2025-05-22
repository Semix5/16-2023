#include <iostream>
#include "piramida.h"
#include "prav_piramida.h"
#include "tetradr.h"

using namespace std;

void menuPiramida() {
    Piramida p(2, 3, 4, 5, 6, 7);
    int choice;
    do {
        cout << "\n--- PIRAMIDA ---\n";
        cout << "1. Показать\n";
        cout << "2. Изменить ребро\n";
        cout << "3. Изменить сторону основания\n";
        cout << "4. Площадь поверхности\n";
        cout << "0. Назад\n";
        cout << "Выберите: ";
        cin >> choice;

        switch (choice) {
            case 1:
                p.show();
                break;
            case 2: {
                int n;
                float val;
                cout << "Введите номер ребра (1-3): ";
                cin >> n;
                if (n != 1 && n != 2  && n != 3) break;
                cout << "Новое значение: ";
                cin >> val;
                if (val <= 0) {
                    cout << "Ошибка: значение должно быть положительным.\n";
                } else {
                    p.changeEdge(n, val);
                }
                break;
            }
            case 3: {
                int n;
                float val;
                cout << "Введите номер стороны основания (1-3): ";
                cin >> n;
                if (n != 1 && n != 2  && n != 3) break;
                else{
                cout << "Новое значение: ";}
                cin >> val;
                if (val <= 0) {
                    cout << "Ошибка: значение должно быть положительным.\n";
                } else {
                    p.changeBaseSide(n, val);
                }
                break;
            }
            case 4:
                if (p.exists()) {
                    cout << "Площадь поверхности: " << p.surfaceArea() << endl;
                } else {
                    cout << "Пирамида с такими параметрами не существует.\n";
                }
                break;
        }
    } while (choice != 0);
}

void menuPravPiramida() {
    Prav_Piramida pp(5, 4);
    int choice;
    do {
        cout << "\n--- PRAVILNAYA PIRAMIDA ---\n";
        cout << "1. Показать\n";
        cout << "2. Изменить ребро\n";
        cout << "3. Изменить сторону основания\n";
        cout << "4. Площадь поверхности\n";
        cout << "5. Площадь боковой поверхности\n";
        cout << "0. Назад\n";
        cout << "Выберите: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pp.show();
                break;
            case 2: {
                float val;
                cout << "Новое значение ребра: ";
                cin >> val;
                if (val <= 0) {
                    cout << "Ошибка: значение должно быть положительным.\n";
                } else {
                    pp.changeEdge(val);
                }
                break;
            }
            case 3: {
                float val;
                cout << "Новое значение стороны основания: ";
                cin >> val;
                if (val <= 0) {
                    cout << "Ошибка: значение должно быть положительным.\n";
                } else {
                    pp.changeBaseSide(val);
                }
                break;
            }
            case 4:
                if (pp.exists()) {
                    cout << "Площадь поверхности: " << pp.surfaceArea() << endl;
                } else {
                    cout << "Правильная пирамида с такими параметрами не существует.\n";
                }
                break;
            case 5:
                if (pp.exists()) {
                    cout << "Площадь боковой поверхности: " << pp.lateralSurfaceArea() << endl;
                } else {
                    cout << "Правильная пирамида с такими параметрами не существует.\n";
                }
                break;
        }
    } while (choice != 0);
}

void menuTetradr() {
    Tetradr t(3);
    int choice;
    do {
        cout << "\n--- TETRADR ---\n";
        cout << "1. Показать\n";
        cout << "2. Изменить ребро\n";
        cout << "3. Площадь поверхности\n";
        cout << "4. Площадь боковой поверхности\n";
        cout << "5. Объем\n";
        cout << "0. Назад\n";
        cout << "Выберите: ";
        cin >> choice;

        switch (choice) {
            case 1:
                t.show();
                break;
            case 2: {
                float val;
                cout << "Новое значение ребра: ";
                cin >> val;
                if (val <= 0) {
                    cout << "Ошибка: значение должно быть положительным.\n";
                } else {
                    t.changeEdge(val);
                }
                break;
            }
            case 3:
                if (t.exists()) {
                    cout << "Площадь поверхности: " << t.surfaceArea() << endl;
                } else {
                    cout << "Правильный тетраэдр с такими параметрами не существует.\n";
                }
                break;
            case 4:
                if (t.exists()) {
                    cout << "Площадь боковой поверхности: " << t.lateralSurfaceArea() << endl;
                } else {
                    cout << "Правильный тетраэдр с такими параметрами не существует.\n";
                }
                break;
            case 5:
                if (t.exists()) {
                    cout << "Объем: " << t.volume() << endl;
                } else {
                    cout << "Правильный тетраэдр с такими параметрами не существует.\n";
                }
                break;
        }
    } while (choice != 0);
}

int main() {
    int mainChoice;
    do {
        cout << "\n=== ГЛАВНОЕ МЕНЮ ===\n";
        cout << "1. Обычная пирамида\n";
        cout << "2. Правильная пирамида\n";
        cout << "3. Тетраэдр\n";
        cout << "0. Выход\n";
        cout << "Выберите: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                menuPiramida();
                break;
            case 2:
                menuPravPiramida();
                break;
            case 3:
                menuTetradr();
                break;
            case 0:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (mainChoice != 0);

    return 0;
}
