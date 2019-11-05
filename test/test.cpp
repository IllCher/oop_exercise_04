#include <gtest/gtest.h>
#include "../src/templates.h"
TEST(TemplateAbsoluteTest, TestingAbsolution) {
    EXPECT_EQ(absolute(-1),1);
    EXPECT_EQ(absolute(0),0);
    EXPECT_EQ(absolute(1.2),1.2);
    EXPECT_EQ(absolute(-1.2), 1.2);
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

}

TEST(TemplateCenterTest, TestingCenterSquare) {

}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}