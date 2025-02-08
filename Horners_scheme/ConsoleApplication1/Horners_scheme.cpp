#include <iostream>

int main()
{
    //wprowadzenie danych
    int stopien;
    std::cout << "Podaj stopien wielomianu: ";
    std::cin >> stopien;

    //dynamiczna alokacja pamięci dla wspolczynnikow wielomianu
    float* wielomian = new float[stopien + 1];
    for (int i = 0; i <= stopien; ++i) {
        std::cout << "Podaj wspolczynnik przy x^" << (stopien - i) << ": ";
        std::cin >> wielomian[i];
    }

    float p;
    std::cout << "Podaj wartosc p (x): ";
    std::cin >> p;

    //schemat Hornera
    float wynik = wielomian[0];
    for (int i = 1; i <= stopien; ++i)
        wynik = wynik * p + wielomian[i];

    std::cout << "Wartosc wielomianu W(x) w punkcie x = " << p << " wynosi " << wynik << "\n";

    //zwolnienie pamięci
    delete[] wielomian;

    return 0;
}
