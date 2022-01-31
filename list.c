#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"


void printList(node* p_pRoot)
{
	if (!p_pRoot)
	{
		printf("\n");
		return;
	}
	printf("[%d] ", p_pRoot->m_data);
	printList(p_pRoot->m_next);
	return;
}
void printListReversed(node* p_pRoot)
{
	if (!p_pRoot)
	{
		printf("\n");
		return;
	}
	node* reversedList = NULL;
	node* index = p_pRoot;
	while (index)
	{
		reversedList = addFirst(reversedList, index->m_data);
		index = index->m_next;
	}
	index = reversedList;
	printf("#-");
	while (index)
	{
		if (index->m_data == 0)
		{
			index = index->m_next;
			continue;
		}
		printf("(%d)-", index->m_data);
		index = index->m_next;
	}
	printf("\n");
	return;
}

node* createListNode(int p_value)
{
	node* m_node = calloc(1, sizeof(node));
	m_node->m_data = p_value;
	//m_node->m_next = NULL;
	return m_node;
}
void freeList(node* p_pRoot)
{
	if (!p_pRoot)
	{
		return;
	}
	freeList(p_pRoot->m_next);
	free(p_pRoot);
	return;
}
node* addFirst(node* p_pRoot, int p_value)
{
	node* new = createListNode(p_value);
	new->m_next = p_pRoot;
	return new;
}
node* addLast(node* p_pRoot, int p_value)
{
	if (!p_pRoot)
	{
		return createListNode(p_value);
	}
	if (p_pRoot->m_next != NULL)
	{
		addLast(p_pRoot->m_next, p_value);
		return p_pRoot;
	}

	p_pRoot->m_next = createListNode(p_value);
	return p_pRoot;
}
node* addSortAsc(node* p_pRoot, int p_value)
{
	if (!p_pRoot || p_value <= p_pRoot->m_data)
		return addFirst(p_pRoot, p_value);
	if (!p_pRoot->m_next)
		return addLast(p_pRoot, p_value);

	p_pRoot->m_next = addSortAsc(p_pRoot->m_next, p_value);
	return p_pRoot;
}
node* addSortDesc(node* p_pRoot, int p_value)
{
	if (!p_pRoot || p_value >= p_pRoot->m_data)
		return addFirst(p_pRoot, p_value);
	if (!p_pRoot->m_next)
		return addLast(p_pRoot, p_value);

	p_pRoot->m_next = addSortAsc(p_pRoot->m_next, p_value);
	return p_pRoot;
}
int listLength(node* p_pRoot)
{
	int length = 0;
	while (p_pRoot != NULL)
	{
		length++;
		p_pRoot = p_pRoot->m_next;
	}
	return length;
}
node* at(node* p_pRoot, int p_index)
{
	if (!p_pRoot)
		return NULL;
	for (int i = 0; i < p_index; i++)
	{
		p_pRoot = p_pRoot->m_next;
	}
	return p_pRoot;
}
node* pop(node* p_pRoot, int* p_result)
{
	if (!p_pRoot)
		return NULL;
	*p_result = p_pRoot->m_data;
	node* tmp = p_pRoot;
	p_pRoot = p_pRoot->m_next;
	free(tmp);
	return p_pRoot;
}
void printHanoi(node** tower)
{

	for (size_t i = 0; i < 3; ++i)
	{
		printListReversed(tower[i]);
	}
	printf("\n\n");
}
node** hanoi(int size, int id_begin, int id_end, int id_mid)
{
	node** tower = (node**)calloc(3, sizeof(node*));
	for (size_t i = 0; i < 3; ++i)
		tower[i] = createListNode(0);

	for (size_t i = size; i >= 1; i--)
		tower[id_begin] = addFirst(tower[id_begin], i);

	printHanoi(tower);

	move_tower(tower, size, id_begin, id_end, id_mid);

	printHanoi(tower);

	return tower;
}
void move_tower(node** tower, int size, int id_begin, int id_end, int id_mid)
{
	if (size == 1)
	{
		move_plate(tower, id_begin, id_end);
		return;
	}
	move_tower(tower, size - 1, id_begin, id_mid, id_end);
	move_plate(tower, id_begin, id_end);
	move_tower(tower, size - 1, id_mid, id_end, id_begin);

	return;

}
void move_plate(node** tower, int id_begin, int id_end)
{
	int result;
	tower[id_begin] = pop(tower[id_begin], &result);
	tower[id_end] = addFirst(tower[id_end], result);
	printHanoi(tower);
	return;
}















/*
void triNode(node* p_head)
{

}

node* insertBeforeNode(node* p_head, node* p_node, node* p_toInsert)
{
	if (!p_node || !p_head)
		return NULL;

	//relie le parent du noeud déplacer a son enfant
	node* p_parent;
	while (p_parent->m_next != p_toInsert)
		p_parent = p_parent->m_next;
	p_parent->m_next = p_toInsert->m_next;

	if (p_node == p_head)
	{
		p_toInsert->m_next = p_head;
		return p_toInsert;
	}
	else{}

}

node* triInsertion(node* p_head, node* p_node)
{
	if (!p_node || !p_head)
		return p_head;

	node* p_actual = p_head;

	while (p_node->m_data > p_actual->m_data)
		p_actual = p_head->m_next;

}

*/