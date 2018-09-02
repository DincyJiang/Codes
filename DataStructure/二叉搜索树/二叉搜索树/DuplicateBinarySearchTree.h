#pragma once
#ifndef DUPLICATEBINARYSEARCHTREE_H
#define DUPLICATEBINARYSEARCHTREE_H
#include"BinarySearchTree.h"
using namespace std;

template<typename K,typename E>
class DuplicateBinarySearchTree : public BianrySearchTree<K, E>
{
public:
	virtual void insert(const pair<const K, E>& thePair) override;
};
#endif

template<typename K, typename E>
inline void DuplicateBinarySearchTree<K, E>::insert(const pair<const K, E>& thePair)
{
	BinaryTreeNode<pair<const K, E>> *p = root, *pp = nullptr;
	while (p != nullptr)
	{
		pp = p;
		if (thePair.first <= p->element.first)
			p = p->leftChild;
		else 
			p = p->rightChild;
	}
	//�½�һ���ڵ���thePair��Ԫ�أ��½ڵ���pp����
	BinaryTreeNode<pair<const K, E>> *newNode = new BinaryTreeNode<pair<const K, E>>(thePair);
	if (root != nullptr)
	{
		if (thePair.first <= pp->element.first)
			pp->leftChild = newNode;
		else
			pp->rightChild = newNode;
	}
	else//������ڵ�Ϊ�գ����²�����Ǹ��ڵ�
		root = newNode;
	treeSize++;
}
