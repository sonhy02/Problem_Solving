#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

struct node {
    char data;
    node *next;
};

class lis {
public:
    lis() {
        head = new node;
        tail = new node;
        head->next = tail;
        tail->next = NULL;
    }

    void push_back(char c) {
        if (size == 0) {
            auto temp = new node;
            temp->data = c;
            head = temp;
            tail = temp;
            tail->next = NULL;
            size++;
        } else {
            auto temp = new node;
            temp->data = c;
            tail->next = temp;
            tail_prev = tail;
            tail = temp;
            tail->next = NULL;
            size++;
        }
    }

    void l() {
        auto temp = head;
        head = head->next;
        tail_prev = tail;
        tail_prev->next = temp;
        tail = temp;
        tail->next = NULL;
    }

    void r() {
        auto temp = tail;
        tail->next = head;
        head = tail;
        tail = tail_prev;
        tail->next = NULL;
        temp = head;
        while (temp->next != tail) temp = temp->next;
        tail_prev = temp;
    }

    void print() {
        auto temp = head;
        while (temp != NULL) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << "\n";
    }

    int size = 0;
    node *head;
    node *tail;
    node *tail_prev;

};

void ss(lis &a, lis &b, int l) {
    auto t1 = a.head;
    auto t2 = b.head;
    for (int i = 0; i < l - 1; ++i) {
        t1 = t1->next;
        t2 = t2->next;
    }
    auto t3 = t1->next;
    t1->next = t2->next;
    t2->next = t3;
    auto temp = a.head;
    a.head = b.head;
    b.head = temp;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, r, q;
    cin >> n >> r >> q;
    string s1, s2;
    cin >> s1 >> s2;
    lis l1, l2;
    for (auto i: s1) {
        l1.push_back(i);
    }
    for (auto i: s2) {
        l2.push_back(i);
    }
    while (q--) {
        string s;
        cin >> s;
        if (s == "L") {
            int a;
            cin >> a;
            if (a == 1) l1.l();
            else l2.l();

        } else if (s == "R") {
            int a;
            cin >> a;
            if (a == 1) l1.r();
            else l2.r();
        } else if (s == "I") {
            r++;
        } else if (s == "D") {
            r--;
        } else if (s == "S") {
            ss(l1, l2, r);
        }
    }
    l1.print();
    l2.print();

    return 0;
}