#include "serialize.hpp"

int main()
{
	Data		data;
	uintptr_t	ptr; // uint 로 포인터(주소값)를 표현하기 때문에 10진법으로 나옴.
	Data*		ptrData;

	data.c = 'a';
	data.d = 2.2;
	data.i = 42;

	ptr = serialize(&data); // Data 타입을 uintptr_t 포인터 타입으로 변환.
	ptrData = deserialize(ptr); // uintptr_t 타입이 된 ptr 를 Data* 타입으로 변환.

	std::cout << &data << std::endl;
	std::cout << ptr << std::endl;
	std::cout << "0x" << std::hex << ptr << std::dec << std::endl;
	std::cout << ptrData << std::endl;
	std::cout << data.c << " " << data.d << " " << data.i << std::endl;
	std::cout << ptrData->c << " "<< ptrData->d << " " << ptrData->i << std::endl;

	return (0);
}
// Data 타입을 uintptr_t 에 변환시켜 저장하고 다시 Data *로 받아 void* 처럼? 사용할 수 있게 할 수 있다는
// 개념을 알려주는 과제.