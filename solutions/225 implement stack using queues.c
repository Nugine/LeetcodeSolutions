#define create(tp) ((tp *)malloc(sizeof(tp)))

typedef struct _node {
    struct _node *prev;
    int val;
} Node;

typedef struct _stack {
    Node *tail;
    int size;
    int maxSize;
} MyStack;

/** Initialize your data structure here. */
MyStack *myStackCreate(int maxSize) {
    MyStack *stack = create(MyStack);
    stack->tail = NULL;
    stack->size = 0;
    stack->maxSize = maxSize;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack *obj, int x) {
    if (obj->size < obj->maxSize) {
        Node *nd = create(Node);
        nd->val = x;
        if (obj->size == 0) {
            obj->tail = nd;
            nd->prev = NULL;
        } else {
            nd->prev = obj->tail;
            obj->tail = nd;
        }
        ++obj->size;
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack *obj) {
    int rv;
    if (obj->size > 0) {
        Node *nd;
        nd = obj->tail;
        rv = nd->val;
        obj->tail = nd->prev;
        free(nd);
        --obj->size;
    }
    return rv;
}

/** Get the top element. */
int myStackTop(MyStack *obj) {
    int rv;
    if (obj->size > 0) {
        rv = obj->tail->val;
    }
    return rv;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack *obj) { return obj->size == 0; }

void myStackFree(MyStack *obj) {
    if (obj->size == 0) {
        free(obj);
        return;
    }
    Node *nd;
    nd = obj->tail;
    while (nd != NULL) {
        obj->tail = nd->prev;
        free(nd);
        nd = obj->tail;
    }
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * struct MyStack* obj = myStackCreate(maxSize);
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */