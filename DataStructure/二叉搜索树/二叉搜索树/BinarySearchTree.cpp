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
{//����thePair�������������ؼ�����ͬ�����ԣ��򸲸�
	BinaryTreeNode<pair<const K, E>> *p = root, *pp = nullptr;
	while (p != nullptr)
	{
		pp = p;
		if (thePair.first < p->element.first)
			p = p->leftChild;
		else if (thePair.first > p->element.first)
			p = p->rightChild;
		else
		{//���Ǿɵ�ֵ
			p->element.second = thePair.second;
			return;
		}
	}
	//�½�һ���ڵ���thePair��Ԫ�أ��½ڵ���pp����
	BinaryTreeNode<pair<const K, E>> *newNode = new BinaryTreeNode<pair<const K, E>>(thePair);
	if (root != nullptr)
	{
		if (thePair.first < pp->element.first)
			pp->leftChild = newNode;
		else
			pp->rightChild = newNode;
	}
	else//������ڵ�Ϊ�գ����²�����Ǹ��ڵ�
		root = newNode;
	treeSize++;
}

template<typename K, typename E>
void BianrySearchTree<K, E>::erase(const K & theKey)
{
	//���Ȳ��ҹؼ���ΪtheKey�Ľڵ㣬pָ��ýڵ㣬pp��p�ĸ��ڵ�
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
	//Ҫɾ���Ľڵ������÷ǿ����������������������������Ԫ��
	if (p->leftChild != nullptr && p->rightChild != nullptr)
	{
		BinaryTreeNode<pair<const K, E>> *s = p->leftChild, *ps = p;//ps��s�ĸ��ڵ�
		while (s->rightChild != nullptr)//�����Һ���ָ���ƶ��ҵ������������Ľڵ�,sָ����
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
		//���Ҫɾ���ڵ�������������ڵ�ĸ��ڵ����Ҫɾ���Ľڵ㣬
		//��ôҪɾ���ڵ�ĸ��ڵ��������Ľڵ㣬
		//����Ҫɾ���ڵ�ĸ��ڵ��ָ�������������ڵ�ĸ��ڵ�
		if (ps == p)
			pp = q;
		else
			pp = ps;
		delete p;
		p = s;
	}
	//��ɾ���Ľڵ�pֻ��һ�������������
	//���������һ������ô��ǰҪɾ���Ľڵ�p��ָ��s��ppָ��s�ĸ��ڵ�ps
	//sֻ�����������ڣ�Ҳ����ֻ��һ������
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
