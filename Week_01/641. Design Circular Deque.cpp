class MyCircularDeque {
public:
    struct DLNode {
        int val;

        DLNode *next;
        DLNode *prev;

        DLNode() : val(-1), next(NULL), prev(NULL) {};

        DLNode(int v) : val(v), next(NULL), prev(NULL) {}
    };

    int size;
    int capacity;
    DLNode *head;
    DLNode *tail;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capacity = k;
        size = 0;
        head = new DLNode(-1);
        tail = new DLNode(-1);
        head->prev = tail;
        head->next = tail;
        tail->prev = head;
        tail->next = head;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (this->isFull()) {
            return false;
        }
        DLNode *node = new DLNode(value);
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
        size++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (this->isFull()) {
            return false;
        }
        DLNode *node = new DLNode(value);
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
        node->next = tail;
        size++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (this->isEmpty()) {
            return false;
        }
        DLNode *node = head->next;
        node->next->prev = head;
        head->next = node->next;
        delete node;
        size--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (this->isEmpty()) {
            return false;
        }
        DLNode *node = tail->prev;
        node->prev->next = tail;
        tail->prev = node->prev;
        delete node;
        size--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        return head->next->val;
    }

    /** Get the last item from the deque. */
    int getRear() {
        return tail->prev->val;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == capacity;
    }
};
