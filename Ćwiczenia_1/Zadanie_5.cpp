#include <iostream>
#include <stdio.h>



int main()
{
	int numer = 10;
	int suma = 0;
	if (numer <= 2) {
		printf("0");
	}
	else {
		for (int i = 0; i < numer; i++) {
			if (i % 3 == 0 or i % 5 == 0) {
				printf("%d\n", i);
				suma += i;
			}
		}
	}
	printf("%d", suma);
	return 0;
}

