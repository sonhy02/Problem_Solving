#include <iostream>
#include <unordered_set>
using namespace std;

string check_password(string database, int length, string lower, string upper) {
    unordered_set<char> possible_digits;

    // 주어진 패스워드 데이터베이스에서 패스워드에 포함될 수 있는 숫자들을 추출합니다.
    for (char digit : database) {
        possible_digits.insert(digit);
    }

    // 패스워드에 포함되지 않는 숫자들을 제외합니다.
    unordered_set<char> remove_digits;
    for (char digit : possible_digits) {
        if (lower.find(digit) == string::npos) {
            remove_digits.insert(digit);
        }
    }
    for (char digit : remove_digits) {
        possible_digits.erase(digit);
    }

    // 주어진 범위 내에서 각 자리의 숫자들이 만족하는지 확인합니다.
    for (int i = 0; i < length; i++) {
        if (lower[i] > upper[i] || possible_digits.find(lower[i]) == possible_digits.end() || possible_digits.find(upper[i]) == possible_digits.end()) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    int t;
    cin >> t; // 테스트케이스 개수

    for (int i = 0; i < t; i++) {
        string database;
        cin >> database; // 패스워드 데이터베이스

        int length;
        cin >> length; // 패스워드 길이

        string lower;
        cin >> lower; // 각 자리의 최소 제한

        string upper;
        cin >> upper; // 각 자리의 최대 제한

        string result = check_password(database, length, lower, upper);
        cout << result << endl;
    }

    return 0;
}
