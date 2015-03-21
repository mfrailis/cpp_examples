
#include "property.h"

#include <sstream>

std::string DoubleProperty::getValueAsString() const
{
  std::ostringstream os;
  os << _value;
  return os.str();
}

std::string IntProperty::getValueAsString() const
{
  std::ostringstream os;
  os << _value;
  return os.str();
}

int StringProperty::getValueAsInt() const
{
  std::istringstream is;
  int res;
  is >> res;
  return res;
}

double StringProperty::getValueAsDouble() const
{
  std::istringstream os;
  double res;
  os >> res;
  return res;
}



Property* createProperty(const std::string& name, double value)
{
  return new DoubleProperty(name, value);
}

Property* createProperty(const std::string& name, int value)
{
  return new IntProperty(name, value);
}

Property* createProperty(const std::string& name, const std::string& value)
{
  return new StringProperty(name, value);
}


