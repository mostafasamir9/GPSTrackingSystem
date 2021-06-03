#include "Calculations.h"

uint32_t absolute(int32_t num){
	return (num >= 0)? num: -1*num;
}

uint32_t Short_Distance(int32_t prev_x, int32_t prev_y, int32_t cur_x, int32_t cur_y){
	uint32_t Distance = 0;
	Distance += absolute(cur_y - prev_y);
	Distance += absolute(cur_x - prev_x);
	return Distance;
}
/*
uint32_t Total_Distance(uint32_t Dis, uint32_t size, int32_t arrx[], int32_t arry[]){
	uint32_t i;
	for(i=1; i<size-1; i++){
		Dis += Short_Distance(arrx[i-1], arry[i-1], arrx[i], arry[i]);
	}
	return Dis;
}*/
