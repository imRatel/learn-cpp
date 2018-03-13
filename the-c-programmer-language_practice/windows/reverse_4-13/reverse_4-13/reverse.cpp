#include <stdio.h>

void reverse(char s[], int low, int high)
{
	int sign;
	if (low > high)
		return;
	
	sign = s[low];
	s[low] = s[high];
	s[high] = sign;

	reverse(s, low + 1, high - 1);
}