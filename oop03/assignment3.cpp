#include <iostream>

int main(){
	char target[] = "Kim SungRyeol";
	long b[27];
	int a = 17;
	int i = 243;
	int *c = new int[502];
	const char * copy = "is no no";
	char name = 'a';
	
	std::cout << (void*)&name  << std::endl;	//
	std::cout << &a << std::endl;				
	std::cout << &i << std::endl;				
	std::cout << &c << std::endl;				
	std::cout << &copy << std::endl;			
	std::cout << &b << std::endl;				
	std::cout << &target << std::endl;		
	std::cout << &name+i << std::endl;
}
