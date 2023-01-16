#include "Conversion.hpp"

Conversion::Conversion()
{
//    std::cout << "[Conversion] Default constructor called." << std::endl;
}

Conversion::Conversion(const char* str)
{
//    std::cout << "[Conversion] " << '[' << name << ']' << " constructor called." << std::endl;
	if (!str[1] && !std::isdigit(str[0])) // 한글자 변환시
		this->_valueDouble = (str[0]);
	else
		this->_valueDouble = std::strtod(str, NULL); // double에 넣어서 손실을 줄인다.-> strtod를 쓰기 위해서
	this->_valueChar = static_cast<char>(this->_valueDouble);
	this->_valueInt = static_cast<int>(this->_valueDouble);
	this->_valueFloat = static_cast<float>(this->_valueDouble);
}

Conversion::Conversion(const Conversion& src)
{
//    std::cout << "[Conversion] Copy constructor called." << std::endl;
    *this = src;
}

Conversion& Conversion::operator=(const Conversion& src)
{
//    std::cout << "[Conversion] Copy assignment operator called." << std::endl;
    if (this != &src)
    {
        this->_valueChar = src._valueChar;
        this->_valueInt = src._valueInt;
        this->_valueFloat = src._valueFloat;
        this->_valueDouble = src._valueDouble;
    }
    return (*this);
}

Conversion::~Conversion()
{
//    std::cout << "[Conversion] Destructor called." << std::endl;
}

char    Conversion::getChar(void) const
{
    return (this->_valueChar);
}

int     Conversion::getInt(void) const
{
    return (this->_valueInt);
}
float   Conversion::getFloat(void) const
{
    return (this->_valueFloat);
}

double  Conversion::getDouble(void) const
{
    return (this->_valueDouble);
}

bool isNan(double d)
{
	return (d != d); //
}

bool isInf(double d)
{
	return (d != 0 && d * 2 == d); // inf * inf 는 inf 니까
}

std::ostream& operator<<(std::ostream& outputStream, const Conversion& obj)
{
	if (isNan(obj.getDouble()) || isInf(obj.getDouble())
		|| obj.getDouble() > 127 || obj.getDouble() < 0) // char ascii에 벗어나는 문자
		std::cout << "char: impossible" << std::endl;
	else if ((0 <= obj.getDouble() && obj.getDouble() < 32) || obj.getDouble() == 127) // 출력 불가 문자
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << obj.getChar() << "'" << std::endl;

	if (isNan(obj.getDouble()) || isInf(obj.getDouble())) // int ascii에 벗어나는 문자
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << obj.getInt() << std::endl;

	std::cout << "float: " << obj.getFloat();
	if (static_cast<float>(obj.getInt()) == obj.getFloat()) // 0일 때
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << obj.getDouble();
	if (static_cast<double>(obj.getInt()) == obj.getDouble()) // 0일 때
		std::cout << ".0";
	std::cout << std::endl;
	return (outputStream);
}
