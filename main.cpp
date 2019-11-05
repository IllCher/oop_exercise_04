
#include <iostream>
#include <tuple>
#include "src/templates.h"
int main() {
        std::string command;
        while (std::cin >> command) {
            try {
            if (command == "tri") {
                TTriangle<int> triangle(std::cin);
                std::cout << "int triangle\n";
                std::cout << "coors: ";
                print(triangle);
                std::cout << "center: " << center(triangle) << "\n";
                std::cout << "area: " << area(triangle) << "\n";
            } else if (command == "trd") {
                using vertex = std::pair<double, double>;
                using std::make_pair;
                vertex A, B, C;
                std::cin >> A >> B >> C;
                std::tuple<vertex, vertex, vertex> tTriangle(make_pair(A.first, A.second), make_pair(B.first, B.second),
                                                             make_pair(C.first, C.second));
                TTriangle<double> triangle(A.first, A.second, B.first, B.second, C.first, C.second);
                std::cout << "double triangle\n";
                std::cout << "coors: ";
                print(triangle);
                std::cout << "center: " << center(triangle) << "\n";
                std::cout << "area: " << area(tTriangle) << "\n";
            } else if (command == "oi") {
                using vertex = std::pair<int, int>;
                using std::make_pair;
                vertex A, B, C, D, E, F, G, H;
                std::cin >> A >> B >> C >> D >> E >> F >> G >> H;
                std::tuple<vertex, vertex, vertex, vertex, vertex, vertex, vertex, vertex> tOctagon(
                        make_pair(A.first, A.second), make_pair(B.first, B.second), make_pair(C.first, C.second),
                        make_pair(D.first, D.second), make_pair(E.first, E.second), make_pair(F.first, F.second),
                        make_pair(G.first, G.second), make_pair(H.first, H.second));
                TOctagon<int> octagon(A.first, A.second, B.first, B.second, C.first, C.second, D.first, D.second,
                                      E.first, E.second, F.first, F.second, G.first, G.second, H.first, H.second);
                std::cout << "int octagon\n";
                std::cout << "coors: ";
                print(octagon);
                std::cout << "center: " << center(octagon) << "\n";
                std::cout << "area: " << area(tOctagon) << "\n";
            } else if (command == "od") {
                TOctagon<double> octagon(std::cin);
                std::cout << "double octagon\n";
                std::cout << "coors: ";
                print(octagon);
                std::cout << "center: " << center(octagon) << "\n";
                std::cout << "area: " << area(octagon) << "\n";
            } else if (command == "si") {
                using vertex = std::pair<int, int>;
                using std::make_pair;
                vertex A, C;
                std::cin >> A >> C;
                std::tuple<vertex, vertex> tSquare(make_pair(A.first, A.second), make_pair(C.first, C.second));
                TSquare<int> square(A.first, A.second, C.first, C.second);
                std::cout << "int square\n";
                std::cout << "coors: ";
                print(square);
                std::cout << "center: " << center(square) << "\n";
                std::cout << "area: " << area(tSquare) << "\n";
            } else if (command == "sd") {
                TSquare<double> square(std::cin);
                std::cout << "double square\n";
                std::cout << "coors: ";
                print(square);
                std::cout << "center: " << center(square) << "\n";
                std::cout << "area: " << area(square) << "\n";
            } else {
                std::cout << "Wrong command\n";
            }
            } catch(std::logic_error e) {
                std::cout << e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
    return 0;
}