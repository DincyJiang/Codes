/*
Trie树一般指字典树, 前缀树
又称单词查找树，Trie树，是一种树形结构，是一种哈希树的变种。
典型应用是用于统计，排序和保存大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。
它的优点是：利用字符串的公共前缀来减少查询时间，最大限度地减少无谓的字符串比较，查询效率比哈希树高。

缺点：构建慢，占用空间大（内存）

*/

#ifndef TRIETREE_H
#define TRIETREE_H
#include "TrieNode.h"
#include <vector>
#include <string>
#include <iostream>

class TrieTree{
public:
    TrieTree ();
    ~TrieTree ();
    void insert(std::string word);
    bool search(std::string word);
    bool startsWith(std::string prefix);
    void preOrderTrieTree();
    void getAllWordFromTrie();

private:
    TrieNode *new_node();
    void insert (const char *word);
    bool search (const char *word);
    bool startsWith (const char *prefix);
    void preOrderTrieTree(TrieNode *node, int layer);
    void getAllWordFromTrie(TrieNode *node, std::string &word, std::vector<std::string> &word_list);

    std::vector<TrieNode *> node_vec; //所有的new的节点都存放在这个vector中
    TrieNode root;
};


#endif //TrieTree