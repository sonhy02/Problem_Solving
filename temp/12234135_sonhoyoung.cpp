#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int s1, s2, s3, s4, s5, s6, s7, s8;
bool c1, c2, c3, c4, c5, c6, c7, c8;

void check(int i) {

	int seat = rand() % 8 + 1;

	switch (seat)
	{
	case 1:
		if (c1 == 0) { s1 = i; c1 = 1; }
		else check(i);
		break;
	case 2:
		if (c2 == 0) { s2 = i; c2 = 1; }
		else check(i);
		break;
	case 3:
		if (c3 == 0) { s3 = i; c3 = 1; }
		else check(i);
		break;
	case 4:
		if (c4 == 0) { s4 = i; c4 = 1; }
		else check(i);
		break;
	case 5:
		if (c5 == 0) { s5 = i; c5 = 1; }
		else check(i);
		break;
	case 6:
		if (c6 == 0) { s6 = i; c6 = 1; }
		else check(i);
		break;
	case 7:
		if (c7 == 0) { s7 = i; c7 = 1; }
		else check(i);
		break;
	case 8:
		if (c8 == 0) { s8 = i; c8 = 1; }
		else check(i);
		break;
	default:
		break;
	}



}




int main() {
	int k = 0;
	int p;
	int nt, ns;
	int num;
	cout << "Enter the numbers of tables [1, 16] and students [1, 128]: ";
	cin >> nt >> ns;

	srand(nt);
	for (int i = 1; i <= nt; i++) {
		cout << "Enter the number of students in Table" << " " << i << ": ";
		cin >> num;
		p = k + 1;
		for (int j = p; j <= p + num - 1; j++) {
			check(j);
			k++;
		}

		cout << "<Table " << i << ">\n";
		if (s1 == 0) {
			cout << "Seat 1: ---------\n";
		}
		else {
			cout << "Seat 1: Student " << s1 << "\n";
		}
		if (s2 == 0) {
			cout << "Seat 2: ---------\n";
		}
		else {
			cout << "Seat 2: Student " << s2 << "\n";
		}
		if (s3 == 0) {
			cout << "Seat 3: ---------\n";
		}
		else {
			cout << "Seat 3: Student " << s3 << "\n";
		}
		if (s4 == 0) {
			cout << "Seat 4: ---------\n";
		}
		else {
			cout << "Seat 4: Student " << s4 << "\n";
		}
		if (s5 == 0) {
			cout << "Seat 5: ---------\n";
		}
		else {
			cout << "Seat 5: Student " << s5 << "\n";
		}
		if (s6 == 0) {
			cout << "Seat 6: ---------\n";
		}
		else {
			cout << "Seat 6: Student " << s6 << "\n";
		}
		if (s7 == 0) {
			cout << "Seat 7: ---------\n";
		}
		else {
			cout << "Seat 7: Student " << s7 << "\n";
		}
		if (s8 == 0) {
			cout << "Seat 8: ---------\n";
		}
		else {
			cout << "Seat 8: Student " << s8 << "\n";
		}

		c1 = 0; c2 = 0; c3 = 0; c4 = 0; c5 = 0; c6 = 0; c7 = 0; c8 = 0;
		s1 = 0; s2 = 0; s3 = 0; s4 = 0; s5 = 0; s6 = 0; s7 = 0; s8 = 0;
		cout << "\n";
	}





	return 0;





}


//���̺� ���� �¼� 8���� ����
//��Ģ: ����ġ�� ���,�迭 ����,���̺� ������ ���� �õ�� ����, �л���ȣ�� 1���� N��, �̹� ������ �¼��̸� �� �¼� ���� �� ���� ���� �����Ͽ� �¼��� ������, �Է¿��� ���� ����
//�Է�: 1,16 ���� ���̺� ���� - 1,128 ������ ���Ի� �ο�, ���̺� ���� �ο� (1,8 ����)
// ���: ���̺� ���� �¼���ȣ�� ������ �л� ��ȣ ���, ������ �л� ������ ---------(���� 9��)�� ���
