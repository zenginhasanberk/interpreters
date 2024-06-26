#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "doubly_linked_list.h"

int main(void) {
    printf("Running tests for doubly linked list...\n");

    // node stuff
    Node* n = create_node("hello");
    assert(n != NULL);
    assert(n->next == NULL);
    assert(n->prev == NULL);
    assert(strcmp(n->val, "hello") == 0);
    delete_node(n);

    // dll stuff
    DLL* dll = create_dll();
    assert(dll != NULL);
    assert(dll->size == 0);
    assert(dll->head == NULL);
    assert(dll->tail == NULL);

    // push_front and push_back
    push_front(dll, "hi");
    assert(dll->size == 1);
    assert(strcmp(front(dll), "hi") == 0);
    assert(strcmp(back(dll), "hi") == 0);

    push_back(dll, "there");
    assert(dll->size == 2);
    assert(strcmp(front(dll), "hi") == 0);
    assert(strcmp(back(dll), "there") == 0);

    // pop_back
    pop_back(dll);
    assert(dll->size == 1);
    assert(strcmp(front(dll), "hi") == 0);
    assert(strcmp(back(dll), "hi") == 0);

    // pop_front
    pop_front(dll);
    assert(dll->size == 0);
    assert(dll->head == NULL);
    assert(dll->tail == NULL);

    // mixed
    push_front(dll, "one");
    push_back(dll, "two");
    push_front(dll, "zero");
    push_back(dll, "three");
    assert(dll->size == 4);
    assert(strcmp(front(dll), "zero") == 0);
    assert(strcmp(back(dll), "three") == 0);

    // find
    Node* found = find(dll, "two");
    assert(found != NULL);
    assert(strcmp(found->val, "two") == 0);

    found = find(dll, "four");
    assert(found == NULL);

    pop_front(dll);
    assert(dll->size == 3);
    assert(strcmp(front(dll), "one") == 0);

    pop_back(dll);
    assert(dll->size == 2);
    assert(strcmp(back(dll), "two") == 0);


    push_front(dll, "start");
    push_back(dll, "end");
    assert(dll->size == 4);
    assert(strcmp(front(dll), "start") == 0);
    assert(strcmp(back(dll), "end") == 0);
    pop_front(dll);
    pop_back(dll);
    assert(dll->size == 2);
    assert(strcmp(front(dll), "one") == 0);
    assert(strcmp(back(dll), "two") == 0);

    push_front(dll, "repeat");
    push_back(dll, "repeat");
    assert(dll->size == 4);
    assert(strcmp(front(dll), "repeat") == 0);
    assert(strcmp(back(dll), "repeat") == 0);

    found = find(dll, "repeat");
    assert(found != NULL);
    assert(strcmp(found->val, "repeat") == 0);

    free_dll(dll);
    dll = create_dll();
    assert(dll != NULL);
    assert(dll->size == 0);
    assert(dll->head == NULL);
    assert(dll->tail == NULL);

    push_back(dll, "only");
    assert(dll->size == 1);
    assert(strcmp(front(dll), "only") == 0);
    assert(strcmp(back(dll), "only") == 0);
    pop_front(dll);
    assert(dll->size == 0);
    assert(dll->head == NULL);
    assert(dll->tail == NULL);

    push_front(dll, "new");
    push_back(dll, "values");
    assert(dll->size == 2);
    assert(strcmp(front(dll), "new") == 0);
    assert(strcmp(back(dll), "values") == 0);

    free_dll(dll);

    printf("All tests passed!\n");

    return 0;
}
