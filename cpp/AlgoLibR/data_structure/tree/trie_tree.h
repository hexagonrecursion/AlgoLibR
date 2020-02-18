/*
Author: raoqiyu@gmail.com
Date: 2020-02-11 18:34:27
FilePath: /AlgoLibR/cpp/AlgoLibR/data_structure/tree/trie_tree.h
Description: 
 */

#ifndef DS_TREE_TRIE_H
#define DS_TREE_TRIE_H

#include <map>
#include <stdlib.h>

namespace AlgoLibR{
namespace data_structure{
namespace tree{
namespace trie{

class TrieNode{
public:
    char key;
    bool is_ending_key;
    std::map<char, TrieNode*> child_nodes;
    TrieNode *parent;

    TrieNode(const char key);
    TrieNode(const char key, TrieNode* parent);
    ~TrieNode();
    void AddChild(const char key);
    void RemoveChild(const char key);
};


template<typename NODETYPE>
class Trie{
protected:
    NODETYPE* root;
    bool is_keys_added;

public:
    Trie();
    ~Trie();

    NODETYPE* Add(const char keys[]);
    NODETYPE* FindNode(const char keys[]);
    bool Search(const char keys[]);
    void Remove(const char keys[]);
};

} // namespace trie
} // namespace tree
} // namespace data_struceture
} // namespace AlgoLibR

#endif
