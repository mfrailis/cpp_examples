
#ifndef GUARD_IMAGE_H
#define GUARD_IMAGE_H

#include <cstddef>
#include <limits>
#include <iostream>
#include <memory>

namespace dimg {

// Image class to handle generic bi-dimensional pixel arrays
template <class PixelT>
class Image {
public:
  // Definition of type aliases used by the class
  using size_type = std::size_t;
  using const_iterator = const PixelT*;
  using iterator = PixelT*;

  // Default constructor
  Image(): _width(0), _height(0), _pix_array(nullptr) {}
  // Constructor requiring the number of rows and columns
  Image(size_type width, size_type height)
    : _width(width), _height(height) {_pix_array = new PixelT[_width * _height];}
  // Copy constructor
  Image(const Image& img)
    : _width(img._width), _height(img._height) {create(img.begin(), img.end());}

  // Destructor
  ~Image() {uncreate();}

  // Call operator, to access each pixel
  PixelT& operator()(size_type i, size_type j) {return _pix_array[i*_width + j];}
  const PixelT& operator()(size_type i, size_type j) const
        {return _pix_array[i*_width + j];}

  // Assignment operator
  Image& operator=(const Image& rhs);
  // Fill image with value val
  Image& operator=(const PixelT val);

  // Total number of pixels and image dimensions
  size_type size() const {return _width*_height;}
  size_type width() const {return _width;}
  size_type height() const {return _height;}

  // Iterators
  iterator begin() {return _pix_array;}
  const_iterator begin() const {return _pix_array;}

  iterator end() {return _pix_array + size();}
  const_iterator end() const {return _pix_array + size();}

protected:
  // Helper functions to create and destroy class instances
  void create(const_iterator istart, const_iterator iend);
  void uncreate();

private:
  // Private attributes
  size_type _width, _height;
  PixelT* _pix_array;
};


template<class PixelT>
std::istream& operator<<(std::istream& is, const Image<PixelT>& img);


// Mask class to handle generic bi-dimensional bitset arrays
template<class MaskPixT>
class Mask: public Image<MaskPixT> {
public:
  using Super = Image<MaskPixT>;
  using typename Super::size_type;

  // Default constructor
  Mask() {}
  // Constructor requiring image dimensions and maximum bit plane
  Mask(size_type width, size_type height,
       size_type maxBitPlane = std::numeric_limits<MaskPixT>::digits)
    : Super(width, height), _maxBitPlane(maxBitPlane)  {}
  // Copy constructor
  Mask(const Mask& rhs): Super(rhs), _maxBitPlane(rhs._maxBitPlane) {}

  // Assignment operators
  Mask& operator=(const Mask& rhs);
  Mask& operator=(const MaskPixT val);

  // Method to get a specific bit of the image
  bool getBitAt(size_type i, size_type j, size_type bitPlane) const
    {return this->operator()(i,j) & getBitMask(bitPlane);}
  // Operator performing a bitwise-or with another mask
  Mask& operator|=(const Mask& rhs);

private:
  // Helper function to compute bit plane mask
  MaskPixT getBitMask(size_type bitPlane)
    {return (bitPlane >= 0 && bitPlane < _maxBitPlane) ? 1 << bitPlane : 0; }

  size_type _maxBitPlane;
};



}

#include "image.cpp"


#endif // end of GUARD_IMAGE_H
