#include "tree_header.h"
#include <stack>

treesys::treesys() {
	this->route = NULL;
	this->nodesize = 0;
}

treesys::~treesys() {
	this->delete_aft(this->route);
}

void treesys::inputdata(tree* tmp, int i) {
	if (tmp == NULL) {
		this->route = new tree;
		this->route->data = i;
		this->route->leftdata = NULL;
		this->route->rightdata = NULL;
	}
	else {
		tmp = this->search_location(tmp, i);

		if (tmp->data == i) {
			cout << "이 데이터 값과 같은 값의 노드가 있습니다" << endl;
			return;
		}
		else if (tmp->data > i) {
			tmp->leftdata = new tree;
			tmp = tmp->leftdata;
		}
		else {
			tmp->rightdata = new tree;
			tmp = tmp->rightdata;
		}
		tmp->data = i;
		tmp->leftdata = NULL;
		tmp->rightdata = NULL;
	}
	this->nodesize++;
}

void treesys::deletedata(int j) {
	tree* tmp[4]; //tmp[1]이 삭제할 위치
	tmp[0] = this->delete_front(&tmp[1], this->route, j);

	if (tmp[0] == NULL && tmp[1] == NULL) {
		cout << "삭제 데이터에 부합하는 노드가 없습니다." << endl;
		return;
	}
	tmp[2] = tmp[1];

	if (tmp[1]->rightdata != NULL) 
		tmp[3] = this->replacenode_right(&tmp[2], tmp[1]->rightdata);
	else if (tmp[1]->leftdata != NULL) 
		tmp[3] = this->replacenode_left(&tmp[2], tmp[1]->leftdata);
	else {
		if (tmp[0] != NULL) {
			if (tmp[0]->leftdata == tmp[1])
				tmp[0]->leftdata = NULL;
			else
				tmp[0]->rightdata = NULL;
		}
		delete tmp[1];
		this->nodesize--;
		return;
	}

	if (tmp[0] == NULL) {
		tmp[3]->leftdata = tmp[1]->leftdata;
		tmp[3]->rightdata = tmp[1]->rightdata;
		this->route = tmp[3];
	}
	else {
		if (tmp[0]->leftdata == tmp[1]) {
			tmp[0]->leftdata = tmp[3];
			if(tmp[3] != tmp[1]->leftdata)
				tmp[3]->leftdata = tmp[1]->leftdata;
			if (tmp[3] != tmp[1]->rightdata)
				tmp[3]->rightdata = tmp[1]->rightdata;
		} 
		else {
			tmp[0]->rightdata = tmp[3];
			if (tmp[3] != tmp[1]->leftdata)
				tmp[3]->leftdata = tmp[1]->leftdata;
			if (tmp[3] != tmp[1]->rightdata)
				tmp[3]->rightdata = tmp[1]->rightdata;
		}
	}

	if (tmp[2]->leftdata == tmp[3])
		tmp[2]->leftdata = NULL;
	else
		tmp[2]->rightdata = NULL;
	delete tmp[1];
	this->nodesize--;
}

bool treesys::search_exist(int j) {
	tree* tmp = this->search_location(this->route, j);

	if (tmp->data == j) 
		return true;
	return false;
}

void treesys::preorder(tree* tmp) {
	if (tmp != NULL)
		cout << tmp->data << " ";
	else
		return;
	if (tmp->leftdata != NULL)
		preorder(tmp->leftdata);
	if (tmp->rightdata != NULL)
		preorder(tmp->rightdata);
}

void treesys::stack_preorder(tree* tmp) {
	stack<tree*> store;
	int limit = this->getsize();
	
	if (tmp != NULL) {
		while(1) {
			cout << tmp->data << " ";
			
			if (tmp->rightdata != NULL) 
				store.push(tmp->rightdata);
			if(tmp->leftdata != NULL)
				tmp = tmp->leftdata;
			else {
				if (store.size() > 0) {
					tmp = store.top();
					store.pop();
				}
				else
					break;
			}
		}
	}
}

void treesys::order(tree* tmp) {
	if (tmp == NULL)
		return;
	if (tmp->leftdata != NULL)
		order(tmp->leftdata);
	cout << tmp->data << " ";

	if (tmp->rightdata != NULL)
		order(tmp->rightdata);
}

void treesys::aftorder(tree* tmp) {
	if (tmp == NULL)
		return;
	if (tmp->leftdata != NULL)
		aftorder(tmp->leftdata);
	if (tmp->rightdata != NULL)
		aftorder(tmp->rightdata);
	cout << tmp->data << " ";
}

void treesys::delete_aft(tree* tmp) {
	if (tmp->leftdata != NULL)
		delete_aft(tmp->leftdata);
	if (tmp->rightdata != NULL)
		delete_aft(tmp->rightdata);
	delete tmp;
}

tree* treesys::search_location(tree* tmp, int k) {
	if (k > tmp->data) {
		if (tmp->rightdata == NULL)
			return tmp;
		return search_location(tmp->rightdata, k);
	}
	else if (k < tmp->data) {
		if (tmp->leftdata == NULL)
			return tmp;
		return search_location(tmp->leftdata, k);
	}
	else
		return tmp;
}

tree* treesys::delete_front(tree** p, tree* tmp, int k) {
	if (tmp == NULL) {
		*p = NULL;
		return NULL;
	}
	if (k > tmp->data) {
		if (tmp->rightdata == NULL) {
			*p = NULL;
			return NULL;
		}
		if (tmp->rightdata->data == k) {
			*p = tmp->rightdata;
			return tmp;
		}
		return delete_front(p, tmp->rightdata, k);
	}
	else if (k < tmp->data) {
		if (tmp->leftdata == NULL) {
			*p = NULL;
			return NULL;
		}
		if (tmp->leftdata->data == k) {
			*p = tmp->leftdata;
			return tmp;
		}
		return delete_front(p, tmp->leftdata, k);
	}
	*p = this->route;
	return NULL;
}

tree* treesys::replacenode_left(tree** p, tree* tmp) {
	if (tmp->rightdata == NULL) 
		return tmp;
	*p = tmp;
	return replacenode_left(p, tmp->rightdata);
}

tree* treesys::replacenode_right(tree** p, tree* tmp) {
	if (tmp->leftdata == NULL)
		return tmp;
	*p = tmp;
	return replacenode_right(p, tmp->leftdata);
}

tree* treesys::getvalue() {
	return this->route;
}