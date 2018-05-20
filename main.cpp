#include "include.hpp"
using namespace std;

int main(int argc, char **argv)
{
	errors(argc);

	char *filepath = argv[1];
	int key = atoi(argv[2]);
	FILE *file = fopen(filepath, "r");
	size_t size = getFileSize(file);
	char *buffer = setBuffer(file, size);
	char *result;
	ofstream resultFile;

	if (key >= 0)
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
