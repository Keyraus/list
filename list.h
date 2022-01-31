#pragma once

typedef struct sNode {

	int m_data;
	struct sNode* m_next;

}node;


//node* insertBeforeNode(node* p_head, node* p_node, node* p_toInsert);
//node* triInsertion(node* p_head, node* p_node);

void printList(node* p_pRoot);
node* createListNode(int p_value);
void freeList(node* p_pRoot);
node* addFirst(node* p_pRoot, int p_value);

node* addLast(node* p_pRoot, int p_value);
node* addSortAsc(node* p_pRoot, int p_value);
node* addSortDesc(node* p_pRoot, int p_value);
int listLength(node* p_pRoot);
node* at(node* p_pRoot, int p_index);
node* pop(node* p_pRoot, int* p_result);

node** hanoi(int size, int id_begin, int id_end, int id_mid);
void move_tower(node** tower, int size, int id_begin, int id_end, int id_mid);
void move_plate(node** tower, int id_begin, int id_end);
