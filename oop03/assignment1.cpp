#include <iostream>

void code(){}

int Data = 1;

static const int Rodata = 1;

int Bss;

int main(){

	int* Heap = new int[1];
	int* Stack;

	std::cout << (void*)code << std::endl;
	std::cout << &Rodata << std::endl;
	std::cout << &Data << std::endl;
	std::cout << &Bss << std::endl;
	std::cout << Heap << std::endl;
	std::cout << &Stack << std::endl;

	return 0;
}
