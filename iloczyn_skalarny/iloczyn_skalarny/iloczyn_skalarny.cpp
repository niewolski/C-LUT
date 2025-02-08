#include <iostream>
#include <cmath>
#include <functional>

// Funkcja do obliczania iloczynu skalarnego
double iloczynSkalarny(std::function<double(double)> f, std::function<double(double)> g, int m) {
    double a = -1.0;
    double b = 1.0;
    double h = (b - a) / m;
    double sum = 0.0;

    for (int i = 0; i < m; ++i) {
        double x0 = a + i * h;
        double x1 = a + (i + 1) * h;
        sum += (f(x0) * g(x0) + f(x1) * g(x1)) * h / 2.0;
    }

    return sum;
}

int main() {
    // Definiowanie funkcji P3 i P4
    auto P3 = [](double x) { return 35 * pow(x, 3) - 30 * x; };
    auto P4 = [](double x) { return 63 * pow(x, 5) - 70 * pow(x, 3) + 15 * x; };

    // Obliczanie iloczynu skalarnego dla m = 25
    int m = 25;
    double wynik = iloczynSkalarny(P3, P4, m);

    // Wyświetlanie wyniku
    std::cout << "Iloczyn skalarny dla m = " << m << " wynosi: " << wynik << std::endl;

    return 0;
}