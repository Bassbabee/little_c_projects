#include <stdio.h>

int main()
{
	int number_of_problems, x, y, z;
	int numer_of_solutions = 0;
	scanf("%d", &number_of_problems);
	for (int i = 0; i < number_of_problems; ++i){
		scanf("%d %d %d", &x, &y, &z);
		if (x + y + z >= 2)
			numer_of_solutions++;
	}
	printf("%d", numer_of_solutions);
	return 0;
}
