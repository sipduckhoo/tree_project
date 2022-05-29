#ifndef TREE_HEADER_H
#define TREE_HEADER_H

#include <iostream>

using namespace std;

struct tree {
	int data;
	tree* leftdata;
	tree* rightdata;
};

class treesys {
public:
	treesys(); 
	~treesys();
	void inputdata(tree* tmp, int i); //Ʈ���� ������ ����
	void deletedata(int j); //Ʈ������ ������ ����
	bool search_exist(int j); //������ ���翩�� �˻�
	void preorder(tree* tmp); //������ȸ
	void stack_preorder(tree* tmp); //����� ���� ������ȸ
	void order(tree* tmp); //������ȸ
	void aftorder(tree* tmp); //������ȸ
	void delete_aft(tree* tmp); //�Ҹ��ڿ� ������ȸ
	tree* search_location(tree* tmp, int k); //������ ������ ����� ��ġ�� ã��
	tree* delete_front(tree** p, tree* tmp, int k); //������ ������ ��� ��ġ�� �� ����� �θ���
	tree* replacenode_left(tree** p, tree* tmp); //���� �� �����ġ�� ��ü�� ���� ��� ��ȯ
	tree* replacenode_right(tree** p, tree* tmp); //���� �� �����ġ�� ��ü�� ������ ��� ��ȯ
	tree* getvalue(); //main�� ��Ʈ��� ��ȯ
private:
	tree* route; //��Ʈ��� ����Ŵ
};

#endif