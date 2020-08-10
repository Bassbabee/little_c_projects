#include <stdlib.h> // For malloc
#include <string.h> // For memset

int main(int argc, char** argv) {
	char* ptr = (char*)malloc(16 * sizeof(char));
	memset(ptr, 0, 16 * sizeof(char)); // Fill with 0
	memset(ptr, 0xff, 16 * sizeof(char)); // Fill with 0xff
	...
	free(ptr);
	return 0;
}


// realloc realocates memory
int main(int argc, char** argv) {
	char* ptr = (char*)malloc(16 * sizeof(char));
	...
	ptr = (char*)realloc(32 * sizeof(char));
	...
	free(ptr);
	return 0;
}
