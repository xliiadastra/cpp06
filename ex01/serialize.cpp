#include "serialize.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
} // reinterpret_cast (타입캐스트 연산자) : 임의의 포인터 타입끼리 변환을 허용해줌.

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}