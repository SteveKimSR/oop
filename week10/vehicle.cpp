#include "vehicle.h"

vehicle::vehicle(){
	has_name = false;
	wheel_number = 0;
	max_speed = 0;
}
vehicle::vehicle(int wn, int ms){
	has_name = false;
	wheel_number = wn;
	max_speed = ms;
}
vehicle::vehicle(int wn, int ms, bool hn){
	has_name = hn;
	wheel_number = wn;
	max_speed = ms;
}
int vehicle::get_wheel_number(){
	return this->wheel_number;
}
int vehicle::get_max_speed(){
	return this->max_speed;
}
bool vehicle::get_has_name(){
	return this->has_name;
}
const char* vehicle::get_class_name(){
	return "vehicle";
}
void vehicle::set_wheel_number(int wn){
	wheel_number = wn;
}
void vehicle::set_max_speed(int ms){
	max_speed = ms;
}
void vehicle::set_has_name(bool hn){
	has_name = hn;
}
