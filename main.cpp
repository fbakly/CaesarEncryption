#include "include.hpp"
using namespace std;

int main(int argc, char **argv)
{
	info();

	char *filepath = getFilepath();
	char* option = getOption();
	int key = getKey();
	FILE *file;
	size_t size;
	char *buffer;
	char *result;
	ofstream resultFile;

	if (!(file = fopen(filepath, "r"))) {
		cout << "\n\tFile could not be opened\n\n";
		return (84);
	}
	size = getFileSize(file);
	buffer = setBuffer(file,size);
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
