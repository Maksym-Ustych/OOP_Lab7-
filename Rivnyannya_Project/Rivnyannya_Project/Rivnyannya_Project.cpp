// Rivnyannya_Project.cpp
#include <iostream>
#include <cmath>
#include <io.h>
#include <fcntl.h>

using namespace std;

// Базовий клас РІВНЯННЯ
class Rivnannya {
protected:
    double a, b, c; // Коефіцієнти
public:
    Rivnannya() : a(0), b(0), c(0) {}
    virtual void VvestyDani() = 0;
    virtual void Rozvyazaty() = 0;
    virtual ~Rivnannya() {}
};

// Похідний клас ЛІНІЙНИХ рівнянь: ax + b = 0
class LinRivnannya : public Rivnannya {
public:
    LinRivnannya(double aa, double bb) { a = aa; b = bb; }
    void VvestyDani() override {
        wcout << L"Рівняння: " << a << L"x + " << b << L" = 0" << endl;
    }
    void Rozvyazaty() override {
        if (a == 0 && b == 0)
            wcout << L"Відповідь: безліч розв’язків (0 = 0)." << endl;
        else if (a == 0)
            wcout << L"Відповідь: розв’язків немає." << endl;
        else {
            double x = -b / a;
            wcout << L"Відповідь: x = " << x << endl;
        }
    }
};

// Похідний клас КВАДРАТНИХ рівнянь: cx^2 + ax + b = 0
class KvadrRivnannya : public Rivnannya {
public:
    KvadrRivnannya(double cc, double aa, double bb) { c = cc; a = aa; b = bb; }
    void VvestyDani() override {
        wcout << L"Рівняння: " << c << L"x^2 + " << a << L"x + " << b << L" = 0" << endl;
    }
    void Rozvyazaty() override {
        if (c == 0) { // Перетворення на лінійне
            LinRivnannya temp(a, b);
            temp.VvestyDani();
            temp.Rozvyazaty();
            return;
        }
        double D = a * a - 4 * c * b;
        wcout << L"Дискримінант D = " << D << endl;
        if (D > 0) {
            double x1 = (-a + sqrt(D)) / (2 * c);
            double x2 = (-a - sqrt(D)) / (2 * c);
            wcout << L"Два розв’язки: x₁ = " << x1 << L", x₂ = " << x2 << endl;
        }
        else if (D == 0) {
            double x = -a / (2 * c);
            wcout << L"Один розв’язок: x = " << x << endl;
        }
        else
            wcout << L"Немає дійсних розв’язків (D < 0)." << endl;
    }
};

int main() {
    // Налаштування консолі на UTF-8
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    wcout << L"=== Програма для розв’язання рівнянь ===\n\n";

    // Лінійні рівняння
    LinRivnannya lin1(2, -4);
    wcout << L"=== Розв'язання лінійного рівняння ===\n";
    lin1.VvestyDani();
    lin1.Rozvyazaty();
    wcout << endl;

    LinRivnannya lin2(0, 0);
    wcout << L"=== Розв'язання лінійного рівняння ===\n";
    lin2.VvestyDani();
    lin2.Rozvyazaty();
    wcout << endl;

    // Квадратні рівняння
    KvadrRivnannya kv1(1, -3, 2); // D > 0
    wcout << L"=== Розв'язання квадратного рівняння ===\n";
    kv1.VvestyDani();
    kv1.Rozvyazaty();
    wcout << endl;

    KvadrRivnannya kv2(0, 0, 0); // Некоректне
    wcout << L"=== Розв'язання квадратного рівняння ===\n";
    kv2.VvestyDani();
    kv2.Rozvyazaty();
    wcout << endl;

    KvadrRivnannya kv3(1, 0, 1); // D < 0
    wcout << L"=== Розв'язання квадратного рівняння ===\n";
    kv3.VvestyDani();
    kv3.Rozvyazaty();
    wcout << endl;

    wcout << L"--- Кінець програми ---\n";
    return 0;
}