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
    using vertex = std::pair<int, int>;
    using std::make_pair;
    using std::get;
    std::tuple<vertex, vertex> tSquare(make_pair(1.1, 2.2), make_pair(3.3, 6.6));
    EXPECT_EQ(get<0>(tSquare).first, 1);
    EXPECT_EQ(get<0>(tSquare).second, 2);
    EXPECT_EQ(get<1>(tSquare).first, 3);
    EXPECT_EQ(get<1>(tSquare).second, 6);
    std::tuple<vertex, vertex, vertex> tTriangle(make_pair(1.1, 2.2), make_pair(3.3, 6.6));
    EXPECT_EQ(get<0>(tTriangle).first, 1);
    EXPECT_EQ(get<0>(tTriangle).second, 2);
    EXPECT_EQ(get<1>(tTriangle).first, 3);
    EXPECT_EQ(get<1>(tTriangle).second, 6);
    EXPECT_EQ(get<2>(tTriangle).first, 1);
    EXPECT_EQ(get<2>(tTriangle).second, 2);
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}