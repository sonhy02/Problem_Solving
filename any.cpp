#include <iostream>

using namespace std;

class arrayVector {
public:
    arrayVector() {
        capa = 1;
        arr = new int[1];
        n = 0;
    }

    bool empty() {
        return (n == 0);
    }

    int size() {
        return n;
    }

    int at(int idx) {
        if (idx < 0 || idx >= n) {
            return -1;
        } else return arr[idx];
    }

    void set(int idx, int d) {
        if (idx < 0 || idx >= n) {
            return;
        } else arr[idx] = d;
    }

    void erase(int idx) {
        if (idx < 0 || idx >= n) {
            return;
        } else {
            for (int i = idx + 1; i < n; ++i) {
                arr[i - 1] = arr[i];
            }
            n--;
        }
    }

    void insert(int idx, int d) {
        if (idx < 0 || idx >= n) {
            return;
        } else {
            if (n == capa)
                reserve(2 * capa);
            for (int i = n - 1; i >= idx; --i) {
                arr[i + 1] = arr[i];
            }
            arr[idx] = d;
            n++;
        }
    }

private:
    int capa;
    int n;
    int *arr;

    void reserve(int size) {
        if (size <= capa) return;
        else {
            int *temparr = new int[size];
            for (int i = 0; i < n; ++i) {
                temparr[i] = arr[i];
            }
            if (arr != NULL)
                delete[] arr;
            arr = temparr;
            capa = size;
        }
    }
};

struct node {
    int data;
    node *past;
    node *next;
};

class nodeList {

    nodeList() {
        head = new node();
        tail = new node();
        head->next = tail;
        tail->past = head;
        head->past = tail->next = NULL;
        n = 0;
    }

    bool empty() {
        return (n == 0);
    }

    int size() {
        return n;
    }

    node *begin() {
        return head->next;
    }

    node *end() {
        return tail;
    }



private:
    node *head;
    node *tail;
    int n;
};


int main() {

    return 0;
}
