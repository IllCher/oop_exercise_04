#ifndef TEMPLATES_H_
#define TEMPLATES_H_
#include <utility>
#include <type_traits>
#include <tuple>
#include <cmath>
#include <typeinfo>
#include "triangle.h"
#include "octagon.h"
#include "square.h"
#include "vertex.h"
template<class T>
struct is_vertex : std::false_type {};

template<class T>
struct is_vertex<std::pair<T,T>> : std::true_type {};

template<class T>
struct is_figurelike_tuple : std::false_type {};

template<class Head, class... Tail>
struct is_figurelike_tuple<std::tuple<Head, Tail...>> :
        std::conjunction<is_vertex<Head>,
                std::is_same<Head, Tail>...> {};

template<class Type, size_t SIZE>
struct is_figurelike_tuple<std::array<Type, SIZE>> :
        is_vertex<Type> {};

template<class T>
inline constexpr bool is_figurelike_tuple_v =
        is_figurelike_tuple<T>::value;

template<class T, class = void>
struct has_print_method : std::false_type {};

template<class T>
struct has_print_method<T,
        std::void_t<decltype(std::declval<const T>().print())>> :
        std::true_type {};

template<class T>
inline constexpr bool has_print_method_v = has_print_method<T>::value;

template<class T>
std::enable_if_t<has_print_method_v<T>, void>
print(const T& figure) {
    figure.print();
}

template<size_t ID, class T>
void single_print(const T& t) {
    std::cout << std::get<ID>(t);
    return;
}

template<size_t ID, class T>
void Recursiveprint(const T& t) {
    if constexpr (ID < std::tuple_size_v<T>){
        single_print<ID>(t);
        Recursiveprint<ID+1>(t);
        return ;
    }
    return;
}

template<class T>
std::enable_if_t<is_figurelike_tuple_v<T>, void>
print(const T& fake) {
    return Recursiveprint<0>(fake);
}

template<class T, class = void>
struct has_center_method : std::false_type {};

template<class T>
struct has_center_method<T,
        std::void_t<decltype(std::declval<const T>().center())>> :
        std::true_type {};

template<class T>
inline constexpr bool has_center_method_v =
        has_center_method<T>::value;

template<class T>
std::enable_if_t<has_center_method_v<T>, std::pair<double,double>>
center(const T& figure) {
    return figure.center();
}

template<class T>
inline constexpr const int tuple_size_v = std::tuple_size<T>::value;

template<size_t ID, class T>
std::pair<double,double> single_center(const T& t) {
    std::pair<double,double> v;
    v.first = std::get<ID>(t).first;
    v.second = std::get<ID>(t).second;
    //v /= std::tuple_size_v<T>;
    return v;
}

template<size_t ID, class T>
std::pair<double,double> Recursivecenter(const T& t) {
    if constexpr (ID < std::tuple_size_v<T>){
        return  (single_center<ID>(t) + Recursivecenter<ID+1>(t));
    } else {
        std::pair<double,double> v;
        v.first = 0;
        v.second = 0;
        return v;
    }
}

template<class T>
std::enable_if_t<is_figurelike_tuple_v<T>, std::pair<double,double>>
center(const T& fake) {
    return Recursivecenter<0>(fake);
}

template<class T, class = void>
struct has_area_method : std::false_type {};

template<class T>
struct has_area_method<T,
        std::void_t<decltype(std::declval<const T>().area())>> :
        std::true_type {};

template<class T>
inline constexpr bool has_area_method_v = has_area_method<T>::value;

template<class T>
std::enable_if_t<has_area_method_v<T>, double>
area(const T& figure) {
    return figure.area();
}

template<size_t ID, class T>
double single_area(const T& t) {
    const auto& a = std::get<0>(t);
    const auto& b = std::get<ID - 1>(t);
    const auto& c = std::get<ID>(t);
    const double dx1 = b.first - a.first;
    const double dy1 = b.second - a.second;
    const double dx2 = c.first - a.first;
    const double dy2 = c.second - a.second;
    return std::abs(dx1 * dy2 - dy1 * dx2) * 0.5;
}

template<size_t ID, class T>
double Recursivearea(const T& t) {
    if constexpr (ID < std::tuple_size_v<T>){
        return single_area<ID>(t) + Recursivearea<ID + 1>(t);
    }
    return 0;
}

template<class T>
std::enable_if_t<is_figurelike_tuple_v<T>, double>
area(const T& fake) {
    return Recursivearea<2>(fake);
}
#endif //TEMPLATES_H_