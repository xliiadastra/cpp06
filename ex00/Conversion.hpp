#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <cmath>

class Conversion
{
private:
    char    _valueChar;
    int     _valueInt;
    float   _valueFloat;
    double  _valueDouble;

public:
    Conversion();
    Conversion(const char* str);
    Conversion(const Conversion& src);
    Conversion& operator=(const Conversion& src);
    ~Conversion();

    char    getChar() const;
    int     getInt() const;
    float   getFloat() const;
    double  getDouble() const;
};

std::ostream& operator<<(std::ostream& outputStream, const Conversion &src);

#endif