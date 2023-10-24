#include "TreeNode.hpp"

#ifndef WORD_TABLE_HEADERS_TABLE_HPP
#define WORD_TABLE_HEADERS_TABLE_HPP

class Table
{
    std::string m_name;
    TreeNode* ptr_treenode;
private:
    void to_lowercase(std::string* word);
public:
    Table();
    ~Table();
    
    void lookup(std::string word);
    void insert(std::string word);
    void remove(std::string word);
    void print();
};

#endif // !WORD_TABLE_HEADERS_TABLE_HPP