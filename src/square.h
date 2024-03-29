#ifndef OOP_EXERCISE_04_SQUARE_H
#define OOP_EXERCISE_04_SQUARE_H
template<class T>
struct TSquare {
    using type = T;
    using vertex = std::pair<T,T>;
    vertex A, B, C, D;
    TSquare(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) :
            A(x1, y1), B(x2, y2), C(x3,y3), D(x4,y4)
    {
        if (!is_square())
            throw std::logic_error("not a square\n");
    }
    TSquare(std::istream& is) {
        std::cin >> A >> B >> C >> D;
        if (!is_square())
            throw std::logic_error("not a square\n");

    }
    std::pair<double,double> center() const;
    void print() const;
    double area() const;
    bool is_square();
};

template <class T>

double TSquare<T>::area() const{
    return ((C.first - A.first) * (C.first - A.first) + (C.second - A.second) * (C.second - A.second)) * 0.5;
}

template <class T>
std::pair<double, double> TSquare<T>::center() const{
    return std::make_pair(static_cast<double>(A.first + C.first) / 2, static_cast<double>(A.second + C.second) / 2);
}

template <class T>
void TSquare<T>::print() const{
    std::pair m = TSquare<T>::center();
    std::cout << A << " " << B << " " << C  << " " << D << "\n";
}
template <class T>
bool TSquare<T>::is_square() {
    double vec1_x = B.first - A.first;
    double vec1_y = B.second - A.second;

    double vec2_x = C.first - B.first;
    double vec2_y = C.second - B.second;

    double vec3_x = D.first - A.first;
    double vec3_y = D.second - A.second;

    double vec4_x = D.first - C.first;
    double vec4_y = D.second - C.second;

    double vecAC_x = C.first - A.first;
    double vecAC_y = C.second - A.second;

    double vec1_length = sqrt(vec1_x * vec1_x + vec1_y * vec1_y);
    double vec2_length = sqrt(vec2_x * vec2_x + vec2_y * vec2_y);
    double vec3_length = sqrt(vec3_x * vec3_x + vec3_y * vec3_y);
    double vec4_length = sqrt(vec4_x * vec4_x + vec4_y * vec4_y);
    double vec_length = sqrt(vecAC_x*vecAC_x + vecAC_y*vecAC_y);

    if (vec_length < vec1_length) {
        std::pair<T,T> tmp;
        tmp.first = C.first;
        tmp.second = C.second;
        C.first = B.first;
        C.second = B.second;
        B.first = tmp.first;
        B.second = tmp.second;
    }
    if (vec_length < vec3_length) {
        std::pair<T,T> tmp;
        tmp.first = C.first;
        tmp.second = C.second;
        C.first = D.first;
        C.second = D.second;
        D.first = tmp.first;
        D.second = tmp.second;
    }
    vec1_x = B.first - A.first;
    vec1_y = B.second - A.second;

    vec2_x = C.first - B.first;
    vec2_y = C.second - B.second;

    vec3_x = D.first - A.first;
    vec3_y = D.second - A.second;

    vec4_x = D.first - C.first;
    vec4_y = D.second - C.second;
    double dotProduct1 = vec1_x * vec2_x + vec1_y * vec2_y;
    double dotProduct2 = vec3_x * vec1_x + vec3_y * vec1_y;
    double dotProduct3 = vec3_x * vec4_x + vec3_y * vec4_y;
    return dotProduct1 == 0 && dotProduct2 == 0 && dotProduct3 == 0 && vec1_length == vec4_length;
}
#endif //OOP_EXERCISE_04_SQUARE_H
