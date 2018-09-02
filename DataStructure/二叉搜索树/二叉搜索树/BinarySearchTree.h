#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include"BsTree.h"
#include"LinkedBinaryTree.h"
using namespace std;

template<typename K, typename E>
class BianrySearchTree : public BsTree<K, E>,
	public LinkedBinaryTree<pair<const K, E>>
{
public:
	//Dictionary类中的操作
	virtual bool empty() const override;
	virtual bool size() const override;
	virtual pair<const K, E>* find(const K& theKey) const override;
	virtual void insert(const pair<const K, E>& thePair) override;
	virtual void erase(const K& theKey) override;
	//BsTree中的操作
	virtual void ascend() const override;
};
#endif