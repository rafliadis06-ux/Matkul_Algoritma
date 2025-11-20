#include <iostream>
#include <stack>
using namespace std;

// Fungsi untuk mengecek validitas kurung
bool isValid(string expr) {
    stack<char> s;

    for (char c : expr) {
        // Jika karakter adalah kurung buka, masukkan ke stack
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        // Jika karakter adalah kurung tutup, cek pasangan
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false; // tidak ada pasangan

            char top = s.top();
            s.pop();

            // cek apakah pasangan sesuai
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    // Jika stack kosong, berarti semua kurung berpasangan
    return s.empty();
}

int main() {
    string ekspresi;
    cout << "Masukkan ekspresi: ";
    getline(cin, ekspresi);

    if (isValid(ekspresi))
        cout << "Valid" << endl;
    else
        cout << "Tidak Valid" << endl;

    return 0;
}