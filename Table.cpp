#include "headers/Table.hpp"
#include <algorithm>
#include <iostream>

Table::Table()
{
	m_name = "Default table name";
	ptr_treenode = nullptr;
}

Table::~Table()
{
}

void Table::to_lowercase(std::string* word)
{
	std::transform(word->begin(), word->end(), word->begin(), tolower);
}

void Table::lookup(std::string word)
{
	to_lowercase(&word);
	ptr_treenode->lookup(word, ptr_treenode);
}

void Table::insert(std::string word)
{
	to_lowercase(&word);
	if (ptr_treenode == nullptr)
	{
		ptr_treenode = new TreeNode(word);
		return;
	}

	ptr_treenode->insert(word, ptr_treenode);
}

void Table::remove(std::string word)
{
	to_lowercase(&word);
	ptr_treenode->remove(word, ptr_treenode);
}

void Table::print()
{
	ptr_treenode->print(ptr_treenode);
}
