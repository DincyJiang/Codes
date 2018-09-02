#ifndef TRIENDOE_H
#define TRIENDOE_H

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

#endif //TrieNode