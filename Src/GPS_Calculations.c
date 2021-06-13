//---------------------------------------------------------//
/***********************************************************  
*  Describtion: Function used to convert array of character to double datatype 
**************************************************************/
double GPS_S_to_f(char *str, uint8_t size){
	int8_t i;
	double Num = 0.00;
	for(i = size; i > 0; i--){
		Num += pow(10, i-1) * (int32_t)(str[size-i] - 48);
	}
	for(i = -1; i >= -5; i--){
		Num += pow(10, i) * (int32_t)(str[size+(-1*i)] - 48);
	}
	Num /= pow(10, size-2);
	return Num;
}