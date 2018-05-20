#include "include.hpp"

using namespace std;

char *encrypt(char *buffer, int key, size_t size)
{
	char *result = new char [size];

	for (int i = 0; i < size - 1; ++i)
	{
		if ((buffer[i]>= 'A' && buffer[i] <= 'Z') &&
				(buffer[i] + key <= 'Z'))
			result[i] = buffer[i] + key;
		else if ((buffer[i] >= 'A' && buffer[i] <= 'Z') &&
						(buffer[i] + key > 'Z'))
			result[i] = 'A' + ('Z' - buffer[i] - 1);
		else if ((buffer[i]>= 'a' && buffer[i] <= 'z') &&
				(buffer[i] + key <= 'z'))
			result[i] = buffer[i] + key;
		else if ((buffer[i] >= 'a' && buffer[i] <= 'z') &&
						(buffer[i] + key > 'z'))
			result[i] = 'a' + ('z' - buffer[i] - 1);
		else
			result[i] = buffer[i] + key;
	}
	return (result);
}

char *decrypt(char *buffer, int key, size_t size)
{
	char *result = new char [size];
	key *= -1;

	for (int i = 0; i < size - 1; ++i)
	{
		if ((buffer[i] >= 'A' && buffer[i] <= 'Z') &&
				(buffer[i] - key >= 'A'))
			result[i] = buffer[i] - key;
		else if ((buffer[i] >= 'A' && buffer[i] <= 'Z') &&
						(buffer[i] - key < 'A'))
			result[i] = 'Z' - (buffer[i] - 'A' + 1);
		else if ((buffer[i]>= 'a' && buffer[i] <= 'z') &&
				(buffer[i] - key >= 'a'))
			result[i] = buffer[i] - key;
		else if ((buffer[i] >= 'a' && buffer[i] <= 'z') &&
						(buffer[i] - key < 'a'))
			result[i] = 'z' - (buffer[i] - 'a' + 1);
		else
			result[i] = buffer[i] - key;
	}
	return (result);
}
