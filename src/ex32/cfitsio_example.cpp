
#include <iostream>
#include <exception>
#include <memory>
#include <sstream>
#include <cstdio>
#define EIGEN_DEFAULT_TO_ROW_MAJOR
#include <eigen3/Eigen/Dense>

extern "C" {
#include <string.h>
#include <fitsio.h>
}

using namespace std;

template<class T>
using DMatrix = Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>;

template<typename T>
class PixelType{
public:
  static const int type;
  static const int read_type;
};

template<typename T> const int PixelType<T>::type = 0;
template<typename T> const int PixelType<T>::read_type = 0;

template<> const int PixelType<unsigned char>::type = BYTE_IMG;
template<> const int PixelType<unsigned char>::read_type = TBYTE;

template<> const int PixelType<short>::type = SHORT_IMG;
template<> const int PixelType<short>::read_type = TSHORT;

template<> const int PixelType<int>::type = LONG_IMG;
template<> const int PixelType<int>::read_type = TINT;

template<> const int PixelType<long long>::type = LONGLONG_IMG;
template<> const int PixelType<long long>::read_type = TLONGLONG;

template<> const int PixelType<float>::type = FLOAT_IMG;
template<> const int PixelType<float>::read_type = TFLOAT;

template<> const int PixelType<double>::type = DOUBLE_IMG;
template<> const int PixelType<double>::read_type = TDOUBLE;

class FitsException : public exception {
public:
  FitsException(int s): _status(s){
    fits_get_errstatus(_status, _fitsError);
  }

  virtual const char* what() const throw() {
    return _fitsError;
  }

private:
  int _status;
  char _fitsError[FLEN_STATUS];
};

template <class ExceptT>
void close_and_throw(fitsfile *fptr, const ExceptT& e){
  int status;
  fits_close_file(fptr, &status);
  throw e;
}

template<typename T>
DMatrix<T> read_image(const string& file_name, int extension=0, bool pixel_convert = false){

  stringstream ss;
  fitsfile *fptr;
  int bitpix;
  int status = 0;
  int naxis;
  long naxes[2];

  ss << file_name << "["<< extension << "]";

  fits_open_file(&fptr,ss.str().c_str() , READONLY, &status);
  if(status) throw FitsException(status);

  fits_get_img_param(fptr, 2,  &bitpix, &naxis, naxes, &status);
  if(status) close_and_throw(fptr, FitsException(status));

  if(!pixel_convert && PixelType<T>::type != bitpix) close_and_throw(fptr, domain_error("wrong pixel type requested"));
  if(naxis != 2) close_and_throw(fptr, domain_error("non 2D image"));

  DMatrix<T> m(naxes[0],naxes[1]);

  long fpixel[] = {1,1};
  int anynull;
  fits_read_pix(fptr,PixelType<T>::read_type , fpixel, naxes[0]*naxes[1],NULL,m.data(), &anynull, &status);

  if(status) close_and_throw(fptr, FitsException(status));

  fits_close_file(fptr, &status);
  return m;
}


int main(int argc, char *argv[])
{
  DMatrix<short> m = read_image<short>("../src/ex31/sample.fits");
  cout << m << endl;
}
