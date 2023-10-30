#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, k; // 문제에서의 N,K와 동일
    vector<int> v1(0); // 1~N까지를 저장할 벡터
    vector<int> v2(0); // 요세푸스 순열 순서로 저장될 벡터
    cin >> n >> k;
    for (int yo = 1; yo <= n; yo++) v1.push_back(yo); // v1에 1~N까지 저장
    int abc = k; // 처음 입력받은 K값을 유지해주기 위한 임시 변수
    while (size(v1) != 0) {
        if (abc > size(v1)) { // else문에서 abc-1 이 들어가므로 >=이 아닌 >로 비교
            for (int i = 0; i < size(v2); i++) { // 요세푸스 벡터로 빠져나간 값을 제거해주는 코드
                remove(v1.begin(), v1.end(), v2[i]);
            }
            abc -= size(v1); // resize전에 abc값 미리 초기화
            v1.resize(n - size(v2)); // remove함수는 벡터의 크기는 변하지 않으므로 resize를 통해 겅제로 변환
        } else {
            v2.push_back(v1[abc - 1]);
            abc += k;
        }
    }

    // 요세푸스 순열을 문제의 출력 조건에 맞게 출력하기 위한 코드
    cout << '<' << v2[0] << ", ";
    for (int j = 1; j < size(v2) - 1; j++) cout << v2[j] << ", ";
    cout << v2[size(v2) - 1] << '>';
    return 0;
}

