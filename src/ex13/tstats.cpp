
#ifndef GUARD_TSTATS_CPP
#define GUARD_TSTATS_CPP

#include "tstats.h"
#include <stdexcept>

template <class T>
T max(const std::vector<T>& v)
{
  auto size = v.size();
  if (size == 0)
    throw std::domain_error("Error: max of an empty vector");

  T max_value = v[0];
  for (decltype(size) i = 1; i != size; ++i)
    if (max_value < v[i])
      max_value = v[i];

  return max_value;
}

#endif // end of GUARD_TSTATS_CPP
