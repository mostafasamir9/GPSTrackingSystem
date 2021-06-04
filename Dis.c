#include "Dis.h"
#include "math.h"
#define PI 3.14159265

//Function to calculate distance between two points using haverside algorithm in (degree.min)
uint32_t Dis(double long1,double lat1,double long2,double lat2){
	const int32_t r = 6371;
	int32_t x = (long2 - long1) * (PI / 180);
	int32_t y = (lat2 - lat1) * (PI / 180);
	double a = sin(y/2) * sin(y/2) + cos(lat1 * (PI / 180)) * cos(lat2 * (PI / 180)) * sin(x/2) * sin(x/2);
	double i = squrt(a);
	double j = squrt(1-a);
	double c = 2 * atan2(i,j);
	double d = r * c * 1000;
	uint32_t dis = (uint32_t) ceil(d);
	return dis; 
}
