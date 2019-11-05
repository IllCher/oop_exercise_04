
#include <iostream>
#include <tuple>
#include "src/templates.h"
int main() {
    std::string command;
    while (std::cin >> command) {
        if (command == "tri") {
            int x1, y1, x2, y2, x3, y3;
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            TTriangle<int> triangle(x1, y1, x2, y2, x3, y3);
            std::cout << "int triangle\n";
            std::cout << "coors: ";
            print(triangle);
            std::cout << "center: " << center(triangle) << "\n";
            std::cout << "area: " << area(triangle) << "\n";
        } else if (command == "trd") {
            double x1, y1, x2, y2, x3, y3;
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            using vertex = std::pair<double, double>;
            using std::make_pair;
            std::tuple<vertex, vertex, vertex> tTriangle(make_pair(x1, y1),make_pair(x2, y2), make_pair(x3,y3));
            TTriangle<double> triangle(x1, y1, x2, y2, x3, y3);
            std::cout << "double triangle\n";
            std::cout << "coors: ";
            print(triangle);
            std::cout << "center: " << center(triangle) << "\n";
            std::cout << "area: " << area(tTriangle) << "\n";
        } else if (command == "oi") {
            int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8;
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6 >> x7 >> y7 >> x8 >> y8 ;
            using vertex = std::pair<int, int>;
            using std::make_pair;
            std::tuple<vertex, vertex, vertex, vertex, vertex, vertex, vertex, vertex> tOctagon(make_pair(x1, y1), make_pair(x2, y2), make_pair(x3, y3), make_pair(x4, y4), make_pair(x5, y5), make_pair(x6, y6), make_pair(x7, y7), make_pair(x8, y8));
            TOctagon<int> octagon(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8);
            std::cout << "int octagon\n";
            std::cout << "coors: ";
            print(octagon);
            std::cout << "center: " << center(octagon) << "\n";
            std::cout << "area: " << area(tOctagon) << "\n";
        } else if (command == "od") {
            double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8;
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6 >> x7 >> y7 >> x8 >> y8 ;
            TOctagon<double> octagon(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8);
            std::cout << "double octagon\n";
            std::cout << "coors: ";
            print(octagon);
            std::cout << "center: " << center(octagon) << "\n";
            std::cout << "area: " << area(octagon) << "\n";
        } else if (command == "si") {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            using vertex = std::pair<int, int>;
            using std::make_pair;
            std::tuple<vertex, vertex> tSquare(make_pair(x1, y1), make_pair(x2, y2));
            TSquare<int> square(x1, y1, x2, y2);
            std::cout << "int square\n";
            std::cout << "coors: ";
            print(square);
            std::cout << "center: " << center(square) << "\n";
            std::cout << "area: " << area(tSquare) << "\n";
        } else if (command == "sd") {
            double x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            TSquare<double> square(x1, y1, x2, y2);
            std::cout << "double square\n";
            std::cout << "coors: ";
            print(square);
            std::cout << "center: " << center(square) << "\n";
            std::cout << "area: " << area(square) << "\n";
        } else {
            std::cout << "Wrong command\n";
        }
    }
    return 0;
}