#include <gtest/gtest.h>
#include "../src/templates.h"

TEST(TriangleValidation, TestingValidation) {
    ASSERT_NO_THROW(TTriangle(0, 1, 0, 0, 2, -1));
    ASSERT_NO_THROW(TTriangle(2.2, 3.2, 5.32, 6.7, 89.43, -143.3));
    ASSERT_ANY_THROW(TTriangle(0, 0, 0, 0, 1, 1));
    ASSERT_ANY_THROW(TTriangle(0.0, 0.0, 0.0, 0.0, 1.1, 1.1));
}

TEST(TemplateAreaTest, TestingAreaTriangle) {
    TTriangle<int> triangle1(0, 1, 2, -1, -2, -1);
    EXPECT_EQ(area(triangle1), 4);
    TTriangle<double> triangle2(0, 1, 2, -1, -2, -1);
    EXPECT_DOUBLE_EQ(area(triangle2), 4);
}

TEST(TemplateAreaTest, TestingAreaOctagon) {
    TOctagon<int> octagon1(2, 2, 2, 5, 4, 7, 7, 7, 9, 5, 9, 2, 7, -1, 4, -1);
    EXPECT_EQ(area(octagon1), 46);
    TOctagon<double> octagon2(2, 2, 2, 5, 4, 7, 7, 7, 9, 5, 9, 2, 7, -1, 4, -1);
    EXPECT_DOUBLE_EQ(area(octagon2), 46);
}

TEST(TemplateAreaTest, TestingAreaSquare) {
    TSquare<int> square1(2, 0, -2, 0);
    EXPECT_EQ(area(square1), 8);
    TSquare<double> square2(2, 0, -2, 0);
    EXPECT_DOUBLE_EQ(area(square2), 8);
}

TEST(TemplateCenterTest, TestingCenterTriangle) {
    TTriangle<int> triangle1(2, 2, 3, 0, -2, 1);
    std::pair pair1 = center(triangle1);
    EXPECT_EQ(pair1.first, 1);
    EXPECT_EQ(pair1.second, 1);
    TTriangle<double> triangle2(1, 1, 2, -1, -2, -1);
    std::pair pair2 = center(triangle2);
    EXPECT_DOUBLE_EQ(pair2.first, 0.33333333333333331);
    EXPECT_DOUBLE_EQ(pair2.second, -0.33333333333333331);
}

TEST(TemplateCenterTest, TestingCenterOctagon) {
    TOctagon<int> octagon1(0, 0,0, 2,2, 3,4, 3,6, 2,6, 0,4, -1,2, -1);
    std::pair pair1 = center(octagon1);
    EXPECT_EQ(pair1.first,3);
    EXPECT_EQ(pair1.second,1);
    TOctagon<double> octagon2(2, 2,
    2, 5,
    4, 7,
    7, 7,
    9, 5,
    9, 2,
    7, -1,
    4, -1);
    std::pair pair2 = center(octagon2);
    EXPECT_DOUBLE_EQ(pair2.first,5.5);
    EXPECT_DOUBLE_EQ(pair2.second,3.25);
}

TEST(TemplateCenterTest, TestingCenterSquare) {
    TSquare<int> square1(2, 2, 5, 4);
    std::pair pair1 = center(square1);
    EXPECT_EQ(pair1.first,3.5);
    EXPECT_EQ(pair1.second,3);
    TSquare<double> square2(2, 2, 5, 4);
    std::pair pair2 = center(square2);
    EXPECT_DOUBLE_EQ(pair2.first,3.5);
    EXPECT_DOUBLE_EQ(pair2.second,3);
}

TEST(TemplateAreaTestTuple, TestingAreaTuple) {
    using vertex1 = std::pair<int, int>;
    using vertex2 = std::pair<double, double>;
    using std::make_pair;
    using std::get;

    std::tuple<vertex1, vertex1> tSquareI1(make_pair(2, 0), make_pair(-2, 0));
    EXPECT_EQ(area(tSquareI1), 8);
    std::tuple<vertex1, vertex1> tSquareI2(make_pair(0, 0), make_pair(0, 1));
    EXPECT_DOUBLE_EQ(area(tSquareI2), 0.5);
    std::tuple<vertex2, vertex2> tSquareD(make_pair(2.5, 1), make_pair(-2.5, 3.5));
    EXPECT_DOUBLE_EQ(area(tSquareD), 15.625);

    std::tuple<vertex1, vertex1, vertex1> tTriangleI1(make_pair(0, 1), make_pair(2, -1) , make_pair(-2,-1));
    EXPECT_EQ(area(tTriangleI1), 0);
    std::tuple<vertex1, vertex1, vertex1> tTriangleI2(make_pair(0, 0), make_pair(0, 1), make_pair(5,0));
    EXPECT_DOUBLE_EQ(area(tTriangleI2), 2.5);
    std::tuple<vertex2, vertex2, vertex2> tTriangleD(make_pair(2.5, 1), make_pair(-2.5, 3.5), make_pair(3.5, 8.9));
    EXPECT_DOUBLE_EQ(area(tSquareD), 15.625);

}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}