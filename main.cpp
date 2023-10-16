#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>

using namespace std;

int main()
{
	string path = "config/input.txt";

    ifstream in(path);
    if (!in.good()) return 1;

    in.seekg(0, std::ios::end);
    int fileSize = in.tellg();
    in.seekg(0, std::ios::beg);

    char* str = new char[fileSize];

    in.read(str, fileSize);

    in.close();

    char* nextToken = nullptr;
    char* token = strtok_s(str, " ,.-;()?:=&^%$#@!\"", &nextToken);

    while (token != nullptr) {
        std::cout << token << std::endl;
        token = strtok_s(nullptr, " ,.-;()?:=&^%$#@!\"", &nextToken);
    }
    delete[] str;

    system("pause");

	return 0;
}