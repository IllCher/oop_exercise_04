#ifndef OOP_EXERCISE_04_TRIANGLE_H
#define OOP_EXERCISE_04_TRIANGLE_H
template<class T>
struct TTriangle {
    using type = T;
    using vertex = std::pair<T,T>;
    vertex A, B, C;
    TTriangle(T x1, T y1, T x2, T y2, T x3, T y3) :
            A(x1, y1), B(x2, y2), C(x3, y3)
    {
        double l = (sqrt((A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second)));
        double k = (sqrt((B.first - C.first) * (B.first - C.first) + (B.second - C.second) * (B.second - C.second)));
        double p = (sqrt((C.first - B.first) * (C.first - B.first) + (C.second - B.second) * (C.second - B.second)));
        if (l + k <= p || l + p <= k || p + k <= l) {
            throw std::logic_error("Triangle doesn't exist");
        }
    }
    TTriangle(std::istream& is) {
        is >> A >> B >> C;
        double l = (sqrt((A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second)));
        double k = (sqrt((B.first - C.first) * (B.first - C.first) + (B.second - C.second) * (B.second - C.second)));
        double p = (sqrt((C.first - B.first) * (C.first - B.first) + (C.second - B.second) * (C.second - B.second)));
        if (l + k <= p || l + p <= k || p + k <= l) {
            throw std::logic_error("Triangle doesn't exist");
        }
    }

    std::pair<double,double> center() const;
    void print() const;
    double area() const;
};


template <class T>
double TTriangle<T>::area() const{
    return (fabs((A.first - C.first) * (B.second - C.second) - (B.first - C.first) * (A.second - C.second)) * 0.5);
}

template <class T>
void TTriangle<T>::print() const{
    std::cout << A << " " << B << " " << C << "\n";
}

template <class T>
std::pair<double,double> TTriangle<T>::center() const {
    double x0 = (A.first + B.first + C.first) / 3;
    double y0 = (A.second + B.second + C.second) / 3;
    return std::make_pair(x0,y0);
}
#endif //OOP_EXERCISE_04_TRIANGLE_H
