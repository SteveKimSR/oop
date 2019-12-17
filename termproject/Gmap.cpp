#include "Gmap.h"
#include "pointer.h"
#include "block.h"

int count = 0;

pointer temp[15]; 

Gmap::Gmap(){}

void Gmap::init(){	
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 5; j++){
			this->field[i][j] = 0;
		}
	}
}

void Gmap::print(){
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 5; j++){
			std::cout <<"   "<< this->field[i][j];
		}
		std::cout <<""<<std::endl;
		std::cout <<""<<std::endl;
	}
}

bool Gmap::checkAvaliable(block* b, pointer* p){
	int t = b->type();
	int s = b->get_shape();
	if(t == 1){
		if(s == 1){
			if((this->field[p->get_y()][p->get_x()] == 0) && (this->field[p->get_y()][p->get_x()+1] == 0)){
				return true;
			}
		}else if(s == 2){
			if((this->field[p->get_y()][p->get_x()] == 0) && (this->field[p->get_y()][p->get_x()+1] == 0)){
				return true;
			}
		}else if(s == 3){
			if(this->field[p->get_y()][p->get_x()] == 0){
				return true;
			}
		}else if(s == 4){
			if(this->field[p->get_y()][p->get_x()+1] == 0){
				return true;
			}
		}
	}else if(t == 2){
		if((s == 1) || (s == 3)){
			if(this->field[p->get_y()+1][p->get_x()] == 0){
				return true;
			}
		}else if((s == 2) || (s == 4)){
			if((this->field[p->get_y()][p->get_x()-1] == 0) && (this->field[p->get_y()][p->get_x()] == 0) &&(this->field[p->get_y()][p->get_x()+1] == 0)){
				return true;
			}
		}
	}else if(t == 3){
		if((this->field[p->get_y()][p->get_x()-1] == 0) && (this->field[p->get_y()][p->get_x()+1] == 0) && (this->field[p->get_y()+1][p->get_x()] == 0)){
			return true;
		}
	}
	return false;
}

void Gmap::insertBlock(block* b, pointer* p){
	int x = p->get_x();
	int y = p->get_y();
	if(b->type() == 1){
		if(b->get_shape() == 1){
			this->field[y-1][x+1] = b->get_color(0);
			this->field[y][x+1] = b->get_color(1);
			this->field[y][x] = b->get_color(2);
		}else if(b->get_shape() == 2){
			this->field[y][x+1] = b->get_color(0);
			this->field[y][x] = b->get_color(1);
			this->field[y-1][x] = b->get_color(2);
		}else if(b->get_shape() == 3){
			this->field[y][x] = b->get_color(0);
			this->field[y-1][x] = b->get_color(1);
			this->field[y-1][x+1] = b->get_color(2);
		}else if(b->get_shape() == 4){
			this->field[y-1][x] = b->get_color(0);
			this->field[y-1][x+1] = b->get_color(1);
			this->field[y][x+1] = b->get_color(2);
		}
	}else if(b->type() == 2){
		if(b->get_shape() == 1){
			this->field[y-1][x] = b->get_color(0);
			this->field[y][x] = b->get_color(1);
			this->field[y+1][x] = b->get_color(2);
		}else if(b->get_shape() == 2){
			this->field[y][x+1] = b->get_color(0);
			this->field[y][x] = b->get_color(1);
			this->field[y][x-1] = b->get_color(2);
		}else if(b->get_shape() == 3){
			this->field[y+1][x] = b->get_color(0);
			this->field[y][x] = b->get_color(1);
			this->field[y-1][x] = b->get_color(2);
		}else if(b->get_shape() == 4){
			this->field[y][x-1] = b->get_color(0);
			this->field[y][x] = b->get_color(1);
			this->field[y][x+1] = b->get_color(2);
		}
	}else if(b->type() == 3){
		if(b->get_shape() == 1){
			this->field[y-1][x] = b->get_color(0);
			this->field[y][x-1] = b->get_color(1);
			this->field[y][x] = b->get_color(2);
			this->field[y][x+1] = b->get_color(3);
			this->field[y+1][x] = b->get_color(4);
		}else if(b->get_shape() == 2){
			this->field[y][x+1] = b->get_color(0);
			this->field[y-1][x] = b->get_color(1);
			this->field[y][x] = b->get_color(2);
			this->field[y+1][x] = b->get_color(3);
			this->field[y][x-1] = b->get_color(4);
		}else if(b->get_shape() == 3){
			this->field[y+1][x] = b->get_color(0);
			this->field[y][x+1] = b->get_color(1);
			this->field[y][x] = b->get_color(2);
			this->field[y][x-1] = b->get_color(3);
			this->field[y-1][x] = b->get_color(4);
		}else if(b->get_shape() == 4){
			this->field[y][x-1] = b->get_color(0);
			this->field[y+1][x] = b->get_color(1);
			this->field[y][x] = b->get_color(2);
			this->field[y-1][x] = b->get_color(3);
			this->field[y][x+1] = b->get_color(4);
		}
	}
}
void Gmap::removeBlock(block* b, pointer* p){
	int x = p->get_x();
	int y = p->get_y();
	if(b->type() == 1){
		if(b->get_shape() == 1){
			this->field[y-1][x+1] = 0;
			this->field[y][x+1] = 0;
			this->field[y][x] = 0;
		}else if(b->get_shape() == 2){
			this->field[y][x+1] = 0;
			this->field[y][x] = 0;
			this->field[y-1][x] = 0;
		}else if(b->get_shape() == 3){
			this->field[y][x] = 0;
			this->field[y-1][x] = 0;
			this->field[y-1][x+1] = 0;
		}else if(b->get_shape() == 4){
			this->field[y-1][x] = 0;
			this->field[y-1][x+1] = 0;
			this->field[y][x+1] = 0;
		}
	}else if(b->type() == 2){
		if((b->get_shape() == 1) || (b->get_shape() == 3)){
			this->field[y-1][x] = 0;
			this->field[y][x] = 0;
			this->field[y+1][x] = 0;
		}else if((b->get_shape() == 2) || (b->get_shape() == 4)){
			this->field[y][x+1] = 0;
			this->field[y][x] = 0;
			this->field[y][x-1] = 0;
		}
	}else if(b->type() == 3){
			this->field[y-1][x] = 0;	
			this->field[y][x-1] = 0;	
			this->field[y][x] = 0;	
			this->field[y][x+1] = 0;	
			this->field[y+1][x] = 0;	
	}
}

void Gmap::dropBlock(block* b, pointer* p){

	int type = b->type();
	int s = b->get_shape();
	int x = p->get_x();
	
	if(type == 1){
		if(s == 1){
			this->field[this->checkEnd(x+1)][x+1] = b->get_color(1);
			this->field[this->checkEnd(x+1)][x+1] = b->get_color(0);
			this->field[this->checkEnd(x)][x] = b->get_color(2);
		}else if(s == 2){
			this->field[this->checkEnd(x+1)][x+1] = b->get_color(0);
			this->field[this->checkEnd(x)][x] = b->get_color(1);
			this->field[this->checkEnd(x)][x] = b->get_color(2);
		}else if(s == 3){
			this->field[this->checkEnd(x)][x] = b->get_color(0);
			this->field[this->checkEnd(x)][x] = b->get_color(1);
			this->field[this->checkEnd(x+1)][x+1] = b->get_color(2);
		}else if(s == 4){
			this->field[this->checkEnd(x)][x] = b->get_color(0);
			this->field[this->checkEnd(x+1)][x+1] = b->get_color(2);
			this->field[this->checkEnd(x+1)][x+1] = b->get_color(1);
		}

	}else if(type == 2){
		if(s == 1){
			this->field[this->checkEnd(x)][x] = b->get_color(2);
			this->field[this->checkEnd(x)][x] = b->get_color(1);
			this->field[this->checkEnd(x)][x] = b->get_color(0);
		}else if(s == 2){
			this->field[this->checkEnd(x+1)][x+1] = b->get_color(0);
			this->field[this->checkEnd(x)][x] = b->get_color(1);
			this->field[this->checkEnd(x-1)][x-1] = b->get_color(2);
		}else if(s == 3){
			this->field[this->checkEnd(x)][x] = b->get_color(0);
			this->field[this->checkEnd(x)][x] = b->get_color(1);
			this->field[this->checkEnd(x)][x] = b->get_color(2);
		}else if(s == 4){
			this->field[this->checkEnd(x-1)][x-1] = b->get_color(0);
			this->field[this->checkEnd(x)][x] = b->get_color(1);
			this->field[this->checkEnd(x+1)][x+1] = b->get_color(2);
		}
	}else if(type == 3){
		if(s == 1){
			this->field[this->checkEnd(x)][x] = b->get_color(4);
			this->field[this->checkEnd(x-1)][x-1] = b->get_color(1);
			this->field[this->checkEnd(x)][x] = b->get_color(2);
			this->field[this->checkEnd(x+1)][x+1] = b->get_color(3);
			this->field[this->checkEnd(x)][x] = b->get_color(0);
		}else if(s == 2){
			this->field[this->checkEnd(x)][x] = b->get_color(3);
			this->field[this->checkEnd(x-1)][x-1] = b->get_color(4);
			this->field[this->checkEnd(x)][x] = b->get_color(2);
			this->field[this->checkEnd(x+1)][x+1] = b->get_color(0);
			this->field[this->checkEnd(x)][x] = b->get_color(1);
		}else if(s == 3){
			this->field[this->checkEnd(x)][x] = b->get_color(0);
			this->field[this->checkEnd(x-1)][x-1] = b->get_color(3);
			this->field[this->checkEnd(x)][x] = b->get_color(2);
			this->field[this->checkEnd(x+1)][x+1] = b->get_color(1);
			this->field[this->checkEnd(x)][x] = b->get_color(4);
		}else if(s == 4){
			this->field[this->checkEnd(x)][x] = b->get_color(1);
			this->field[this->checkEnd(x-1)][x-1] = b->get_color(0);
			this->field[this->checkEnd(x)][x] = b->get_color(2);
			this->field[this->checkEnd(x+1)][x+1] = b->get_color(4);
			this->field[this->checkEnd(x)][x] = b->get_color(3);
		}
	}
}
int Gmap::checkEnd(int x){
	int temp = 11;
	while(this->field[temp][x] != 0){
		temp--;
	}
	return temp;
}
bool Gmap::checkCollision(block* b, pointer* p){
	int type = b->type();
	int s = b->get_shape();
	int x = p->get_x();
	int y = p->get_y();
	int fy = 0;

	if(type == 1){
		if(s == 1){
			if((y+1) == 12){
				return true;
			}
		if((checkEnd(x) == y) || (checkEnd(x+1) == y)){
			return true;
		}
		}else if(s == 2){
			if((checkEnd(x) == y) || (checkEnd(x+1) == y)){
				return true;
			}
		}else if(s == 3){
			if((checkEnd(x) == y) || (checkEnd(x+1) == y-1)){
				return true;
			}
		}else if(s == 4){
			if((checkEnd(x) == y-1) || (checkEnd(x+1) == y)){
				return true;
			}
		}
	}else if(type == 2){
		if((s == 1) || (s == 3)){
			if((y+2) == 12){
				return true;
			}
			if(checkEnd(x) == y+1){
				return true;
			}
		}else if((s == 2) || (s == 4)){
			if((y+1) == 12){
				return true;
			}
			if((checkEnd(x-1) == y) || (checkEnd(x) == y) || (checkEnd(x+1) == y)){
				return true;
			}
		}
	}else if(type == 3){
		if((y+2) == 12){
			return true;
		}
		if((checkEnd(x-1) == y)||(checkEnd(x) == y+1)|| (checkEnd(x+1) == y)){
			return true;
		}
	}
	return false;
}

bool Gmap::explode(){
	int flag = 0;

	bool visited[12][5] = {false, };	// for checking if already used


	for(int i = 11; i > 0; i--){
		for(int j = 4; j > 0; j--){		
			if(!visited[i][j]){
				visited[i][j] = true;
				if((this->field[i][j] != 0) && (this->field[i][j] != 1)){
					count = 0;
					this->visitAll(i, j, temp, visited);
					if(count >= 3){
						for(int m = 0; m < count+1; m++){
							this->field[temp[m].get_y()][temp[m].get_x()] = 0;
							this->visitOne(temp[m].get_y(), temp[m].get_x());
						}
					flag++;
					}
				}
			}
		}
	}
	if(flag == 0)
		return false;
	else
		return true;
}

void Gmap::visitAll(int y, int x, pointer* temp, bool visited[12][5]){
	temp[count] = pointer(x,y);
	if(y != 0){
		if((!visited[y-1][x]) && (this->field[y][x] == this->field[y-1][x])){
			visited[y-1][x] = true;
			count++;
			temp[count] = pointer(y-1,x);
			this->visitAll(y-1, x, temp, visited);
		}
	}
	if(y != 11){
		if((!visited[y+1][x]) && (this->field[y][x] == this->field[y+1][x])){
			visited[y+1][x] = true;
			count++;
			temp[count] = pointer(y+1,x);
			this->visitAll(y+1, x, temp, visited);
		}
	}
	if(x != 0){
		if((!visited[y][x-1]) && this->field[y][x] == this->field[y][x-1]){
			visited[y][x-1] = true;
			count++;
			temp[count] = pointer(y,x-1);
			this->visitAll(y, x-1, temp, visited);
		}
	}
	if(x != 4){
		if((!visited[y][x+1]) && this->field[y][x] == this->field[y][x+1]){
			visited[y][x+1] = true;
			count++;
			temp[count] = pointer(y,x+1);
			this->visitAll(y, x+1, temp, visited);
		}
	}
}
void Gmap::visitOne(int y, int x){
	if(y != 0){
		if(this->field[y-1][x] == 1){
			this->field[y-1][x] = 0;
		}
	}
	if(y != 11){
		if(this->field[y+1][x] == 1){
			this->field[y+1][x] = 0;
		}
	}
	if(x != 0){
		if(this->field[y][x-1] == 1){
			this->field[y][x-1] = 0;
		}
	}
	if(x != 4){
		if(this->field[y][x+1] == 1){
			this->field[y][x+1] = 0;
		}
	}
}

void Gmap::makeClean(){
	for(int i = 0; i < 5; i++){
		int clone[12] = {0,};
		int y = 11;
		for(int j = 11; j > 0; j--){
			if(this->field[j][i] != 0){
				clone[y] = this->field[j][i];
				y--;
			}
		}
		for(int l = 11; l > 0; l--){
			this->field[l][i] = clone[l];
		}
	}
}
