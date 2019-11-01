//
// Created by Ilya on 25.10.2019.
//

#ifndef OOP_EXERCISE_04_TEMPLATES_H
#define OOP_EXERCISE_04_TEMPLATES_H
#include <type_traits>
#include "vertex.h"
struct false_type {
    static constexpr bool value = false;
};
template<class T>
struct is_vertex : std::false_type {};
template<class T>
struct is_vertex<vertex<T>> : std::true_type {};
template<class T>
struct is_figurelike_tuple : std::false_type {};
template<class Head, class... Tail>
struct is_figurelike_tuple<std::tuple<Head, Tail...>> :
        std::conjunction<is_vertex<Head>, std::is_same<Head, Tail...>>{}; //запись всё что было в tail через запятую(распаковка типов) is<Head, Tail[0], Tail[1], ... , Tail[n-1]
        // is<Head, Tail[0]>, is<H,T[1]> ...
        template<class T>
        inline constexpr bool is_figurelike_tuple_v = is_figurelike_tuple<T>::value;
                template<class T>
std::enable_if_t<!is_figurelike_tuple_v<T>, double> area(const T& figure) {
    return figure.area();
}

template<size_t  ID, class T>
double single_area(const T& t) {
    const auto& a = std::get<0>(t);
    const auto& b = std::get<ID-1>(t);
    const auto& c = std::get<ID>(t);
    const T dx1 = b.x - a.x;
    const T dy1 = b.y - a.y;
    const T dx2 = c.x - a.x;
    const T dy2 = c.y - a.y;
}
template<size_t ID, class T>
double recursive_area(const T& t) {
    if constexpr  (ID  < std::tuple_size_v<T>) {
        return  single_area<ID>(t) + recursive_area<ID+1>(t);
    } else {
        return 0;
    }
}

template<class T>
std::enable_if_t<is_figurelike_tuple_v<T>, double>
        area(const T& fake) {
            return recursive_area<2>(fake);
        }


#endif //OOP_EXERCISE_04_TEMPLATES_H
