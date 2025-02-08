#include <iostream>
#include <fstream>
#include <array>

//struktura Point3D reprezentująca punkt w przestrzeni 3D
template <typename T>
struct Point3D
{
    T x, y, z;

    //konstruktor domyślny
    Point3D() : x(T(0)), y(T(0)), z(T(0)) {}

    //konstruktor z trzema parametrami
    Point3D(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}

    //operator dodawania punktów
    Point3D<T> operator+(const Point3D<T>& rhs) const
    {
        return Point3D<T>(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    //operator przypisania
    Point3D<T>& operator=(const Point3D<T>& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        return *this;
    }

    //operator mnożenia przez skalar
    Point3D<T> operator*(T scalar) const
    {
        return Point3D<T>(x * scalar, y * scalar, z * scalar);
    }
};

//struktura reprezentująca węzeł interpolacji
struct Node
{
    Point3D<float> point;
    float value;

    Node() : point(), value(0.0f) {}
    Node(const Point3D<float>& p, float val) : point(p), value(val) {}
};

//funkcja obliczajaca wartosc interpolacji Lagrange'a
Point3D<float> interpolateLagrange(const std::array<Node, 4>& nodes, float t)
{
    Point3D<float> result;

    for (int i = 0; i < nodes.size(); ++i)
    {
        float Li = 1.0f;
        for (int j = 0; j < nodes.size(); ++j)
        {
            if (i != j)
            {
                Li *= (t - nodes[j].value) / (nodes[i].value - nodes[j].value);
            }
        }
        result = result + nodes[i].point * Li;
    }

    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);

    //definicja wezlow interpolacji
    std::array<Node, 4> nodes = {
        Node(Point3D<float>(-6, -8, 3), 0.0f),
        Node(Point3D<float>(-5, -3, 3), 1.0f),
        Node(Point3D<float>(6, 3, -2), 2.0f),
        Node(Point3D<float>(2, 2, 6), 3.0f) };

    //tablica wartosci t do obliczen
    std::array<float, 7> t_values = { 0.0f, 0.5f, 1.5f, 2.25f, 3.0f, 3.5f, 4.0f };

    //plik wyjsciowy
    std::ofstream output("trajektoria.txt");

    if (!output.is_open())
    {
        std::cerr << "Blad otwarcia pliku trajektoria.txt!" << std::endl;
        return 1;
    }

    // Interpolacja dla każdej wartości t
    for (float t : t_values)
    {
        Point3D<float> result = interpolateLagrange(nodes, t);
        output << "[" << result.x << ", " << result.y << ", " << result.z << "]\n";
    }

    output.close();

    std::cout << "Wyniki interpolacji zostaly zapisane do pliku trajektoria.txt.\n";

    return 0;
}
