#pragma once
#ifndef BINARYSEARCHTREEWITHVISIT_H
#define BINARYSEARCHTREEWITHVISIT_H
#include"BinarySearchTree.h"
using namespace std;

template<typename K,typename E>
class BinarySearchTreeWithVisit : public BianrySearchTree
{
public:
	virtual void insert(const pair<const K, E> &thePair, void(*visit)(E &u)) override;
};
#endif

template<typename K, typename E>
inline void BinarySearchTreeWithVisit<K, E>::insert(const pair<const K, E> &thePair, void(*visit)(E &u))
{
	BinaryTreeNode<pair<const K, E>> *p = root, *pp = 0;
	while (p != nullptr)
	{
		pp = p;
		if (thePair.first < p->element.first)
			p = p->leftChild;
		else if (thePair.first > p->element.first)
			p = p->rightChild;
		else
		{
			visit(p->element.second);
			return;
		}
	}
	BinaryTreeNode<pair<const K, E>> *newNode = new BinaryTreeNode<pair<const K, E>>(thePair);
	if (root != nullptr)
		if (thePair.first < pp->element.first)
			pp->leftChild = newNode;
		else
			pp->rightChild = newNode;
	else
		root = newNode;
	treeSize++;
}
