#include <stdio.h>

int main()
{
	int number_of_participants, place, participant;
	scanf("%d %d", &number_of_participants, &place);

	int* array_of_places = (int*)malloc(place * sizeof(int));

	for (int i = 0; i < place; ++i){
		scanf("%d ", &participant);
	}
	return 0;
}
