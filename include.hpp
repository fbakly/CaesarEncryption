#ifndef _MY_ALGORITHMS_HPP__
# define _MY_ALGORITHMS_HPP__

#include <iostream>
#include <fstream>
#include <cstdlib>

void errors(int argc);
size_t getFileSize(FILE *file);
char *setBuffer(FILE *file, size_t size);
char *encrypt(char *buffer, int key, size_t size);
char *decrypt(char *buffer, int key, size_t size);
int main(int argc, char **argv);

#endif
