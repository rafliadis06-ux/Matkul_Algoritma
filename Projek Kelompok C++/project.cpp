#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Proses {
    int id;
    int burst;
    int sisa;
    int tunggu = 0;
};

int main() {
    int jumlah, quantum;
    cout << "Jumlah proses: ";
    cin >> jumlah;

    vector<Proses> proses(jumlah);
    for (int i = 0; i < jumlah; i++) {
        cout << "Burst time P" << i + 1 << ": ";
        cin >> proses[i].burst;
        proses[i].sisa = proses[i].burst;
        proses[i].id = i + 1;
    }

    cout << "Quantum time: ";
    cin >> quantum;

    queue<int> antrian;
    for (int i = 0; i < jumlah; i++) {
        antrian.push(i);
    }

    int waktu = 0;
    vector<string> gantt;

    while (!antrian.empty()) {
        int idx = antrian.front();
        antrian.pop();

        if (proses[idx].sisa > quantum) {
            waktu += quantum;
            proses[idx].sisa -= quantum;
            gantt.push_back("P" + to_string(proses[idx].id));
            for (int i = 0; i < jumlah; i++) {
                if (i != idx && proses[i].sisa > 0)
                    proses[i].tunggu += quantum;
            }
            antrian.push(idx);
        } else {
            waktu += proses[idx].sisa;
            gantt.push_back("P" + to_string(proses[idx].id));
            for (int i = 0; i < jumlah; i++) {
                if (i != idx && proses[i].sisa > 0)
                    proses[i].tunggu += proses[idx].sisa;
            }
            proses[idx].sisa = 0;
        }
    }

    // Tampilkan Gantt Chart
    cout << "\nGantt Chart:\n| ";
    for (string p : gantt) {
        cout << p << " | ";
    }

    // Hitung rata-rata waktu tunggu
    float totalTunggu = 0;
    cout << "\n\nWaktu Tunggu:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "P" << proses[i].id << ": " << proses[i].tunggu << " ms\n";
        totalTunggu += proses[i].tunggu;
    }

    cout << "\nRata-rata waktu tunggu: " << totalTunggu / jumlah << " ms\n";

    return 0;
}
