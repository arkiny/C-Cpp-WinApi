/*
	�ڱ� ���� ����ü

	- ����ü �ȿ� �ڽ��� ����ü�� �ֱ�
*/

#include <stdio.h> // printf

typedef unsigned int UNIT;

// ���ڱ� ��带 ����ٴ�... ��ٳ���
// ���ڱ� data structure �⺻�� ���� �Ǵٴ�... 
// �Ǵٴ�... �Ǵٴ�.....
// Iterator�� �ϰ� ����?
typedef struct node{
	UNIT ukey;
	int nValue;
	
	node* pnext; // next node

	// Do RECURSIVE
	node* findNode(UNIT key){
		//base case
		if (ukey == key) return this;
		// ���� ��尡 �������,
		if (pnext == nullptr) return nullptr;
		// do recursive
		pnext->findNode(ukey);	
	}
}NODE;

// prototype
void showNode(node *head);
void addNode(node *front, node* input);
node* findNode(node *head, UNIT key);

// main
void main(){
	node a;
	a.ukey = 1001;
	a.nValue = -77;
	a.pnext = nullptr;

	node b = { 1002, 21, nullptr };
	
	a.pnext = &b;

	node c = { 1003, 44, nullptr };

	b.pnext = &c;

	// node a�� Ȱ���ؼ� a~b ���� �� ���
	node *cur = &a;
	while (true){		
		printf("ukey : %u\n", cur->ukey);
		printf("nValue : %d\n\n", cur->nValue);
		if (cur->pnext == nullptr) break;
		cur = cur->pnext;		
	} // while

	printf("\n----------------------\n");

	// �Լ��� �����
	// showNode(head);

	// �ѹ��� �Ѿ�� ������ ��ħ
	cur = &a;
	for (; cur != nullptr;){
		printf("ukey : %u\n", cur->ukey);
		printf("nValue : %d\n\n", cur->nValue);
		cur = cur->pnext;
	}	// for

	printf("Add node ---->\n");
	node d = { 1004, 34, nullptr };

	addNode(&a, &d);
	showNode(&a);
	UNIT find = 1004;
	node* pfind = findNode(&a, find);

	node* pf = a.findNode(1004); 
	if (pf){
		printf("pf nvalue = %d\n", pf->nValue);
	}
	else {
		printf("err: No such an element\n");
	}
}// main()

// Print out from head to tail
// @param node *head The head node
void showNode(node *head){
	node *cur = head;
	for (; cur != nullptr;){
		printf("ukey : %u\n", cur->ukey);
		printf("nValue : %d\n\n", cur->nValue);
		cur = cur->pnext;
	}// for
}// showNode

// add node
// @param node *front 
// @param node *input
void addNode(node *front, node* input){
	input->pnext = front->pnext;
	front->pnext = input;
}

// findNode
// @param node *cur
// @param UINT key
node* findNode(node *head, UNIT key){
	node *cur = head;
	while (cur->ukey != key){
		cur = cur->pnext;
		if (cur == nullptr){
			printf("No such a key in the list\n");
			return nullptr;
		}
	}
	printf("Value of Key %u is %d\n", cur->ukey, cur->nValue);
	return cur;
}

