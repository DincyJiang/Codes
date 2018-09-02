#include "BinarySearchTree.h"

template<typename K, typename E>
bool BianrySearchTree<K, E>::empty() const
{
	return treeSize == 0;
}

template<typename K, typename E>
bool BianrySearchTree<K, E>::size() const
{
	return treeSize;
}

template<typename K, typename E>
pair<const K, E>* BianrySearchTree<K, E>::find(const K & theKey) const
{
	BinaryTreeNode<pair<const K, E>> *p = root;
	while (p != nullptr)
	{
		if (theKey < p->element.first)
			p = p->leftChild;
		else if (theKey > p->element.first)
				p = p->rightChild;
			else
				return &p->element;
	}
	return nullptr;
}

template<typename K, typename E>
void BianrySearchTree<K, E>::insert(const pair<const K, E>& thePair)
{//插入thePair，如果存在与其关键字相同的数对，则覆盖
	BinaryTreeNode<pair<const K, E>> *p = root, *pp = nullptr;
	while (p != nullptr)
	{
		pp = p;
		if (thePair.first < p->element.first)
			p = p->leftChild;
		else if (thePair.first > p->element.first)
			p = p->rightChild;
		else
		{//覆盖旧的值
			p->element.second = thePair.second;
			return;
		}
	}
	//新建一个节点存放thePair的元素，新节点与pp链接
	BinaryTreeNode<pair<const K, E>> *newNode = new BinaryTreeNode<pair<const K, E>>(thePair);
	if (root != nullptr)
	{
		if (thePair.first < pp->element.first)
			pp->leftChild = newNode;
		else
			pp->rightChild = newNode;
	}
	else//如果根节点为空，则新插入就是根节点
		root = newNode;
	treeSize++;
}

template<typename K, typename E>
void BianrySearchTree<K, E>::erase(const K & theKey)
{
	//首先查找关键字为theKey的节点，p指向该节点，pp是p的父节点
	BinaryTreeNode<pair<const K, E>> *p = root, *pp = nullptr;
	while (p != nullptr && p->element.first != theKey)
	{
		pp = p;
		if (theKey < p->element.first)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	if (p == nullptr)
		return;
	//要删除的节点有两棵非空子树的情况，在左子树中找最大的元素
	if (p->leftChild != nullptr && p->rightChild != nullptr)
	{
		BinaryTreeNode<pair<const K, E>> *s = p->leftChild, *ps = p;//ps是s的父节点
		while (s->rightChild != nullptr)//沿着右孩子指针移动找到左子树中最大的节点,s指向它
		{
			ps = s;
			s = s->rightChild;
		}
		BinaryTreeNode<pair<const K, E>> *q = new BinaryTreeNode<pair<const K, E>>(s->element, p->leftChild, p->rightChild);
		if (pp == nullptr)
			root = q;
		else if (p == pp->leftChild)
			pp->leftChild = q;
		else
			pp->rightChild = q;
		//如果要删除节点的左子树的最大节点的父节点就是要删除的节点，
		//那么要删除节点的父节点就是新造的节点，
		//否则要删除节点的父节点就指向左子树的最大节点的父节点
		if (ps == p)
			pp = q;
		else
			pp = ps;
		delete p;
		p = s;
	}
	//待删除的节点p只有一棵子树的情况，
	//如果经过上一步骤那么当前要删除的节点p就指向s，pp指向s的父节点ps
	//s只有左子树存在，也就是只有一棵子树
	BinaryTreeNode<pair<const K, E>> *c;
	if (p->leftChild != nullptr)
		c = p->leftChild;
	else
		c = p->rightChild;
	if (p == root)
		root = c;
	else
	{
		if (p == pp->leftChild)
			pp->leftChild = c;
		else pp->rightChild = c;
	}
	treeSize--;
	delete p;
}

void BianrySearchTree<K, E>::ascend() const
{
	inOrderOutput();
}
