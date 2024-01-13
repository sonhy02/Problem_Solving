#include <iostream>
#include <array>
#include <cmath>

using namespace std;

array<array<char, 6600>, 6600> arr;
int a;

void Star(array<array<char, 6600>, 6600> &s, int n, int N, int m, int M) {
    int nn = (N - n) / 3;
    int mm = (M - m) / 3;
    if (nn == 0 || mm == 0) return;
    Star(s, n, n + nn, m, m + mm);
    Star(s, n + nn, N - nn, m, m + mm);
    Star(s, N - nn, N, m, m + mm);
    Star(s, n, n + nn, m + mm, M - mm);

    for (int i = n + nn; i < N - nn; i++)
        for (int j = m + mm; j < M - mm; j++)
            s[i][j] = ' ';

    Star(s, N - nn, N, m + mm, M - mm);
    Star(s, n, n + nn, M - mm, M);
    Star(s, n + nn, N - nn, M - mm, M);
    Star(s, N - nn, N, M - mm, M);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a;
    int i, j;
    for (i = 0; i < a; i++)
        for (j = 0; j < a; j++)
            arr[i][j] = '*';
    Star(arr, 0, a, 0, a);
    for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++)
            cout << arr[i][j];
        cout << '\n';
    }
    return 0;
}
