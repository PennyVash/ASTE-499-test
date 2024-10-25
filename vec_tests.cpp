#include "gtest/gtest.h"
#include "vec.h"

// Test for dot product
TEST(VecTest, VecDot) {
    double3 a{ 0, 1, 2 };
    double3 b{ 0, 0, 1 };
    EXPECT_EQ(dot(a, b), 2);
}

// Test fixture for vector addition and subtraction
class vecTestClass : public ::testing::Test {
protected:
    vecTestClass() : a{ 0, 1, 2 }, b{ 0, 0, 1 } { }

    void SetUp() override {
        // Test addition
        double3 c = a + b;
        add_matches = true;
        for (int i = 0; i < 3; i++) {
            if (c[i] != a[i] + b[i]) {
                add_matches = false;
            }
        }

        // Test subtraction
        double3 d = a - b;
        sub_matches = true;
        for (int i = 0; i < 3; i++) {
            if (d[i] != a[i] - b[i]) {
                sub_matches = false;
            }
        }
    }

    double3 a, b;
    bool sub_matches = false;
    bool add_matches = false;
};

// Test addition using test fixture
TEST_F(vecTestClass, VecAdd) {
    EXPECT_EQ(add_matches, true);
}

// Test subtraction using test fixture
TEST_F(vecTestClass, VecSub) {
    EXPECT_EQ(sub_matches, true);
}
