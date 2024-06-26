#include "doubly_linked_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

Node* create_node(const char* s) {
    assert(s != NULL);

    Node* n = malloc(sizeof(Node));

    if (n == NULL) {
        fprintf(stderr, "Could not allocate heap memory!");
        return NULL;
    }

    n->prev = NULL;
    n->next = NULL;
    n->val = strdup(s);

    if (n->val == NULL) {
        fprintf(stderr, "Could not allocate heap memory!");
        return NULL;
    }
    return n;
}

void delete_node(Node* n) {
    assert(n != NULL);
    free(n->val);
    free(n);
}

DLL* create_dll() {
    DLL* dll = malloc(sizeof(DLL));
    dll->head = NULL;
    dll->tail = NULL;
    dll->size = 0;
    return dll;
}

void push_front(DLL* dll, const char* s) {
    assert(dll != NULL);
    assert(s != NULL);

    Node* n = create_node(s);

    if (empty(dll)) {
        dll->head = n;
        dll->tail = n;
    } else {
        n->next = dll->head;
        dll->head->prev = n;
        dll->head = n;
    }
    ++dll->size;
}

void push_back(DLL* dll, const char* s) {
    assert(dll != NULL);
    assert(s != NULL);

    Node* n = create_node(s);

    if (empty(dll)) {
        dll->head = n;
        dll->tail = n;
    } else {
        n->prev = dll->tail;
        dll->tail->next = n;
        dll->tail = n;
    }
    ++dll->size;
}

char* front(const DLL* dll) {
    assert(dll != NULL);
    assert(!empty(dll));
    return dll->head->val;
}

char* back(const DLL* dll) {
    assert(dll != NULL);
    assert(!empty(dll));
    return dll->tail->val;
}

void pop_front(DLL* dll) {
    assert(dll != NULL);
    assert(!empty(dll));

    if (get_size(dll) == 1) {
        delete_node(dll->head);
        dll->head = NULL;
        dll->tail = NULL;
    } else {
        Node* node_to_delete = dll->head;
        dll->head = dll->head->next;
        dll->head->prev = NULL;
        delete_node(node_to_delete);
    }
    --(dll->size);
}

void pop_back(DLL* dll) {
    assert(dll != NULL);
    assert(!empty(dll));

    if (get_size(dll) == 1) {
        delete_node(dll->head);
        dll->head = NULL;
        dll->tail = NULL;
    } else {
        Node* node_to_delete = dll->tail;
        dll->tail = dll->tail->prev;
        dll->tail->next = NULL;
        delete_node(node_to_delete);
    }
    --(dll->size);
}

Node* find(const DLL* dll, const char* s) {
    assert(dll != NULL);

    Node* n = dll->head;

    while (n != NULL) {
        if (strcmp(n->val, s) == 0) return n;
        n = n->next;
    }

    return NULL;
}

void free_dll(DLL* dll) {
    assert(dll != NULL);

    Node* n = dll->head;

    while (n != NULL) {
        Node* node_to_delete = n;
        n = n->next;
        delete_node(node_to_delete);
    }
    free(dll);
}

size_t get_size(const DLL* dll) {
    assert(dll != NULL);

    return dll->size;
}

int empty(const DLL* dll) {
    assert(dll != NULL);

    return dll->size == 0;
}

void print_dll(const DLL* dll) {
    const Node* n = dll->head;

    while (n != NULL) {
        printf("%s ", n->val);
        n = n->next;
    }
    printf("\n");
}
