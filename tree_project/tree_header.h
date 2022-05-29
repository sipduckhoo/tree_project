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
	void inputdata(tree* tmp, int i); //트리에 데이터 삽입
	void deletedata(int j); //트리에서 데이터 삭제
	bool search_exist(int j); //데이터 존재여부 검색
	void preorder(tree* tmp); //전위순회
	void stack_preorder(tree* tmp); //사용자 스택 전위순회
	void order(tree* tmp); //중위순회
	void aftorder(tree* tmp); //후위순회
	void delete_aft(tree* tmp); //소멸자용 후위순회
	tree* search_location(tree* tmp, int k); //삽입할 데이터 노드의 위치를 찾음
	tree* delete_front(tree** p, tree* tmp, int k); //삭제할 데이터 노드 위치와 그 노드의 부모노드
	tree* replacenode_left(tree** p, tree* tmp); //삭제 된 노드위치를 대체할 왼쪽 노드 반환
	tree* replacenode_right(tree** p, tree* tmp); //삭제 된 노드위치를 대체할 오른쪽 노드 반환
	tree* getvalue(); //main용 루트노드 반환
private:
	tree* route; //루트노드 가리킴
};

#endif