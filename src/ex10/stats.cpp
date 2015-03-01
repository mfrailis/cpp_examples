
#include "stats.h"
#include <stdexcept>
#include <algorithm>

using std::vector;
using std::nth_element;
using std::max_element;
using std::domain_error;


double median(std::vector<double> samples)
{
  auto size = samples.size();
  if (!size)
    throw std::domain_error("Computing median on an empty vector");

  auto pos = size/2;

  // using the nth_element standard algorithm to find the median in O(n)
  nth_element(samples.begin(), samples.begin() + pos, samples.end());

  // if the number of elements is even the median is computed as the mean
  // of the two middle values
  if (size%2)
    return samples[pos];
  else
    // max_element standard algorithm finds the maximum value of a sequence
    return (samples[pos] + (*max_element(samples.begin(),
            samples.begin() + pos)))/2;
}


double mean(const vector<double>& samples)
{
  auto size = samples.size();

  if (size == 0)
    throw domain_error("mean of an empty vector");

  double sum = 0;
  for (const auto& x : samples)
    sum += x;
  return sum/size;
}
