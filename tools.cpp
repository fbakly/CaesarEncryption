#include "include.hpp"

using namespace std;

void info()
{
	cout << "\n\t./caesar -option filename key\n\n";
	cout << "\tOptions:\n";
	cout << "\t\t-e to encrypt\n";
	cout << "\t\t-d to decrypt\n\n";
}

char *getFilepath()
{
	char *filepath = new char[50];

	cout << "Please enter filename: ";
	cin >> filepath;
	return (filepath);
}

char *getOption()
{
	char* option = new char [2];

	do {
		cout << "Please enter option: ";
		cin >> option;
	} while (strncmp(option, "-e", 2) != 0 && strncmp(option, "-d", 2) != 0);
	return option;
}

int getKey()
{
	int key;

	while (key > 26 || key < 0) {
		cout << "Please enter a key between 0 and 26: ";
		cin >> key;
	}
	return (key);
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
