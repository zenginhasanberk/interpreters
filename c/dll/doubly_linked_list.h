#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>

/**
 * @brief Represents a node in the doubly-linked list
 */
typedef struct Node {
    char* val;
    struct Node* next;
    struct Node* prev;
} Node;

/**
 * @brief Represents a doubly-linked list.
 */
typedef struct {
    Node* head;
    Node* tail;
    size_t size;
} DLL;

/**
 * @brief Creates a new node with the given string by COPYING it.
 *
 * @param s The string to be stored in the node.
 * @return A pointer to the newly-created node.
 * @pre s != NULL
 * @post If heap memory allocation succeeds, returned node will have next = NULL and prev = NULL, val = a copy of s.
 *       If heap memory allocation fails, NULL is returned and an error message is printed to stderr.
 */
Node* create_node(const char* s);

/**
 * @brief Deletes a given node and frees its memory.
 *
 * @param n A pointer to the node to be deleted.
 * @pre n != NULL
 */
void delete_node(Node* n);

/**
 * @brief Creates a new doubly-linked-list.
 *
 * @return A pointer to the newly created doubly-linked list.
 * @post DLL's head=NULL, tail=NULL and size=0
 */
DLL* create_dll();

/**
 * @brief Inserts a new string at the front of the doubly-linked list by COPYING the argument.
 *
 * @param dll A pointer to the doubly-linked list to insert into.
 * @param s  The string to insert.
 * @pre dll != NULL
 * @pre s != NULL
 * @post dll->front() now corresponds to a newly-created Node with val = s.
 */
void push_front(DLL* dll, const char* s);

/**
 * @brief Inserts a new string at the back of the doubly-linked list by COPYING the argument.
 *
 * @param dll A pointer to the doubly-linked list to insert into.
 * @param s The string to insert.
 * @pre dll != NULL
 * @pre s != NULL
 * @post dll->back() now corresponds to a newly-created Node with val = s.
 */
void push_back(DLL* dll, const char* s);

/**
 * @brief Returns the string that's stored in the head of the doubly-linked list.
 *
 * @param dll A pointer to the doubly-linked list.
 * @pre dll != NULL
 * @pre !dll->empty()
 * @return Returns the string value of the head node.
 */
char* front(const DLL* dll);

/**
 * @brief Returns the string that's stored in the tail of the doubly-linked list.
 *
 * @param dll A pointer to the doubly-linked list.
 * @pre dll != NULL
 * @pre !dll->empty()
 * @return Returns the string value of the tail node.
 */
char* back(const DLL* dll);

/**
 * @brief Removes the head of the doubly-linked list.
 *
 * @param dll A pointer to the doubly-linked list to remove from.
 * @pre dll != NULL
 * @pre !dll->empty()
 * @post If the original head node's next node was not NULL, it becomes the new head.
 */
void pop_front(DLL* dll);

/**
 * @brief Removes the tail of the doubly-linked list.
 *
 * @param dll A pointer to the doubly-linked list to remove from.
 * @pre dll != NULL
 * @pre !dll->empty()
 * @post If the original tail's previous node was not NULL, it becomes the new tail.
 */
void pop_back(DLL* dll);

/**
 * @brief Attempts to find a string in the doubly-linked list.
 *
 * @param dll A pointer to the doubly-linked list to search in.
 * @param s The string to search inside the doubly-linked list.
 * @pre dll != NULL
 * @pre s != NULL
 * @return Returns NULL if not found, the node if found.
 */
Node* find(const DLL* dll, const char* s);

/**
 * @brief Deletes all of the nodes in the doubly-linked list and frees its memory.
 *
 * @param dll A pointer to the doubly-linked list to delete.
 * @pre dll != NULL
 */
void free_dll(DLL* dll);

/**
 * @brief Returns the current size (i.e., number of members) of the doubly-linked list.
 *
 * @param dll A pointer to the doubly-linked list.
 * @pre dll != NULL
 * @return Size of the doubly-linked list.
 */
size_t get_size(const DLL* dll);

/**
 * @brief Returns whether the current doubly-linked list is empty or not.
 *
 * @param dll A pointer to the doubly-linked list.
 * @pre dll != NULL
 * @return Returns 1 if DLL is empty, 0 if not empty.
 */
int empty(const DLL* dll);

/**
 * @brief Prints all of the elements in the doubly-linked list to standard out.
 *
 * @param dll A pointer to the doubly-linked list.
 * @pre dll != NULL
 */
void print_dll(const DLL* dll);

#endif // DOUBLY_LINKED_LIST_H