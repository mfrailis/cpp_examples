
#include <iostream>
#include <eigen3/Eigen/Dense>

using namespace std;
namespace E = Eigen;

int main()
{
  double a[] = {
    1, 2, 3,
    2, 1, 2,
    2, 5, 2};

  // create a  3x3 matrix of doubles using a built-in array as buffer
  E::Map<E::Matrix<double,3,3, E::RowMajor>> A(a);

  // create a vector and initialize using the initialization list
  E::Vector3d b {1,2,1};

  // solve the linear sistem using the LU factorization
  E::Vector3d x = A.fullPivLu().solve(b);

  // use overloaded arithmetic operators with matrices and vectors
  double relative_error = (A*x - b).norm() / b.norm(); // norm() is L2 norm

  cout << "A: \n" << A << endl;
  cout << "Solution: \n" << x << endl;
  cout << "The relative error is: " << relative_error << endl;
}
