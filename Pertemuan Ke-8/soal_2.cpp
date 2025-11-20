#include <iostream>
#include <stack>   // pakai STL stack
using namespace std;

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);   // input kalimat lengkap (termasuk spasi)

    stack<char> s;

    // Masukkan setiap karakter ke dalam stack
    for (char c : kalimat) {
        s.push(c);
    }

    cout << "Kalimat terbalik: ";
    // Ambil karakter dari stack satu per satu
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}