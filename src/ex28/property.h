
#ifndef GUARD_PROPERTY_H
#define GUARD_PROPERTY_H

#include <string>

class Property {
public:
  Property(const std::string& name): _name(name) {}
  const std::string& name() const {return _name;}

  virtual ~Property() {}  // virtual destructor

  virtual double getValueAsDouble() const = 0;
  virtual int getValueAsInt() const = 0;
  virtual std::string getValueAsString() const = 0;
private:
  std::string _name;
};

class DoubleProperty: public Property  {
public:
  DoubleProperty(const std::string& name, double value)
    : Property(name), _value(value) {}

  double getValueAsDouble() const {return _value;}
  int getValueAsInt() const {return static_cast<int>(_value);}
  std::string getValueAsString() const;

private:
  double _value;
};

class IntProperty: public Property  {
public:
  IntProperty(const std::string& name, int value)
    : Property(name), _value(value) {}

  double getValueAsDouble() const {return _value;}
  int getValueAsInt() const {return _value;}
  std::string getValueAsString() const;

private:
  int _value;
};

class StringProperty: public Property  {
public:
  StringProperty(const std::string& name, const std::string& value)
    : Property(name), _value(value) {}

  double getValueAsDouble() const;
  int getValueAsInt() const;
  std::string getValueAsString() const {return _value;}

private:
  std::string _value;
};


Property* createProperty(const std::string& name, double value);
Property* createProperty(const std::string& name, int value);
Property* createProperty(const std::string& name, const std::string& value);




#endif // end of GUARD_PROPERTY_H
