#include <iostream>
#include <fstream>

#include "headers/Table.hpp"

using namespace std;

int main()
{
    setlocale(0, "");
	string path = "config/input.txt";

    ifstream in(path);
    if (!in.good()) return 1;

    in.seekg(0, std::ios::end);
    int fileSize = in.tellg();
    in.seekg(0, std::ios::beg);

    char* str = new char[fileSize]();

    in.read(str, fileSize);

    in.close();

    char* nextToken = nullptr;
    char* token = strtok_s(str, " ,.-;()?:=&^%$#@!\"\n", &nextToken);
    
    Table* mytable = new Table();

    while (token != nullptr) {
        std::string temp = token;
        if (temp.size() > 1)
        {
            mytable->insert(temp);
        }
        token = strtok_s(nullptr, " ,.-;()?:=&^%$#@!\"\n", &nextToken);
    }

    string word_to_search;
    mytable->print();

    std::string answer;
    bool running = true;
    while (running)
    {
        cout << "Enter a word: ";
        cin >> word_to_search;
        cout << "Search results: ";
        mytable->lookup(word_to_search);
        cout << "\nRepeat? Y/N: ";
        cin >> answer;
        running = (strcmp(answer.c_str(), "N") == 0) ? false : true;
    }
    
    delete[] str;

	return 0;
}