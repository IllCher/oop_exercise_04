#include <iostream>
#include <tuple>
#include "src/templates.h"
int main() {
        std::string command;
        while (std::cin >> command) {
            try {
            if (command == "tri") {
                using vertex = std::pair<int, int>;
                using std::make_pair;
                vertex A, B, C;
                std::cin >> A >> B >> C;
                std::tuple<vertex, vertex, vertex> triangle(make_pair(A.first, A.second), make_pair(B.first, B.second), make_pair(C.first, C.second));
                std::cout << "int triangle\n";
                std::cout << "coors: ";
                print(triangle);
                std::cout << "\n";
                std::cout << "center: " << center(triangle) << "\n";
                std::cout << "area: " << area(triangle) << "\n";
            } else if (command == "trd") {
                using vertex = std::pair<double, double>;
                using std::make_pair;
                vertex A, B, C;
                std::cin >> A >> B >> C;
                std::tuple<vertex, vertex, vertex> tTriangle(make_pair(A.first, A.second), make_pair(B.first, B.second), make_pair(C.first, C.second));
                std::cout << "double triangle\n";
                std::cout << "coors: ";
                print(tTriangle);
                std::cout << "\n";
                std::cout << "center: " << center(tTriangle) << "\n";
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
                std::cout << "int octagon\n";
                std::cout << "coors: ";
                print(tOctagon);
                std::cout << "\n";
                std::cout << "center: " << center(tOctagon) << "\n";
                std::cout << "area: " << area(tOctagon) << "\n";
            } else if (command == "od") {
                using vertex = std::pair<double, double>;
                using std::make_pair;
                vertex A, B, C, D, E, F, G, H;
                std::cin >> A >> B >> C >> D >> E >> F >> G >> H;
                std::tuple<vertex, vertex, vertex, vertex, vertex, vertex, vertex, vertex> tOctagon(
                        make_pair(A.first, A.second), make_pair(B.first, B.second), make_pair(C.first, C.second),
                        make_pair(D.first, D.second), make_pair(E.first, E.second), make_pair(F.first, F.second),
                        make_pair(G.first, G.second), make_pair(H.first, H.second));
                std::cout << "double octagon\n";
                std::cout << "coors: ";
                print(tOctagon);
                std::cout << "\n";
                std::cout << "center: " << center(tOctagon) << "\n";
                std::cout << "area: " << area(tOctagon) << "\n";
            } else if (command == "si") {
                using vertex = std::pair<int, int>;
                using std::make_pair;
                vertex A, B, C, D;
                std::cin >> A >> B >> C >> D;
                std::tuple<vertex, vertex, vertex, vertex> tSquare(make_pair(A.first, A.second), make_pair(B.first, B.second), make_pair(C.first, C.second), make_pair(D.first, D.second));
                std::cout << "int square\n";
                std::cout << "coors: ";
                print(tSquare);
                std::cout << "\n";
                std::cout << "center: " << center(tSquare) << "\n";
                std::cout << "area: " << area(tSquare) << "\n";
            } else if (command == "sd") {
                using vertex = std::pair<double, double>;
                using std::make_pair;
                vertex A, B, C, D;
                std::cin >> A >> B >> C >> D;
                std::tuple<vertex, vertex, vertex, vertex> tSquare(make_pair(A.first, A.second), make_pair(B.first, B.second), make_pair(C.first, C.second), make_pair(D.first, D.second));
                //tSquare.is_square();
                std::cout << "double square\n";
                std::cout << "coors: ";
                print(tSquare);
                std::cout << "\n";
                std::cout << "center: " << center(tSquare) << "\n";
                std::cout << "area: " << area(tSquare) << "\n";
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