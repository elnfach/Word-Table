#include <string>

#ifndef WORD_TABLE_HEADERS_TREE_NODE_HPP
#define WORD_TABLE_HEADERS_TREE_NODE_HPP

class TreeNode
{
    std::string m_key;
    int m_counter;

    TreeNode* ptr_left;
    TreeNode* ptr_right;
private:
public:
    TreeNode();
    TreeNode(std::string word);
    ~TreeNode();

    void print(TreeNode* root);
    void lookup(std::string word, TreeNode* root);
    void insert(std::string word, TreeNode* root);
    TreeNode* remove(std::string word, TreeNode* root);
    TreeNode* maxNode(TreeNode* root);
    TreeNode* minNode(TreeNode* root);
};

#endif // !WORD_TABLE_HEADERS_TREE_NODE_HPP