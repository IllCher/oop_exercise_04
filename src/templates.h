#ifndef TEMPLATES_H_
#define TEMPLATES_H_
#include <utility>
#include <type_traits>
#include <tuple>
#include <cmath>

template <typename T1, typename T2>
std::ostream& operator<< (std::ostream& out, const std::pair<T1, T2>& p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

template<class T>
struct TTriangle {
    using type = T;
    using vertex = std::pair<T,T>;
    vertex A, B, C;
    TTriangle(T x1, T y1, T x2, T y2, T x3, T y3) :
            A(x1, y1), B(x2, y2), C(x3, y3)
    {
        auto l = (sqrt((A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second)));
        auto k = (sqrt((B.first - C.first) * (B.first - C.first) + (B.second - C.second) * (B.second - C.second)));
        auto p = (sqrt((C.first - B.first) * (C.first - B.first) + (C.second - B.second) * (C.second - B.second)));
        if (l + k <= p || l + p <= k || p + k <= l) {
            throw std::logic_error("Triangle doesn't exist");
        }
    }

};

template<class T>
struct TOctagon{
    using type = T;
    using vertex = std::pair<T,T>;
    vertex A, B, C, D, E, F, G, H;
    TOctagon(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4, T x5, T y5, T x6, T y6, T x7, T y7, T x8, T y8) :
            A(x1, y1), B(x2, y2), C(x3, y3), D(x4, y4), E(x5, y5), F(x6, y6), G(x7, y7), H(x8, y8)
    {}
};

template<class T>
struct TSquare {
    using type = T;
    using vertex = std::pair<T,T>;
    vertex A, C;
    TSquare(T x1, T y1, T x2, T y2) :
            A(x1, y1), C(x2, y2)
    {}
};

template <class T>
struct IsTTriangle {
    static constexpr bool value = false;
};

template <template <class...> class F, class T>
struct IsTTriangle<F<T>> {
    static constexpr bool value = std::is_same<F<T>, TTriangle<T>>::value;
};

template <class T>
typename std::enable_if<IsTTriangle<T>::value, double>::type
area(const T& t) {
    return (fabs(((t.A.first - t.C.first) * (t.B.second - t.C.second) - (t.B.first - t.C.first) * (t.A.second - t.C.second))) * 0.5);
}

template <class T>
void print(const TTriangle<T>& t) {
    std::cout << t.A << " " << t.B << " " << t.C << "\n";
}

template <class T>
typename std::enable_if<IsTTriangle<T>::value, std::pair<typename T::type, typename T::type>>::type
center(const T& t) {
    typename T::type x0 = (t.A.first + t.B.first + t.C.first) / 3;
    typename T::type y0 = (t.A.second + t.B.second + t.C.second) / 3;
    return std::make_pair(x0,y0);
}

template <class T>
struct IsTOctagon {
    static constexpr bool value = false;
};

template <template <class...> class F, class T>
struct IsTOctagon<F<T>> {
    static constexpr bool value = std::is_same<F<T>, TOctagon<T>>::value;
};

template <class T>
typename std::enable_if<IsTOctagon<T>::value, double>::type
area(const T& o) {
    return fabs(((o.A.first * o.B.second) + (o.B.first * o.C.second) + (o.C.first * o.D.second) + (o.D.first * o.E.second) + (o.E.first * o.F.second) + (o.F.first * o.G.second) + (o.G.first * o.H.second) + (o.H.first * o.A.second) - (o.B.first * o.A.second) - (o.C.first * o.B.second) - (o.D.first * o.C.second) - (o.E.first * o.D.second) - (o.F.first * o.E.second) - (o.G.first * o.F.second) - (o.H.first * o.G.second) - (o.A.first * o.H.second)) * 0.5);
}

template <class T>
void print(const TOctagon<T>& o) {
    std::cout << o.A << " " << o.B << " " << o.C << " " << o.D << " " << o.E << " " << o.F << " " << o.G << " " << o.H << "\n";
}

template <class T>
typename std::enable_if<IsTOctagon<T>::value, std::pair<typename T::type, typename T::type>>::type
center(const T& o) {
    return std::make_pair((o.A.first + o.B.first + o.C.first + o.D.first + o.E.first + o.F.first + o.G.first + o.H.first) / 8,(o.A.second + o.B.second + o.C.second + o.D.second + o.E.second + o.F.second + o.G.second + o.H.second) / 8);
}
template <class T>
struct IsTSquare {
    static constexpr bool value = false;
};

template <template <class...> class F, class T>
struct IsTSquare<F<T>> {
    static constexpr bool value = std::is_same<F<T>, TSquare<T>>::value;
};

template <class T>
typename std::enable_if<IsTSquare<T>::value, double>::type
area(const T& s) {
    return ((s.C.first - s.A.first) * (s.C.first - s.A.first) + (s.C.second - s.A.second) * (s.C.second - s.A.second)) * 0.5;
}

template <class T>
typename std::enable_if<IsTSquare<T>::value, std::pair<typename T::type, typename T::type>>::type
center(const T& s) {
    return std::make_pair((s.A.first + s.C.first) / 2, (s.A.second + s.C.second) / 2);
}

template <class T>
void print(const TSquare<T>& s) {
    std::pair m = center(s);
    std::cout << s.A << " " <<  std::make_pair(m.first - s.C.second + m.second, m.second + s.C.first - m.first) << " " << s.C  << " " << std::make_pair(m.first - s.A.second + m.second, m.second + s.A.first - m.first) << "\n";
}

template <class T>
T area(const std::tuple<std::pair<T,T>, std::pair<T,T>, std::pair<T,T>>& tTriangle) {
    return fabs(((std::get<0>(tTriangle).first - std::get<2>(tTriangle).first) * (std::get<1>(tTriangle).second - std::get<2>(tTriangle).second) - (std::get<1>(tTriangle).first - std::get<2>(tTriangle).first) * (std::get<0>(tTriangle).second - std::get<2>(tTriangle).second)) * 0.5);
}

template <class T>
T area(const std::tuple<std::pair<T, T>, std::pair<T, T>, std::pair<T, T>, std::pair<T, T>, std::pair<T, T>, std::pair<T, T>, std::pair<T, T>, std::pair<T, T>>& tOctagon) {
    return fabs(((std::get<0>(tOctagon).first * std::get<1>(tOctagon).second) + (std::get<1>(tOctagon).first * std::get<2>(tOctagon).second) + (std::get<2>(tOctagon).first * std::get<3>(tOctagon).second) + (std::get<3>(tOctagon).first * std::get<4>(tOctagon).second) + (std::get<4>(tOctagon).first * std::get<5>(tOctagon).second) + (std::get<5>(tOctagon).first * std::get<6>(tOctagon).second) + (std::get<6>(tOctagon).first * std::get<7>(tOctagon).second) + (std::get<7>(tOctagon).first * std::get<0>(tOctagon).second) - (std::get<1>(tOctagon).first * std::get<0>(tOctagon).second) - (std::get<2>(tOctagon).first * std::get<1>(tOctagon).second) - (std::get<3>(tOctagon).first * std::get<2>(tOctagon).second) - (std::get<4>(tOctagon).first * std::get<3>(tOctagon).second) - (std::get<5>(tOctagon).first * std::get<4>(tOctagon).second) - (std::get<6>(tOctagon).first * std::get<5>(tOctagon).second) - (std::get<7>(tOctagon).first * std::get<6>(tOctagon).second) - (std::get<0>(tOctagon).first * std::get<7>(tOctagon).second)) * 0.5);
}

template <class T>
T area(const std::tuple<std::pair<T, T>, std::pair<T, T>>& tSquare) {
    return fabs(((std::get<1>(tSquare).first - std::get<0>(tSquare).first) * (std::get<1>(tSquare).first - std::get<0>(tSquare).first) + (std::get<1>(tSquare).second - std::get<0>(tSquare).second) * (std::get<1>(tSquare).second - std::get<0>(tSquare).second)) * 0.5);
}
#endif //TEMPLATES_H_