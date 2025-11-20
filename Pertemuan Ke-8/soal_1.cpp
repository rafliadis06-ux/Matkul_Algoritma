#include <iostream>
using namespace std;

int *stackArr;   // pointer ke array stack
int top = -1;    // posisi elemen paling atas
int capacity;    // kapasitas maksimal stack

// Fungsi Push
void push(int value) {
    if (top >= capacity - 1) {
        cout << "Stack penuh! Tidak bisa menambahkan data.\n";
        return;
    }
    stackArr[++top] = value;
    cout << value << " berhasil ditambahkan ke stack.\n";
}

// Fungsi Pop
void pop() {
    if (top == -1) {
        cout << "Stack kosong! Tidak ada data yang bisa dihapus.\n";
        return;
    }
    cout << stackArr[top--] << " berhasil dihapus dari stack.\n";
}

// Fungsi Peek
void peek() {
    if (top == -1) {
        cout << "Stack kosong!\n";
        return;
    }
    cout << "Elemen paling atas: " << stackArr[top] << endl;
}

// Fungsi IsEmpty
bool isEmpty() {
    return top == -1;
}

// Fungsi Size
int size() {
    return top + 1;
}

int main() {
    cout << "Masukkan kapasitas maksimal stack: ";
    cin >> capacity;
    stackArr = new int[capacity]; // alokasi array sesuai kapasitas

    int pilihan, data;
    do {
        cout << "\n=== MENU STACK ===\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. IsEmpty\n";
        cout << "5. Size\n";
        cout << "6. Exit\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan data: ";
            cin >> data;
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            cout << (isEmpty() ? "Stack kosong\n" : "Stack tidak kosong\n");
            break;
        case 5:
            cout << "Jumlah elemen: " << size() << endl;
            break;
        case 6:
            cout << "Keluar program.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    delete[] stackArr; // bebaskan memori
    return 0;
}
