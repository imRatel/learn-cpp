#include <stdio.h>
#include <math.h>

float Chanage_T_F_C (float T_F)
{
	float T_C=0;
	T_C=(T_F-32.0)*5.0/9.0;
	return T_C;
}

int main ()
{
	float in_f;
	printf("Please enter a temperature(F*).\n");
	scanf("%f",&in_f);
	printf("%f",Chanage_T_F_C(in_f));
	return 0;
}
