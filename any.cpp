#include <iostream>
#include <vector>

using namespace std;

class user {
public:

    user(string &s, string &birth, int &id, int &ph) {
        set_name(s);
        set_birth(birth);
        set_id(id);
        set_phone(ph);
    }

    void set_name(string &s) {
        name = s;
    }

    string get_name() {
        return name;
    }

    void set_id(int &n) {
        id = n;
    }

    int get_id() {
        return id;
    }

    void set_birth(string &s) {
        birth = s;
    }

    string get_birth() {
        return birth;
    }

    void set_phone(int &i) {
        phone = i;
    }

    int get_phone() {
        return phone;
    }

    void print_info() {
        cout << "이름: " << this->get_name() << "\n";
        string temp = this->get_birth();
        cout << "생년월일: " << temp[0] << temp[1] << "/" << temp[2] << temp[3] << "/" << temp[4] << temp[5] << "\n";
        cout << "전화번호: " << this->get_phone() << "\n";
        cout << "\n";
    }

    void set_rent(int a, int b) {
        rent_book_num.push_back({a, b});
    }

    vector<pair<int, int>> get_rent() {
        return rent_book_num;
    }


private:
    int id;
    string birth;
    int phone;
    string name;
    vector<pair<int, int>> rent_book_num;

};


class book {
public:
    book(string &s, int &num, int &isbn, int &count) {
        set_book_name(s);
        set_book_num(num);
        set_book_count(count);
        set_book_isbn(isbn);
    }

    void set_book_name(string &s) {
        name = s;
    }

    string get_book_name() {
        return name;
    }

    void set_book_num(int &i) {
        num = i;
    }

    int get_book_num() {
        return num;
    }

    void set_book_count(int &i) {
        count = i;
    }

    int get_book_count() {
        return count;
    }

    void set_book_isbn(int &i) {
        isbn = i;
    }

    int get_book_isbn() {
        return isbn;
    }

    void print_info() {
        cout << "제목: " << this->get_book_name() << "\n";
        cout << "ISBN: " << this->get_book_isbn() << "\n";
        cout << "수량: " << this->get_book_count() << "\n";
        cout << "\n";
    }


private:
    string name;
    int count;
    int isbn;
    int num;

};

vector<user> User;
vector<book> Book;
vector<int> delet_user;
vector<int> delet_book;

int main() {
    int user_count = 0;
    int book_count = 0;
    int modes;
    cout << "select the mode 0) 회원등록 1)회원정보 확인 2)회원정보 수정 3)도서등록 4)도서정보 수정 5)도서 검색 6)도서 대여/반납 7)정보 삭제 : ";
    while (cin >> modes) {
        switch (modes) {
            case 0: {
                user_count++;
                cout << "회원이름을 입력하세요: ";
                string name;
                cin.ignore(100, '\n');
                getline(cin, name);
                cout << "010을 제외한 전화번호 8자리를 입력하세요: ";
                int num;
                cin >> num;
                cout << "생년월일 6자리를 입력하세요: ";
                string birth;
                cin >> birth;
                User.push_back({name, birth, user_count, num});
                cout << "회원번호는 " << user_count << " 입니다.\n";
                cout << "\n";
                break;
            }
            case 1:
                cout << "회원 번호를 입력하세요: ";
                int Num;
                cin >> Num;
                Num--;
                if(find(delet_user.begin(), delet_user.end(),Num) != delet_user.end()){
                    cout << "삭제된 회원입니다.\n\n";
                    break;
                }
                if (Num > User.size() || Num < 0) cout << "회원번호가 틀렸습니다.\n\n";
                else {
                    User[Num].print_info();
                }
                break;
            case 2:
                cout << "변경할 회원의 번호를 입력하세요: ";
                int num;
                cin >> num;
                num--;
                if(find(delet_user.begin(), delet_user.end(),num) != delet_user.end()){
                    cout << "삭제된 회원입니다.\n\n";
                    break;
                }
                if (num > User.size() || num < 0) {
                    cout << "회원번호가 틀렸습니다.\n\n";
                    break;
                }
                cout << "변경할 요소를 입력하세요 1)이름 2)전화번호 3)생년월일 : ";
                int m;
                cin >> m;
                if (m == 1) {
                    cout << "변경할 값을 입력하세요: ";
                    cin.ignore(100, '\n');
                    string n;
                    getline(cin, n);
                    User[num].set_name(n);
                    cout << "이름 변경이 완료되었습니다\n\n";
                } else if (m == 2) {
                    cout << "변경할 값을 입력하세요: ";
                    int n;
                    cin >> n;
                    User[num].set_phone(n);
                    cout << "전화번호 변경이 완료되었습니다\n\n";
                } else {
                    cout << "변경할 값을 입력하세요: ";
                    string n;
                    cin >> n;
                    User[num].set_birth(n);
                    cout << "생년원일 변경이 완료되었습니다\n\n";
                }
                break;
            case 3: {
                book_count++;
                cout << "책 이름을 입력하세요: ";
                cin.ignore(100, '\n');
                string name;
                getline(cin, name);
                cout << "책의 ISBN을 입력하세요: ";
                int isbn;
                cin >> isbn;
                cout << "책의 수량을 입력하세요: ";
                cin >> num;
                Book.push_back({name, book_count, isbn, num});
                cout << "책 등록이 완료되었습니다.\n";
                cout << "등럭번호는 " << book_count << "입니다.\n";
                cout << "\n";
                break;
            }
            case 4:
                cout << "변경할 도서의 등록번호를 입력하세요: ";
                cin >> num;
                num--;
                if (num > User.size() || num < 0) {
                    cout << "도서 등록번호가 틀렸습니다.\n\n";
                    break;
                }
                if(find(delet_book.begin(), delet_book.end(),num) != delet_user.end()){
                    cout << "삭제된 도서입니다.\n\n";
                    break;
                }

                cout << "변경할 요소를 입력하세요 1)이름 2)ISBN 3)수량 : ";
                cin >> m;
                if (m == 1) {
                    cout << "변경할 값을 입력하세요: ";
                    cin.ignore(100, '\n');
                    string n;
                    getline(cin, n);
                    Book[num].set_book_name(n);
                    cout << "이름 변경이 완료되었습니다\n";
                } else if (m == 2) {
                    cout << "변경할 값을 입력하세요: ";
                    int n;
                    cin >> n;
                    Book[num].set_book_isbn(n);
                    cout << "ISBN 변경이 완료되었습니다\n";
                } else {
                    cout << "변경할 값을 입력하세요: ";
                    int n;
                    cin >> n;
                    Book[num].set_book_count(n);
                    cout << "수량변경이 완료되었습니다\n";
                }
                break;
            case 5:
                cout << "도서 등록번호를 입력하세요: ";
                cin >> Num;
                Num--;
                if (Num > Book.size() || Num < 0) cout << "등록번호가 틀렸습니다.\n\n";
                else {
                    Book[Num].print_info();
                }
                break;
            case 6:
                cout << "1)대출 2)반납 :";
                int a;
                cin >> a;
                switch (a) {
                    case 1: {
                        string search;
                        cout << "책 제목을 입력해주세요: ";
                        cin.ignore(100, '\n');
                        getline(cin, search);
                        bool flag = false;
                        int n, m;
                        for (int i = 0; i < Book.size(); ++i) {
                            if (Book[i].get_book_name() == search) {
                                flag = true;
                                n = i;
                                break;
                            }
                        }
                        if(find(delet_book.begin(), delet_book.end(),n) != delet_user.end()){
                            cout << "삭제된 도서입니다.\n\n";
                            break;
                        }
                        if (!flag) {
                            cout << "해당 책이 없거나 이름이 틀렸습니다. \n\n";
                            break;
                        }
                        flag = false;
                        Book[n].print_info();
                        if (Book[n].get_book_count() == 0) {
                            cout << "대여할 수 없습니다.\n\n";
                            break;
                        } else {
                            cout << "대출하실 분의 전화번호를 입력해주세요: ";
                            int b;
                            cin >> b;
                            for (int j = 0; j < User.size(); ++j) {
                                if (User[j].get_phone() == b) {
                                    flag = true;
                                    m = j;
                                    break;
                                }
                            }
                            if(find(delet_user.begin(), delet_user.end(),m) != delet_user.end()){
                                cout << "삭제된 회원입니다.\n\n";
                                break;
                            }
                            if (!flag) {
                                cout << "전화번호가 존재하거나 틀렸습니다.\n\n";
                                break;
                            }
                            cout << "빌릴 권수를 입력해주세요 :";
                            int c;
                            cin >> c;
                            int cal = Book[n].get_book_count() - c;
                            if (cal) {
                                User[m].set_rent(n, c);
                                Book[n].set_book_count(cal);
                                cout << c << "권 대여가 완료되었습니다.";
                            } else {
                                cout << "대여가능 권수가 초과했습니다.\n\n";
                            }
                        }

                        break;
                    }

                    case 2:
                        cout << "회원 전화번호를 입력하세요.: ";
                        int d;
                        cin >> d;
                        bool flag = false;
                        for (int j = 0; j < User.size(); ++j) {
                            if (User[j].get_phone() == d) {
                                flag = true;
                                m = j;
                                break;
                            }
                        }
                        if (!flag) {
                            cout << "전화번호가 존재하거나 틀렸습니다.\n\n";
                            break;
                        }
                        vector<pair<int, int>> v = User[m].get_rent();
                        for (int i = 0; i < v.size(); ++i) {
                            cout << i + 1<< "\n";
                            cout << "빌린 책 제목: " << Book[v[i].first].get_book_name() << "\n";
                            cout << "권수: " << v[i].second << "\n";
                        }
                        cout << "반납하실 번호와 권수를 입력하세요.: ";
                        int e, f;
                        cin >> e >> f;
                        e--;
                        if (e < 0 || e > v.size() || v[e].second > f || f < 0) {
                            cout << "잘못된 입력입니다.\n\n";
                            break;
                        }
                        int temp = Book[v[e].first].get_book_count() + f;
                        Book[v[e].first].set_book_count(temp);
                        cout << "반납이 완료 되었습니다.\n\n";
                        v.erase(v.begin() + e);
                        break;
                }
                break;
            case 7:
                int g;
                cout << "1)회원 2)책: ";
                cin >> g;
                if (g == 1) {
                    cout << "삭제할 회원 번호를 입력하세요: ";
                    int h;
                    cin >> h;
                    h--;
                    if (h > -1 && h < User.size()) {
                        delet_user.push_back(h);
                        cout << "삭제가 완료 되었습니다.\n\n";
                    } else {
                        cout << "잘못된 값입니다.\n\n";
                    }
                } else if(g == 2){
                    cout << "삭제할 책 번호를 입력하세요: ";
                    int h;
                    cin >> h;
                    h--;
                    if (h > -1 && h < Book.size()) {
                        delet_book.push_back(h);
                        cout << "삭제가 완료 되었습니다.\n\n";
                    } else {
                        cout << "잘못된 값입니다.\n\n";
                    }
                }
                break;
            default:
                break;
        }

        cout << "select the mode 0) 회원등록 1)회원정보 확인 2)회원정보 수정 3)도서등록 4)도서정보 수정 5)도서 검색 6)도서 대여/반납 7)정보 삭제 : ";
    }
    return 0;
}
