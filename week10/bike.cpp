#include "bike.h"

bike::bike(){
	bike_name = nullptr;
	bike_number = 0;
}
bike::bike(int wn, int ms) : vehicle(wn, ms){}

bike::bike(int wn, int ms, char* bname) : vehicle(wn, ms){
	bike_name = bname;
}
bike::bike(int wn, int ms, char* bname, int bnumber) : vehicle(wn, ms){
	bike_name = bname;
	bike_number = bnumber;
}
bike::bike(int wn, int ms, char* bname, int bnumber, bool hn) : vehicle(wn, ms, hn){
	bike_name = bname;
	bike_number = bnumber;
}
int bike::get_bike_number(){
	return bike_number;
}

char* bike::get_bike_name(){
	return bike_name;
}

const char* bike::get_class_name(){
	return "bike";
}

void bike::set_bike_name(char* bn){
	bike_name = bn;
}
void bike::set_bike_number(int bn){
	bike_number = bn;
}
