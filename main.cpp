#include <iostream>
#include <tuple>
#include "triangle.h"
#include "templates.h"
int main() {
    triangle<double> t(std::cin);
    std::cout << area(t) << std::endl;
    std::tuple<vertex<double>, vertex<double>, vertex,double>>
    fake_triangle{{0,0}, {0,1}, {1,1}};
    std::cout << area(fake_triangle) << std::endl;
    return 0;
}