#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

//vi merge(vi v1, vi v2) {
//    int l = 0, r = 0;
//    vi v;
//    while (l < v1.size() && r < v2.size()) {
//        if (v1[l] < v2[r] && l < v1.size()) {
//            v.push_back(v1[l]);
//            l++;
//        } else if (v1[l] > v2[r] && r < v2.size()) {
//            v.push_back(v2[r]);
//            r++;
//        }
//    }
//    return v;
//}
//
//
//vi mergesort(vi v) {
//    vi v1, v2;
//    if (v.size() > 1) {
//        int m = v.size() / 2;
//        for (int i = 0; i < m; ++i) {
//            v1.push_back(v[i]);
//        }
//        for (int i = m; i < v.size(); ++i) {
//            v2.push_back(v[i]);
//        }
//    }
//    return merge(mergesort(v1), mergesort(v2));
//}


class Car {
public:
    Car(const string brand, const int price);
    void setBrand(const string brand);
    string getBrand();
    void setPrice(const int price);
    int getPrice();
    void printCarInfo();
private:
    string carBrand;
    int carPrice;
};

class SportsCar : public Car {
public:
    SportsCar(const string brand, const int price)
            : Car(brand, price), turbo(false) {}
    void toggleTurbo() {
        if(turbo)
            turbo = false;
        else
            turbo = true;
    }
private:
    bool turbo;
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    int t;
//    cin >> t;
//    vi v(t);
//    for (int i = 0; i < t; ++i) {
//        cin >> v[t];
//    }
//    mergesort(v);
//    for (int i = 0; i < t; ++i) {
//        cout << v[i] << " ";
//    }

    while ()















    return 0;
}


