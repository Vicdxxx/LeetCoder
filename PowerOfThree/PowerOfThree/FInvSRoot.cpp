#include<iostream>
#include<cmath>

using namespace std;
float Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;
	x2 = number*0.5F;
	y = number;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y*(threehalfs - (x2*y*y));
	return y;
	
}
float FinvSqR(int x)
{
	long i = 0;
	float y = x;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y*(1.5F - (0.5F*x*y*y));
	y = y*(1.5F - (0.5F*x*y*y));

	return y;
}
void main2()
{
	
	
		
		float x = FinvSqR(4444);
		cout << x << endl;
	
	
	cin.get();
	cin.get();

}