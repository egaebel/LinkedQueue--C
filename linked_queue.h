#ifndef LINKED_QUEUE_H_
#define LINKED_QUEUE_H_

#include <inttypes.h>
#include <stddef.h>
#include <stdlib.h>

//Preprocessor macro which converts a AdjNode to the structure the AdjNode is IN (Duct tape style!)
#define QUEUE_ENTRY(NODE, STRUCT, MEMBER) 					\
	((STRUCT *)((uint8_t*)(NODE) - offsetof(STRUCT, MEMBER)))

//struct definitions----------------------------------
//linked node struct holding prev and next linked_node ptrs
struct linked_node {

	struct linked_node *prev;
	struct linked_node *next;
};

//linked list struct containing head and tail linked_nodes
struct linked_list {

	struct linked_node head;
	struct linked_node tail;
};

//TypeDefs---------------------------------------------
typedef struct linked_node QNode;
typedef struct linked_list Queue;

//Prototypes------------------------------------------------------
void init_queue(Queue *q);
void init_qnode(QNode *node);
Queue* create_queue();

void add_queue(Queue *q, QNode *node);
QNode* remove_queue(Queue *q);

int is_empty (Queue *q);

#endif