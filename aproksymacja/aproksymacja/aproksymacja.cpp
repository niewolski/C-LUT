#include <iostream>
#include <vector>
#include <utility> // dla std::pair

//definicja szablonu struktury Punkt2d
template<typename T>
struct Punkt2d {
    T x;
    T y;

    //dodalem konstruktor do struktury Punkt2d, aby umozliwic przekazywanie argumentow x i y przy tworzeniu obiektow
    Punkt2d(T x_value, T y_value) : x(x_value), y(y_value) {}
};

//metoda najmniejszych kwadratow: y = a_0 + a_1 * x
template<typename T>
std::pair<float, float> MetodaNajmniejszychKwadratow(const std::vector<Punkt2d<T>>& punkty) {
    float n = static_cast<float>(punkty.size());
    float x = 0.0f;
    float f = 0.0f;
    float fx = 0.0f;
    float x2 = 0.0f;

    for (const auto& punkt : punkty) {
        x += punkt.x;
        f += punkt.y;
        fx += punkt.x * punkt.y;
        x2 += punkt.x * punkt.x;
    }

    float a1 = (n * fx - f * x) / (n * x2 - x * x);
    float a0 = (f - a1 * x) / n;

    return std::pair<float, float>(a0, a1);
}

int main() {
    std::ios::sync_with_stdio(false);

    // Zadanie 5: podany zbior danych
    std::vector<Punkt2d<float>> punkty = {
        Punkt2d<float>(0.f, 4.f),
        Punkt2d<float>(2.f, 2.f),
        Punkt2d<float>(-2.f, 6.f),
        Punkt2d<float>(8.f, 0.f),
        Punkt2d<float>(10.f, 2.f),
        Punkt2d<float>(12.f, 4.f),
        Punkt2d<float>(5.f, -1.f)
    };

    //oblicz wspolczynniki za pomocą MetodaNajmniejszychKwadratow
    auto wspolczynniki = MetodaNajmniejszychKwadratow(punkty);

    //wyswietl wyniki
    std::cout << "Obliczone wspolczynnikow:\n";
    std::cout << "a0 (przeciecie) = " << wspolczynniki.first << "\n";
    std::cout << "a1 (nachylenie) = " << wspolczynniki.second << "\n";

    return 0;
}
