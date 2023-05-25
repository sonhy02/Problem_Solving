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

//#include <bits/stdc++.h>
//
//using namespace std;
//
//class max_heap {
//public:
//    int size() {
//        return cnt;
//    }
//
//    void push(int a) {
//        heap[cnt++] = a;
//        int child = cnt;
//        int parent = cnt / 2;
//        while (heap[child] > heap[parent] && child > 1) {
//            swap(heap[child], heap[parent]);
//            child = parent;
//            parent = child / 2;
//        }
//    }
//
//    int pop() {
//        int result = heap[1];
//        swap(heap[1], heap[cnt]);
//        cnt--;
//        int parent = 1;
//        int child = parent * 2;
//
//
//
//        return result;
//    }
//
//
//private:
//    int heap[100001];
//    int cnt = 1;
//
//
//};
//
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    priority_queue<int> pq;
//    int t;
//    cin >> t;
//    while (t--) {
//        int num;
//        cin >> num;
//        for (int i = 0; i < num; ++i) {
//            int a;
//            cin >> a;
//            pq.push(a);
//        }
//        for (int i = 0; i < num; ++i) {
//            cout << pq.top() << "\n";
//            pq.pop();
//
//        }
//
//
//    }
//
//
//}

//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//
//int main() {
//    while (true) {
//        string s;
//        int sign = 0; // pop에서 걸러진 경우
//        getline(cin, s);
//        if (s == "\n") {
//            continue;
//        }
//        if (s == ".") {
//            break;
//        }
//        stack<int> round;
//        stack<int> square;
//        int count = 0;
//
//        round.push(0); // 초기화 작업
//        square.push(0);
//
//        for (int i = 0; i < s.length(); i++) {
//            if (s[i] == '(') {
//                count++;
//                round.push(count);
//            }
//            else if (s[i] == ')') {
//                if (round.size() == 1 || round.top() != count) {
//                    cout << "no\n";
//                    sign = 1;
//                    break;
//                }
//                round.pop();
//                count--;
//            }
//            else if (s[i] == '[') {
//                count++;
//                square.push(count);
//
//            }
//            else if (s[i] == ']') {
//                if (square.size() == 1 || square.top() != count) {
//                    cout << "no\n";
//                    sign = 1;
//                    break;
//                }
//                square.pop();
//                count--;
//            }
//        }
//        if (sign == 1) {
//            continue;
//        }
//        if (square.size() == 1 && round.size() == 1) {
//            cout << "yes\n";
//        }
//        else if ((square.size() == 1 && round.size() >= 1) || (square.size() >= 1 && round.size() == 1)){
//            cout << "no\n";
//        }
//    }
//}
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

class Candidate {
public:
    static const int maxLength{11};

    Candidate(unsigned candID = 0, const string &candName = "", unsigned v = 0);

    void setID(unsigned candID);

    unsigned getID() const;

    void setName(const string &candName);

    string getName() const;

    void setVotes(unsigned v);

    unsigned getVotes() const;

    void increaseVotes();

private:
    unsigned ID;
    char name[maxLength];
    unsigned votes;
};

int main() {
    cout << "Enter the number of candidates and polls: ";
    int n{0};
    int votenum{0};
    cin >> n >> votenum;
    Candidate cand[10];
    Candidate *candPtr{cand};
    cin.ignore(100, '\n');
    for (int i{0}; i < n; i++) {
        string name;
        cout << "Enter the name of candidate #" << i + 1 << ": ";
        getline(cin, name);
        (*(candPtr + i)).setName(name);
        (*(candPtr + i)).setID(i + 1);
        (*(candPtr + i)).setVotes(0);
    }
    srand(votenum);
    for (int i{0}; i < votenum; i++) {
        int vote = rand() % n;
        (*(candPtr + vote)).increaseVotes();
    }
    cout << "\nResults of " << votenum << " exit polls\n";
    for (int i = 0; i < n; i++) {
        cout << "Candidate #" << i + 1 << ": ";
        int value = (*(candPtr + i)).getVotes() + 50;
        value = value / 100;
        for (int j = 0; j < value; j++) {
            cout << "*";
        }
        cout << fixed << setprecision(2) << " (" << (*(candPtr + i)).getVotes() << " votes, "
             << ((double) (*(candPtr + i)).getVotes() / votenum) * 100 << "%)\n";
    }
    int index{0};
    unsigned int max = 0;
    for (int i = 0; i < n; i++) {
        if ((*(candPtr + i)).getVotes() > max) {
            max = (*(candPtr + i)).getVotes();
            index = i;
        }
    }
    cout << "\nCandidate #" << (*(candPtr + index)).getID() << " " << (*(candPtr + index)).getName()
         << " is likely to win.";
}

Candidate::Candidate(unsigned candID, const string &candName, unsigned v) {
    ID = candID;
    for (int i = 0; i < 11; i++) {
        *(name + i) = '\0';
    }
    votes = v;
}

void Candidate::setID(unsigned candID) {
    ID = candID;
}

unsigned Candidate::getID() const {
    return ID;
}

void Candidate::setName(const string &candName) {
    if (candName.length() < 10) {
        for (int i = 0; i < candName.length(); i++) {
            *(name + i) = candName[i];
        }
    } else {
        for (int i = 0; i < 10; i++) {
            *(name + i) = candName[i];
        }
    }
}

string Candidate::getName() const {
    return name;
}

void Candidate::setVotes(unsigned v) {
    votes = v;
}

unsigned Candidate::getVotes() const {
    return votes;
}

void Candidate::increaseVotes() {
    votes++;
}