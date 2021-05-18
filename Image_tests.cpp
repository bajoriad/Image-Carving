// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(image_get_set_pixel)
{
    Image *img = new Image;
    const Pixel red = {255, 0, 0};
    const Pixel green = {0, 255, 0};
    const Pixel blue = {0, 0, 255};
    const Pixel white = {255, 255, 255};
    const int width = 3;
    const int height = 3;
    Image_init(img, width, height);
    ASSERT_EQUAL(Image_width(img), width);
    ASSERT_EQUAL(Image_height(img), height);
    Image_set_pixel(img, 0, 0, red);
    Image_set_pixel(img, 0, 1, red);
    Image_set_pixel(img, 0, 2, red);
    Image_set_pixel(img, 1, 0, green);
    Image_set_pixel(img, 1, 1, green);
    Image_set_pixel(img, 1, 2, blue);
    Image_set_pixel(img, 2, 0, white);
    Image_set_pixel(img, 2, 1, blue);
    Image_set_pixel(img, 2, 2, green);
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), red));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 0), green));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 2), blue));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 2, 0), white));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), red));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 0), green));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 2), blue));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 2, 0), white));
    delete img;
}

TEST(test_image_fill)
{
    Image *img = new Image;
    const Pixel red = {255, 0, 0};
    const Pixel green = {0, 255, 0};
    const Pixel blue = {0, 0, 255};
    const int width = 5;
    const int height = 5;
    Image_init(img, width, height);
    Image_fill(img, green);
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), green));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 0), green));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 2), green));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 2, 4), green));
    Image_fill(img, red);
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), red));
    Image_fill(img, blue);
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 4, 4), blue));
    delete img;
}

TEST(test_image_print)
{
    Image *img = new Image;
    const Pixel red = {255, 0, 0};
    const Pixel green = {0, 255, 0};
    const Pixel blue = {0, 0, 255};
    const int width = 3;
    const int height = 3;
    Image_init(img, width, height);
    Image_set_pixel(img, 0, 0, red);
    Image_set_pixel(img, 0, 1, green);
    Image_set_pixel(img, 0, 2, blue);
    Image_set_pixel(img, 1, 0, green);
    Image_set_pixel(img, 1, 1, green);
    Image_set_pixel(img, 1, 2, red);
    Image_set_pixel(img, 2, 0, blue);
    Image_set_pixel(img, 2, 1, blue);
    Image_set_pixel(img, 2, 2, green);
    ostringstream actual;
    Image_print(img, actual);
    ostringstream expected;
    expected << "P3\n3 3\n255\n";
    expected << "255 0 0 0 255 0 0 0 255 \n";
    expected << "0 255 0 0 255 0 255 0 0 \n";
    expected << "0 0 255 0 0 255 0 255 0 \n";
    ASSERT_EQUAL(actual.str(), expected.str());
    delete img;
}

TEST(test_imig_init)
{
    Image *img = new Image;
    const Pixel red = {255, 0, 0};
    const Pixel green = {0, 255, 0};
    const Pixel blue = {0, 0, 255};
    string input = "P3\n 2 2\n 255\n 255 0 0 0 255 0\n 0 0 255 255 0 0\n";
    istringstream actual(input);
    Image_init(img, actual);
    ASSERT_EQUAL(Image_width(img),2);
    ASSERT_EQUAL(Image_height(img),2);
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), red));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 1), green));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 0), blue));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 1), red));
    delete img;
}

TEST(image_print)
{
    Image *img = new Image;
    const int width = 3;
    const int height = 3;
    Image_init(img, width, height);
    ASSERT_EQUAL(Image_height(img),height);
    ASSERT_EQUAL(Image_width(img), width);
    Image_set_pixel(img, 0, 0, Pixel {0 , 2, 225});
    Image_set_pixel(img, 0, 1, Pixel {10 , 25, 60});
    Image_set_pixel(img, 0, 2, Pixel {100 , 200, 225});
    Image_set_pixel(img, 1, 0, Pixel {0 , 255, 250});
    Image_set_pixel(img, 1, 1, Pixel {90 , 28, 225});
    Image_set_pixel(img, 1, 2, Pixel {10 , 205, 205});
    Image_set_pixel(img, 2, 0, Pixel {225 , 225, 225});
    Image_set_pixel(img, 2, 1, Pixel {57 , 35, 250});
    Image_set_pixel(img, 2, 2, Pixel {46 , 254, 0});
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), Pixel {0,2,225}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 1), Pixel {10,25,60}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 2), Pixel {100,200,225}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 0), Pixel {0,255,250}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 1), Pixel {90,28,225}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 2), Pixel {10,205,205}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 2, 0), Pixel {225,225,225}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 2, 1), Pixel {57,35,250}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 2, 2), Pixel {46,254,0}));
    ostringstream actual;
    Image_print(img, actual);
    ostringstream expected;
    expected << "P3\n3 3\n255\n";
    expected << "0 2 225 10 25 60 100 200 225 \n";
    expected << "0 255 250 90 28 225 10 205 205 \n";
    expected << "225 225 225 57 35 250 46 254 0 \n";
    ASSERT_EQUAL(actual.str(), expected.str());
    Image_fill(img, Pixel {0,45,45});
    ostringstream actual1;
    Image_print(img, actual1);
    ostringstream expected1;
    expected1 << "P3\n3 3\n255\n";
    expected1 << "0 45 45 0 45 45 0 45 45 \n";
    expected1 << "0 45 45 0 45 45 0 45 45 \n";
    expected1 << "0 45 45 0 45 45 0 45 45 \n";
    ASSERT_EQUAL(actual1.str(), expected1.str());
    delete img;
}

TEST(seven_by_three_matrix)
{
    Image *img = new Image;
    string input = "P3\n 3 7\n 255\n 0 2 225 56 78 90 0 0 225\n 34 56 76 67 89 225 78 89 250\n 45 67 89 0 0 225 250 250 250\n 255 255 255 0 0 0 250 250 250\n 89 90 67 90 67 248 76 89 90\n 67 78 90 56 245 89 46 78 245\n 88 90 46 78 99 100 250 245 246\n";
    istringstream actual(input);
    Image_init(img, actual);
    ASSERT_EQUAL(Image_height(img), 7);
    ASSERT_EQUAL(Image_width(img), 3);
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), Pixel {0,2,225}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 1), Pixel {56,78,90}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 0), Pixel {34,56,76}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 1, 1), Pixel {67,89,225}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 6, 0), Pixel {88,90,46}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 6, 1), Pixel {78,99,100}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 4, 2), Pixel {76,89,90}));
    ostringstream actual1;
    Image_print(img, actual1);
    ostringstream expected1;
    expected1 << "P3\n3 7\n255\n";
    expected1 << "0 2 225 56 78 90 0 0 225 \n";
    expected1 << "34 56 76 67 89 225 78 89 250 \n";
    expected1 << "45 67 89 0 0 225 250 250 250 \n";
    expected1 << "255 255 255 0 0 0 250 250 250 \n";
    expected1 << "89 90 67 90 67 248 76 89 90 \n";
    expected1 << "67 78 90 56 245 89 46 78 245 \n";
    expected1 << "88 90 46 78 99 100 250 245 246 \n";
    ASSERT_EQUAL(actual1.str(), expected1.str());
    delete img;
}

TEST(one_by_five)
{
    Image *img = new Image;
    const int width = 5;
    const int height = 1;
    Image_init(img, width, height);
    ASSERT_EQUAL(Image_height(img),height);
    ASSERT_EQUAL(Image_width(img), width);
    Image_set_pixel(img, 0, 0, Pixel {0 , 2, 225});
    Image_set_pixel(img, 0, 1, Pixel {10 , 250, 60});
    Image_set_pixel(img, 0, 2, Pixel {100 , 200, 225});
    Image_set_pixel(img, 0, 3, Pixel {0 , 255, 250});
    Image_set_pixel(img, 0, 4, Pixel {90 , 28, 225});
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), Pixel {0,2,225}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 1), Pixel {10,250,60}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 2), Pixel {100,200,225}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 3), Pixel {0,255,250}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 4), Pixel {90,28,225}));
    ostringstream actual;
    Image_print(img, actual);
    ostringstream expected;
    expected << "P3\n5 1\n255\n";
    expected << "0 2 225 10 250 60 100 200 225 0 255 250 90 28 225 \n";
    ASSERT_EQUAL(actual.str(), expected.str());
    Image_fill(img, Pixel {0,45,45});
    ostringstream actual1;
    Image_print(img, actual1);
    ostringstream expected1;
    expected1 << "P3\n5 1\n255\n";
    expected1 << "0 45 45 0 45 45 0 45 45 0 45 45 0 45 45 \n";
    ASSERT_EQUAL(actual1.str(), expected1.str());
    delete img;
}

TEST(one_by_five_base)
{
    Image *img = new Image;
    string input = "P3\n 5 1\n 255\n 0 2 225 10 250 60 100 200 225 0 255 250 90 28 225\n";
    istringstream actual(input);
    Image_init(img, actual);
    ASSERT_EQUAL(Image_height(img), 1);
    ASSERT_EQUAL(Image_width(img), 5);
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), Pixel {0,2,225}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 1), Pixel {10,250,60}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 2), Pixel {100,200,225}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 3), Pixel {0,255,250}));
    ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 4), Pixel {90,28,225}));
    ostringstream actual1;
    Image_print(img, actual1);
    ostringstream expected;
    expected << "P3\n5 1\n255\n";
    expected << "0 2 225 10 250 60 100 200 225 0 255 250 90 28 225 \n";
    ASSERT_EQUAL(actual1.str(), expected.str());
    delete img;
}


TEST(test_init_basic) {
  Image *img = new Image; // create an Image in dynamic memory
  Image_init(img, 4, 2);
    ASSERT_EQUAL(Image_width(img), 4);
    ASSERT_EQUAL(Image_height(img), 2);
  // Capture our output
  
  delete img; // delete the Image
}

// test all functions on a size one image
TEST(test_init) {
  Image *img = new Image; // create an Image in dynamic memory
    istringstream input("P3\n1 1\n255\n0 1 170 \n");
  Image_init(img, input);
    ASSERT_EQUAL(Image_width(img), 1);
    ASSERT_EQUAL(Image_height(img), 1);
    ostringstream correct;
    correct << "P3\n1 1\n255\n0 1 170 \n";
    ostringstream s;
    Image_print(img, s);
    ASSERT_EQUAL(s.str(), correct.str());
    Pixel p1 = Image_get_pixel(img, 0, 0);
    Pixel p = {0,1,170};
    ASSERT_EQUAL(Pixel_equal(p1, p),1);
    Pixel p2 = {150,3,0};
    Image_set_pixel(img,0,0,p2);
    ostringstream correct1;
    correct1 << "P3\n1 1\n255\n150 3 0 \n";
    ostringstream s1;
    Image_print(img, s1);
    ASSERT_EQUAL(s1.str(), correct1.str());
    
    Image_fill(img, p);
    ostringstream s2;
    Image_print(img, s2);
    ASSERT_EQUAL(s2.str(), correct.str());
  delete img; // delete the Image
}


// test all functions on an image of size 3*5
TEST(test_init1) {
  Image *img = new Image; // create an Image in dynamic memory
  Image_init(img, 5,3);
    const Pixel red = {255, 0, 0};
    const Pixel green = {0, 255, 0};
    const Pixel blue = {0, 0, 255};
    const Pixel white = {255, 255, 255};

    Image_set_pixel(img, 0, 0, red);
    Image_set_pixel(img, 0, 1, green);
    Image_set_pixel(img, 0, 2, blue);
    Image_set_pixel(img, 0, 3, white);
    Image_set_pixel(img, 0, 4, Pixel {0, 1, 2});
    Image_set_pixel(img, 1, 0, Pixel {3, 3, 3});
    Image_set_pixel(img, 1, 1, Pixel {5, 100, 0});
    Image_set_pixel(img, 1, 2, Pixel {2, 2, 2});
    Image_set_pixel(img, 1, 3, Pixel {8, 8, 8});
    Image_set_pixel(img, 1, 4, Pixel {100, 1, 2});
    Image_set_pixel(img, 2, 0, Pixel {200, 0, 200});
    Image_set_pixel(img, 2, 1, Pixel {5, 50, 0});
    Image_set_pixel(img, 2, 2, Pixel {2, 20, 20});
    Image_set_pixel(img, 2, 3, Pixel {80, 18, 80});
    Image_set_pixel(img, 2, 4, Pixel {100, 100, 2});
    
    ASSERT_EQUAL(Image_width(img), 5);
    ASSERT_EQUAL(Image_height(img), 3);
    ostringstream correct;
    correct << "P3\n5 3\n255\n255 0 0 0 255 0 0 0 255 255 255 255 0 1 2 \n";
    correct << "3 3 3 5 100 0 2 2 2 8 8 8 100 1 2 \n";
    correct << "200 0 200 5 50 0 2 20 20 80 18 80 100 100 2 \n";
    ostringstream s;
    Image_print(img, s);
    ASSERT_EQUAL(s.str(), correct.str());
    Pixel p1 = Image_get_pixel(img, 2, 2);
    Pixel p = {2,20,20};
    ASSERT_EQUAL(Pixel_equal(p1, p),1);
    Pixel p2 = {150,3,0};
    
    Image_set_pixel(img,1,3,p2);
    ostringstream correct1;
    correct1 << "P3\n5 3\n255\n255 0 0 0 255 0 0 0 255 255 255 255 0 1 2 \n";
    correct1 << "3 3 3 5 100 0 2 2 2 150 3 0 100 1 2 \n";
    correct1 << "200 0 200 5 50 0 2 20 20 80 18 80 100 100 2 \n";
    ostringstream s1;
    Image_print(img, s1);
    ASSERT_EQUAL(s1.str(), correct1.str());
    
    Image_fill(img, red);
    ostringstream s2;
    Image_print(img, s2);
    ostringstream correct2;
    correct2 << "P3\n5 3\n255\n255 0 0 255 0 0 255 0 0 255 0 0 255 0 0 \n";
    correct2 << "255 0 0 255 0 0 255 0 0 255 0 0 255 0 0 \n";
    correct2 << "255 0 0 255 0 0 255 0 0 255 0 0 255 0 0 \n";
    ASSERT_EQUAL(s2.str(), correct2.str());
  delete img; // delete the Image
}

TEST(test_init3) {
  Image *img = new Image; // create an Image in dynamic memory
    istringstream input("P3\n1 3\n255\n0 1 170 \n0 0 0 \n 250 250 250 \n");
  Image_init(img, input);
    ASSERT_EQUAL(Image_width(img), 1);
    ASSERT_EQUAL(Image_height(img), 3);
    ostringstream correct;
    correct << "P3\n1 3\n255\n0 1 170 \n0 0 0 \n250 250 250 \n";
    ostringstream s;
    Image_print(img, s);
    ASSERT_EQUAL(s.str(), correct.str());
    Pixel p1 = Image_get_pixel(img, 1, 0);
    Pixel p = {0,0,0};
    ASSERT_EQUAL(Pixel_equal(p1, p),1);
    Pixel p2 = {150,3,0};
    Image_set_pixel(img,2,0,p2);
    ostringstream correct1;
    correct1 << "P3\n1 3\n255\n0 1 170 \n0 0 0 \n150 3 0 \n";
    ostringstream s1;
    Image_print(img, s1);
    ASSERT_EQUAL(s1.str(), correct1.str());
    
    Image_fill(img, p);
    ostringstream s2;
    Image_print(img, s2);
    ostringstream correct2;
    correct2 << "P3\n1 3\n255\n0 0 0 \n0 0 0 \n0 0 0 \n";
    ASSERT_EQUAL(s2.str(), correct2.str());
  delete img; // delete the Image
}

// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
