#include "include.hpp"
using namespace std;

int main(int argc, char **argv)
{
	info();

	char *filepath = getFilepath();
	char* option = getOption();
	int key = getKey();
	FILE *file = fopen(filepath, "r");
	size_t size = getFileSize(file);
	char *buffer = setBuffer(file, size);
	char *result;
	ofstream resultFile;

	if (option == "-e")
		result = encrypt(buffer, key, size);
	else
		result = decrypt(buffer, key, size);

	resultFile.open("result.txt");
	resultFile << result;

	resultFile.close();
	fclose(file);
	delete [] buffer;
	delete [] result;
	return (0);
}
