#include "include.hpp"

using namespace std;

void errors(int argc)
{
	if (argc < 3)
		exit(EXIT_FAILURE);
}

size_t getFileSize(FILE *file)
{
	//get file size
	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);
	return (size);
}

char *setBuffer(FILE *file, size_t size)
{
	// Create the buffer
	char *buffer = new char [size];
	// Set file to beginning
	rewind(file);
	// Read file contents to buffer
	fread(buffer, sizeof(char), size, file);
	return (buffer);
}
