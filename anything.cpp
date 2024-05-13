#include <iostream>

using namespace std;

int passGrade(int w, int e, int m) {
    int g[3]{};
    int count{0};

    g[0] = w;
    g[1] = e;
    g[2] = m;

    for (int i: g) {
        if (i >= 60) {
            count++;
        }
    }

    return count;
}

int main() {
    int n{0}, i{0};
    string studentName;
    int wGrade{0}, eGrade{0}, mGrade{0};
    cout << "전체 학생 수를 입력하세요: ";
    cin >> n;

    while (i < n) {
        cin >> studentName >> wGrade >> eGrade >> mGrade;
        cout << "이름: " << studentName << " 통과한 과목: " << passGrade(wGrade, eGrade, mGrade) << "\n";
        i++;
    }
}