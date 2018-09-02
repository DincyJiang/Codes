#include "TrieTree.h"
using namespace std;

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
