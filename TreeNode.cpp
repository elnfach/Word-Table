#include <iostream>
#include "headers/TreeNode.hpp"

TreeNode::TreeNode() : ptr_left(0), ptr_right(0)
{
    m_key = std::string();
    m_counter = 1;
    ptr_left = nullptr;
    ptr_right = nullptr;
}

TreeNode::TreeNode(std::string word)
{
    m_key = word;
    m_counter = 1;
    ptr_left = nullptr;
    ptr_right = nullptr;
}

TreeNode::~TreeNode()
{

}

void TreeNode::print(TreeNode* root)
{
    std::cout << root->m_key;
    std::cout << " | ";
    std::cout << root->m_counter;
    std::cout << std::endl;

    if (root->ptr_right != nullptr)
    {
        print(root->ptr_right);
    }
    if (root->ptr_left != nullptr)
    {
        print(root->ptr_left);
    }
}

void TreeNode::lookup(std::string word, TreeNode* root)
{
    int temp = strcmp(root->m_key.c_str(), word.c_str());
    if (temp != 0)
    {
        if (root->ptr_left != nullptr)
        {
            lookup(word, root->ptr_left);
        }
        if (root->ptr_right != nullptr)
        {
            lookup(word, root->ptr_right);
        }
        return;
    }
    
    std::cout << root->m_key << " | " << root->m_counter;
}

void TreeNode::insert(std::string word, TreeNode* root)
{
    int temp = strcmp(root->m_key.c_str(), word.c_str());
    if (temp == 0)
    {
        root->m_counter++;
        return;
    }

    if (temp < 0)
    {
        if (root->ptr_right == nullptr)
        {
            root->ptr_right = new TreeNode(word);
            return;
        }
        insert(word, root->ptr_right);
    }
    else {
        if (root->ptr_left == nullptr)
        {
            root->ptr_left = new TreeNode(word);
            return;
        }
        insert(word, root->ptr_left);
    }
}

    if (root->ptr_left != nullptr)
    {
        root->ptr_left = remove(word, root->ptr_left);
    }
    if (root->ptr_right != nullptr)
    {
        root->ptr_left = remove(word, root->ptr_right);
    }
    return root;
}

TreeNode* TreeNode::maxNode(TreeNode* root)
{
    return nullptr;
}

TreeNode* TreeNode::minNode(TreeNode* root)
{
    return nullptr;
}
