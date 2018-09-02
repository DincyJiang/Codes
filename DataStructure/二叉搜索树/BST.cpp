#include <iostream>
#include <cassert>

using namespace std;

template<typename Key, typename Value>
class BST {
private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;
        Node(Key key, Value value) : key(key), value(value), left(nullptr), right(nullptr) {}
        Node(Node* node) {
            key = node->key;
            value = node->value;
            left = node->left;
            right = node->right;
        }
    };
    Node *root;
    int count;

public:
    BST() : root(nullptr), count(0) {}
    ~BST() {
        
    }
    int size() {
        return count;
    }
    bool empty() {
        return count == 0;
    }
    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }
    // 如果找不到，就返回nullptr, 如果找到了，用户可以修改value
    Value* search(Key key) {
        return search(root, key);
    }
    // 寻找最小的键值
    Key minimum() {
        assert(count != 0);
        Node* minNode = minimum(root);
        return minNode->key;
    }
    // 寻找最大的键值
    Key maximum() {
        assert(count != 0);
        Node* maxNode = maximum(root);
        return maxNode->key;
    }
    // 从二叉树中删除最小值所在的节点
    void removeMin() {
        if (root)
            root = removeMin(root);
    }
    void remove(Key key) {
        root = remove(root, key);
    }
private:
    Node* insert(Node* node, Key key, Value value) {
        // if has not this key
        if (node == nullptr) {
            ++count;
            return new Node(key, value);
        }
        if (key == node->key)
            node->value = value;
        else if (key < node->key)
            node->left = insert(node->left, key, value);
        else
            node->right = insert(node->right, key, value);
        return node;
    }
    // 查看以node为根的二叉搜索树中是否包含键值为key的节点
    bool contain(Node* node, Key key) {
        if (node == nullptr)
            return false;
        if (key == node->key)
            return true;
        else if (key < node->key)
            return contain(node->left, key);
        else
            return contain(node->right, key);
    }
    // 在以node为根的二叉搜索树中查找key所对应的value
    Value* search(Node* node, Key key) {
        if (node == nullptr)
            return nullptr;
        if (key == node->key)
            return &(node->value);
        else if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }
    // 在以node为根的二叉搜索树中，返回最小键值的节点
    Node* minimum(Node* node) {
        if (node->left == nullptr)
            return node;
        return minimum(node->left);    
    }
    Node* maximum(Node* node) {
        if (node->right == nullptr)
            return node;
        return minimum(node->right);    
    }
    Node* removeMin(Node* node) {
        if (node->left == nullptr) {
            Node* rightNode = node->right;
            delete node;
            node = nullptr;
            --count;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }
    // 返回的是新的代替node的节点
    Node* remove(Node* node, Key key) {
        if (node == nullptr)
            return nullptr;
        if (key < node->key) {
            node->left = remove(node->left, key);
            return node;
        } else if (key > node->key) {
            node->right = remove(node->right, key);
            return node;
        } else { // key == node->key
            if (node->left == nullptr) {
                Node *rightNode = node->right;
                delete node;
                node = nullptr;
                --count;
                return rightNode;
            }
            if (node->right == nullptr) {
                Node *leftNode = node->left;
                delete node;
                node = nullptr;
                --count;
                return leftNode;
            } 
            Node *successor = new Node(minimum(node->right));
            ++count;
            successor->right = removeMin(node->right);
            successor->left = node->left;
            delete node;
            node = nullptr;
            --count;
            return successor;
        }
    }
};