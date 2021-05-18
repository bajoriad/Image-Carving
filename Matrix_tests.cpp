// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic)
{
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(test_matrix_print)
{
    Matrix *mat = new Matrix;
    const int width = 5;
    const int height = 5;
    Matrix_init(mat,5,5);
    int width_copy = Matrix_width(mat);
    int height_copy = Matrix_height(mat);
    ASSERT_EQUAL(width, width_copy);
    ASSERT_EQUAL(height, height_copy);
    *Matrix_at(mat,0,0) = 1;
    *Matrix_at(mat,0,1) = 3;
    *Matrix_at(mat,0,2) = 9;
    *Matrix_at(mat,0,3) = 12;
    *Matrix_at(mat,0,4) = 15;
    *Matrix_at(mat,1,0) = 18;
    *Matrix_at(mat,1,1) = 21;
    *Matrix_at(mat,1,2) = 24;
    *Matrix_at(mat,1,3) = 27;
    *Matrix_at(mat,1,4) = 30;
    *Matrix_at(mat,2,0) = 75;
    *Matrix_at(mat,2,1) = 36;
    *Matrix_at(mat,2,2) = 39;
    *Matrix_at(mat,2,3) = 42;
    *Matrix_at(mat,2,4) = 45;
    *Matrix_at(mat,3,0) = 48;
    *Matrix_at(mat,3,1) = 51;
    *Matrix_at(mat,3,2) = 54;
    *Matrix_at(mat,3,3) = 57;
    *Matrix_at(mat,3,4) = 60;
    *Matrix_at(mat,4,0) = 63;
    *Matrix_at(mat,4,1) = 66;
    *Matrix_at(mat,4,2) = 69;
    *Matrix_at(mat,4,3) = 72;
    *Matrix_at(mat,4,4) = 33;
    ASSERT_EQUAL(*Matrix_at(mat,4,4), 33);
    const int* ptr = Matrix_at(mat,4,4);
    int col = Matrix_column(mat, ptr);
    ASSERT_EQUAL(col, 4);
    int row = Matrix_row(mat, ptr);
    ASSERT_EQUAL(row, 4);
    ostringstream actual;
    ostringstream expected;
    expected << "5 5\n"
             << "1 3 9 12 15 \n"
             << "18 21 24 27 30 \n"
             << "75 36 39 42 45 \n"
             << "48 51 54 57 60 \n"
             << "63 66 69 72 33 \n";
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());
    int max = Matrix_max(mat);
    ASSERT_EQUAL(max, 75);
    int min_col = Matrix_column_of_min_value_in_row(mat, 0, 0, 5);
    ASSERT_EQUAL(min_col, 0);
    int min_value = Matrix_min_value_in_row(mat, 0, 0, 5);
    ASSERT_EQUAL(min_value, 1);
    delete mat;
}

TEST(test_matrix_fill)
{
    Matrix *mat = new Matrix;
    Matrix_init(mat,5,5);
    Matrix_fill(mat, 42);
    ASSERT_EQUAL(*Matrix_at(mat,4,4), 42);
    ASSERT_EQUAL(*Matrix_at(mat,0,0), 42);
    Matrix_fill_border(mat, 30);
    ostringstream actual1;
    ostringstream expected1;
    expected1 << "5 5\n"
             << "30 30 30 30 30 \n"
             << "30 42 42 42 30 \n"
             << "30 42 42 42 30 \n"
             << "30 42 42 42 30 \n"
             << "30 30 30 30 30 \n";
    Matrix_print(mat, actual1);
    ASSERT_EQUAL(expected1.str(), actual1.str());
    ASSERT_EQUAL(Matrix_max(mat), 42);
    delete mat;
}

TEST(test_matrix_print1)
{
    Matrix *mat = new Matrix;
    const int width = 3;
    const int height = 3;
    Matrix_init(mat,3,3);
    int width_copy = Matrix_width(mat);
    int height_copy = Matrix_height(mat);
    ASSERT_EQUAL(width, width_copy);
    ASSERT_EQUAL(height, height_copy);
    *Matrix_at(mat, 0, 0) = 96;
    *Matrix_at(mat, 0, 1) = -4;
    *Matrix_at(mat, 0, 2) = -4;
    *Matrix_at(mat, 1, 0) = -100;
    *Matrix_at(mat, 1, 1) = 90;
    *Matrix_at(mat, 1, 2) = 5;
    *Matrix_at(mat, 2, 0) = 567;
    *Matrix_at(mat, 2, 1) = 9009;
    *Matrix_at(mat, 2, 2) = 1000;
    int min_col = Matrix_column_of_min_value_in_row(mat, 0, 0, 3);
    ASSERT_EQUAL(min_col, 1);
    int min_col1 = Matrix_column_of_min_value_in_row(mat, 1, 0, 3);
    ASSERT_EQUAL(min_col1, 0);
    int min_value = Matrix_min_value_in_row(mat, 0, 0, 3);
    ASSERT_EQUAL(min_value, -4);
    int min_value1 = Matrix_min_value_in_row(mat, 2, 0, 3);
    ASSERT_EQUAL(min_value1, 567);
    delete mat;
}

TEST(matrix_column)
{
    Matrix *mat = new Matrix;
    const int width = 5;
    const int height = 5;
    Matrix_init(mat, width, height);
    int width_copy = Matrix_width(mat);
    int height_copy = Matrix_height(mat);
    ASSERT_EQUAL(width, width_copy);
    ASSERT_EQUAL(height, height_copy);
    Matrix_fill(mat, 43);
    const int *ptr = Matrix_at(mat, 4, 0);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 0);
    ptr = ptr + 4;
    ASSERT_EQUAL(Matrix_column(mat, ptr), 4);
    delete mat;
}

TEST(matrix_row)
{
    Matrix *mat = new Matrix;
    const int width = 3;
    const int height = 3;
    Matrix_init(mat, width, height);
    int width_copy = Matrix_width(mat);
    int height_copy = Matrix_height(mat);
    ASSERT_EQUAL(width, width_copy);
    ASSERT_EQUAL(height, height_copy);
    Matrix_fill(mat, 0);
    const int *ptr = Matrix_at(mat, 0, 1);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 0);
    ptr = ptr + 3;
    ASSERT_EQUAL(Matrix_row(mat, ptr), 1);
    delete mat;
}

TEST(min_col_and_value)
{
    Matrix *mat = new Matrix;
    const int width = 6;
    const int height = 6;
    Matrix_init(mat, width, height);
    ASSERT_EQUAL(Matrix_width(mat), 6);
    ASSERT_EQUAL(Matrix_height(mat), 6);
    *Matrix_at(mat,0,0) = -100;
    *Matrix_at(mat,0,1) = 1000;
    *Matrix_at(mat,0,2) = 67;
    *Matrix_at(mat,0,3) = 90;
    *Matrix_at(mat,0,4) = 45;
    *Matrix_at(mat,0,5) = 34;
    *Matrix_at(mat,1,0) = -56;
    *Matrix_at(mat,1,1) = 90;
    *Matrix_at(mat,1,2) = -98;
    *Matrix_at(mat,1,3) = -120;
    *Matrix_at(mat,1,4) = 300;
    *Matrix_at(mat,1,5) = 320;
    *Matrix_at(mat,2,0) = -450;
    *Matrix_at(mat,2,1) = -340;
    *Matrix_at(mat,2,2) = -68;
    *Matrix_at(mat,2,3) = -99;
    *Matrix_at(mat,2,4) = -234;
    *Matrix_at(mat,2,5) = -890;
    *Matrix_at(mat,3,0) = 890;
    *Matrix_at(mat,3,1) = 34;
    *Matrix_at(mat,3,2) = 90;
    *Matrix_at(mat,3,3) = 4345;
    *Matrix_at(mat,3,4) = 789;
    *Matrix_at(mat,3,5) = 89;
    *Matrix_at(mat,4,0) = -90;
    *Matrix_at(mat,4,1) = -90;
    *Matrix_at(mat,4,2) = -90;
    *Matrix_at(mat,4,3) = -90;
    *Matrix_at(mat,4,4) = -90;
    *Matrix_at(mat,4,5) = -90;
    *Matrix_at(mat,5,0) = 101;
    *Matrix_at(mat,5,1) = 101;
    *Matrix_at(mat,5,2) = 101;
    *Matrix_at(mat,5,3) = 101;
    *Matrix_at(mat,5,4) = 101;
    *Matrix_at(mat,5,5) = 101;
    ASSERT_EQUAL(Matrix_max(mat), 4345);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 6), 0);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 2, 5), 3);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 3, 5), 4);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 3, 4, 6), 5);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 4, 1, 5), 1);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 5, 4, 5), 4);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 1, 6), 34);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 2, 6), -120);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 3, 6), -890);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 3, 4, 6), 89);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 4, 1, 6), -90);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 5, 4, 6), 101);
    ostringstream actual1;
    ostringstream expected1;
    expected1 << "6 6\n"
              << "-100 1000 67 90 45 34 \n"
              << "-56 90 -98 -120 300 320 \n"
              << "-450 -340 -68 -99 -234 -890 \n"
              << "890 34 90 4345 789 89 \n"
              << "-90 -90 -90 -90 -90 -90 \n"
              << "101 101 101 101 101 101 \n";
    Matrix_print(mat, actual1);
    ASSERT_EQUAL(expected1.str(), actual1.str());
    delete mat;
}

TEST(three_by_five_matrix)
{
    Matrix *mat = new Matrix;
    const int width = 5;
    const int height = 3;
    Matrix_init(mat, width, height);
    ASSERT_EQUAL(Matrix_width(mat), 5);
    ASSERT_EQUAL(Matrix_height(mat), 3);
    *Matrix_at(mat,0,0) = -100;
    *Matrix_at(mat,0,1) = 200;
    *Matrix_at(mat,0,2) = -100;
    *Matrix_at(mat,0,3) = 906;
    *Matrix_at(mat,0,4) = -45;
    *Matrix_at(mat,1,0) = -56;
    *Matrix_at(mat,1,1) = 90;
    *Matrix_at(mat,1,2) = -98;
    *Matrix_at(mat,1,3) = -120;
    *Matrix_at(mat,1,4) = 300;
    *Matrix_at(mat,2,0) = -45;
    *Matrix_at(mat,2,1) = -45;
    *Matrix_at(mat,2,2) = -45;
    *Matrix_at(mat,2,3) = -45;
    *Matrix_at(mat,2,4) = -45;
    ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 2, 3)), 2);
    ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 2, 1)), 2);
    ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 0, 3)), 3);
    ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 1, 2)), 2);
    ASSERT_EQUAL(Matrix_max(mat), 906);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 5), 0);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 2, 5), 3);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 3, 5), 3);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 1, 5), -100);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 2, 5), -120);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 3, 5), -45);
    Matrix_fill(mat, -30);
    Matrix_fill_border(mat, 450);
    ostringstream actual1;
    ostringstream expected1;
    expected1 << "5 3\n"
              << "450 450 450 450 450 \n"
              << "450 -30 -30 -30 450 \n"
              << "450 450 450 450 450 \n";
    Matrix_print(mat, actual1);
    ASSERT_EQUAL(expected1.str(), actual1.str());
    delete mat;
}

TEST(one_by_one)
{
    Matrix *mat = new Matrix;
    const int width = 1;
    const int height = 1;
    Matrix_init(mat, width, height);
    ASSERT_EQUAL(Matrix_width(mat), 1);
    ASSERT_EQUAL(Matrix_height(mat), 1);
    ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 0, 0)), 0);
    ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 0, 0)), 0);
    *Matrix_at(mat, 0, 0) = 45;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 1), 0);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 1), 45);
    ostringstream actual1;
    ostringstream expected1;
    Matrix_fill(mat, -100);
    Matrix_fill_border(mat, -45);
    expected1 << "1 1\n"
              << "-45 \n";
    Matrix_print(mat, actual1);
    ASSERT_EQUAL(expected1.str(), actual1.str());
    delete mat;
}

TEST(test_matrix_print2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 2);

  Matrix_fill(mat, -2);
    *Matrix_at(mat, 0, 0) = 10;
    *Matrix_at(mat, 0, 1) = -9;
    *Matrix_at(mat, 1, 4) = 6;

  ostringstream expected;
  expected << "5 2\n"
    << "10 -9 -2 -2 -2 \n"
           << "-2 -2 -2 -2 6 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());
    ASSERT_EQUAL(Matrix_width(mat), 5);
    ASSERT_EQUAL(Matrix_max(mat), 10);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,0,0,4),1)
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,0,2,4),2)
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,1,0,4),0)
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,0,0,5), -9);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,0,0,1), 10);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,0,0,2), -9);
  delete mat;
}

TEST(test_matrix_print3) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);
    *Matrix_at(mat, 0, 0) = 10;
  ostringstream expected;
    expected<< "1 1\n"
    << "10 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());
ASSERT_EQUAL(Matrix_width(mat), 1);
    ASSERT_EQUAL(Matrix_max(mat), 10);
    
    
  delete mat;
}

TEST(test_matrix_print4) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 4);
    Matrix_fill(mat, 0);
    *Matrix_at(mat, 3, 3) = 10;
  ostringstream expected;
    expected<< "5 4\n"
    << "0 0 0 0 0 \n"
    << "0 0 0 0 0 \n"
    << "0 0 0 0 0 \n"
    << "0 0 0 10 0 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());
    ASSERT_EQUAL(Matrix_width(mat), 5);
ASSERT_EQUAL(Matrix_max(mat), 10);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,3,0,4),0);
  delete mat;
}


TEST(test_matrix_fill_border) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 4);
    Matrix_fill(mat, 0);
    Matrix_fill_border(mat, -2);
  ostringstream expected;
    expected<< "5 4\n"
    << "-2 -2 -2 -2 -2 \n"
    << "-2 0 0 0 -2 \n"
    << "-2 0 0 0 -2 \n"
    << "-2 -2 -2 -2 -2 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());
    ASSERT_EQUAL(Matrix_width(mat), 5);
ASSERT_EQUAL(Matrix_max(mat), 0);
    *Matrix_at(mat, 1, 3) = -3;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,1,1,4),3);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,1,0,3), -2);
     ASSERT_EQUAL(Matrix_min_value_in_row(mat,1,0,4), -3);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,1,0,5), -3);
  delete mat;
}

TEST(test_matrix_fill_border1) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 7, 3);
    *Matrix_at(mat, 0, 0) = -1;
    *Matrix_at(mat, 0, 1) = 0;
    *Matrix_at(mat, 0, 2) = 2;
    *Matrix_at(mat, 0, 3) = 6;
    *Matrix_at(mat, 0, 4) = 5;
    *Matrix_at(mat, 0, 5) = 10;
    *Matrix_at(mat, 0, 6) = -5;
    *Matrix_at(mat, 1, 0) = 2;
    *Matrix_at(mat, 1, 1) = 2;
    *Matrix_at(mat, 1, 2) = 1;
    *Matrix_at(mat, 1, 3) = 0;
    *Matrix_at(mat, 1, 4) = 2;
    *Matrix_at(mat, 1, 5) = 3;
    *Matrix_at(mat, 1, 6) = 4;
    *Matrix_at(mat, 2, 0) = 1;
    *Matrix_at(mat, 2, 1) = 0;
    *Matrix_at(mat, 2, 2) = 0;
    *Matrix_at(mat, 2, 3) = 2;
    *Matrix_at(mat, 2, 4) = 3;
    *Matrix_at(mat, 2, 5) = 3;
    *Matrix_at(mat, 2, 6) = 2;
  ostringstream expected;
    expected<< "7 3\n"
    << "-1 0 2 6 5 10 -5 \n"
    << "2 2 1 0 2 3 4 \n"
    << "1 0 0 2 3 3 2 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());
    ASSERT_EQUAL(Matrix_width(mat), 7);
    ASSERT_EQUAL(Matrix_max(mat), 10);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,0,0,7),-5);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,0,0,6),-1);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,1,0,7),0);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,1,3,7),0);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,2,0,7),0);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,0,0,7),6);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,0,0,6),0);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,1,0,7),3);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,1,3,7),3);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,2,0,7),1);
 
    Matrix_fill_border(mat, -7);
     ASSERT_EQUAL(Matrix_min_value_in_row(mat,2,0,7),-7);
     ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,0,0,7),0);
  delete mat;
}


TEST(test_matrix_fill_border2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 4);
    Matrix_fill(mat, 0);
    Matrix_fill_border(mat, 5);
  ostringstream expected;
    expected<< "1 4\n"
    << "5 \n"
    << "5 \n"
    << "5 \n"
    << "5 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());
    ASSERT_EQUAL(Matrix_width(mat), 1);
    *Matrix_at(mat, 0, 0) = 6;
ASSERT_EQUAL(Matrix_max(mat), 6);
  delete mat;
}

TEST(test_matrix_fill_border3) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 2, 2);
    Matrix_fill(mat, 0);
    Matrix_fill_border(mat, 2);
  ostringstream expected;
    expected<< "2 2\n"
    << "2 2 \n"
    << "2 2 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,1,0,1),0);
    *Matrix_at(mat, 0, 1) = 1;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,0,0,1),0);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,0,0,2), 1);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat,0,0,1), 2);
  delete mat;
}



TEST(test_matrix_column) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 4);
    Matrix_fill(mat, 0);
    *Matrix_at(mat, 3, 3) = 10;
    int *prt = Matrix_at(mat, 0, 0);
    prt += 8;
    ASSERT_EQUAL(Matrix_row(mat, prt), 1);
    ASSERT_EQUAL(Matrix_column(mat, prt), 3);

  delete mat;
}

TEST(test_matrix_column1) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 4);
    Matrix_fill(mat, 0);
    int *prt = Matrix_at(mat, 0, 0);
    prt += 3;
    ASSERT_EQUAL(Matrix_row(mat, prt), 3);
    ASSERT_EQUAL(Matrix_column(mat, prt), 0);

  delete mat;
}
// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
