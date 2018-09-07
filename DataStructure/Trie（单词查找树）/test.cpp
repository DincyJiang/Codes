
using namespace std;

/*
Trie树一般指字典树, 前缀树
又称单词查找树，Trie树，是一种树形结构，是一种哈希树的变种。
典型应用是用于统计，排序和保存大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。
它的优点是：利用字符串的公共前缀来减少查询时间，最大限度地减少无谓的字符串比较，查询效率比哈希树高。

缺点：构建慢，占用空间大（内存）

*/


#include <vector>
#include <string>
#include <iostream>

static const int TRIE_MAX_CHAR_NUM = 26;

class TrieNode{
public:
    TrieNode() : is_end(false) {
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i){
            child[i] = 0;
        }
    }

    ~TrieNode() {}

    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end; //单词是不是结束了
};


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


TrieTree::TrieTree (){
    
}

TrieTree::~TrieTree (){
    for (int i = 0; i < node_vec.size(); ++i){
        delete node_vec[i];
    }
    // for (auto i : node_vec){
    //     delete i;
    // }
}

void TrieTree::insert(std::string word){
    insert(word.c_str());
}

bool TrieTree::search(std::string word){
    return search(word.c_str());
}

bool TrieTree::startsWith(std::string prefix){
    return startsWith(prefix.c_str());
}

void TrieTree::preOrderTrieTree(){
    preOrderTrieTree(&root, 0);
}

void TrieTree::getAllWordFromTrie(){
    std::string word;
    std::vector<std::string> word_list;
    getAllWordFromTrie(&root, word, word_list);
    for (auto i : word_list){
        std::cout << i << std::endl;
    }
}

void TrieTree::preOrderTrieTree(TrieNode *node, int layer){
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i){
        if (node->child[i]){
            for (int j = 0; j < layer; ++j){
                std::cout<<"---";
            }
            // std::cout<<i+'a'<<std::endl;
            printf("%c", i + 'a');
            if (node->child[i]->is_end){
                cout<<"(end)";
            }
            cout << endl;
            preOrderTrieTree(node->child[i], layer + 1);
        }
    }
}

void TrieTree::getAllWordFromTrie(TrieNode *node, std::string &word, std::vector<std::string> &word_list){
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i){
        if (node->child[i]){
            word.push_back(i + 'a');
            if (node->child[i]->is_end){
                word_list.push_back(word);
            }
            getAllWordFromTrie(node->child[i], word, word_list);
            word.erase(word.length() - 1, 1);
        }
    }
}

TrieNode* TrieTree::new_node(){
    TrieNode *node = new TrieNode();
    node_vec.push_back(node);
    return node;
}

void TrieTree::insert (const char *word){
    TrieNode *ptr = &root;
    while (*word){
        int pos = *word - 'a';
        if (!ptr->child[pos]){
            ptr->child[pos] = new_node();
        }
        ptr = ptr->child[pos];
        ++word;
    }
    ptr->is_end = true;
}

bool TrieTree::search (const char *word){
    TrieNode *ptr = &root;
    while (*word){
        int pos = *word - 'a';
        if (!ptr->child[pos]){
            return false;
        }
        ptr = ptr->child[pos];
        ++word;
    }
    return ptr->is_end;
}

bool TrieTree::startsWith (const char *prefix){
    TrieNode *ptr = &root;
    while (*prefix){
        int pos = *prefix - 'a';
        if (!ptr->child[pos]){
            return false;
        }
        ptr = ptr->child[pos];
        ++prefix;
    }
    return true;
}

int main(){
    TrieTree trie;
    string str = "abcdefg";
    cout<<str;
    trie.insert(str);

    trie.preOrderTrieTree();
    string abc = "abcd";
    cout<< trie.search(abc) << endl;



    return 0;
}