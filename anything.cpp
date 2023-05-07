//#include <bits/stdc++.h>
//
//using namespace std;
//using ll = long long;

//ll fastpow(ll a, ll b, ll mod) {
//    if (b == 0) {
//        return 1;
//    }
//
//    ll sub = fastpow(a, b / 2, mod);
//    ll result = sub * sub % mod;
//
//    if (b % 2 == 1) {
//        result = result * a % mod;
//    }
//
//    return result;
//
//
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    int a, b, c;
//    cin >> a >> b >> c;
//    cout << fastpow(a, b, c) << "\n";
//
//
//    return 0;
//}

#include <bits/stdc++.h>

using namespace std;

class max_heap {
public:
    int size() {
        return cnt;
    }

    void push(int a) {
        heap[cnt++] = a;
        int child = cnt;
        int parent = cnt / 2;
        while (heap[child] > heap[parent] && child > 1) {
            swap(heap[child], heap[parent]);
            child = parent;
            parent = child / 2;
        }
    }

    int pop() {
        int result = heap[1];
        swap(heap[1], heap[cnt]);
        cnt--;
        int parent = 1;
        int child = parent * 2;



        return result;
    }


private:
    int heap[100001];
    int cnt = 1;


};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int> pq;
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        for (int i = 0; i < num; ++i) {
            int a;
            cin >> a;
            pq.push(a);
        }
        for (int i = 0; i < num; ++i) {
            cout << pq.top() << "\n";
            pq.pop();

        }


    }


}
