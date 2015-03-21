
#ifndef GUARD_IMAGE_CPP
#define GUARD_IMAGE_CPP

#include "image.h"

#include <algorithm>
#include <stdexcept>
#include <functional>

namespace dimg {


template <class PixelT>
void Image<PixelT>::create(const_iterator istart, const_iterator iend)
{
  _pix_array = new PixelT[iend - istart];
  std::copy(istart, iend, _pix_array);
}


template <class PixelT>
void Image<PixelT>::uncreate()
{
  delete[] _pix_array;
  _pix_array = nullptr;
  _width = _height = 0;
}


template <class PixelT>
Image<PixelT>& Image<PixelT>::operator=(const Image& rhs)
{
  // check for self-assignment
  if (&rhs != this) {
    // free the array in the left-hand side
    uncreate();
    // copy pixels from rhs
    create(rhs.begin(), rhs.end());
    // copy dimensions
    _width = rhs._width;
    _height = rhs._height;
  }
  return *this;
}


template <class PixelT>
Image<PixelT>& Image<PixelT>::operator=(const PixelT val)
{
  std::fill(begin(), end(), val);
  return *this;
}


template<class PixelT>
std::ostream& operator<<(std::ostream& is, const Image<PixelT>& img)
{
  using size_type = typename Image<PixelT>::size_type;

  for (size_type i = 0; i < img.height(); ++i) {
    for (size_type j = 0; j < img.width(); ++j)
      is << img(i,j) << " ";
    is << std::endl;
  }
  return is;
}


template <class MaskPixT>
Mask<MaskPixT>& Mask<MaskPixT>::operator=(const Mask& rhs)
{
  Super::operator=(rhs);
  _maxBitPlane = rhs._maxBitPlane;
  return *this;
}


template <class MaskPixT>
Mask<MaskPixT>& Mask<MaskPixT>::operator=(const MaskPixT val)
{
  Super::operator=(val);
  return *this;
}


template <class MaskPixT>
Mask<MaskPixT>& Mask<MaskPixT>::operator|=(const Mask& rhs)
{
  if (Super::width() != rhs.width() || Super::height() != rhs.height())
    throw std::length_error("Images are of different size");

  std::transform(rhs.begin(), rhs.end(), Super::begin(), Super::begin(),
                 std::bit_or<MaskPixT>());
  return *this;
}

}

#endif // end of GUARD_IMAGE_CPP
