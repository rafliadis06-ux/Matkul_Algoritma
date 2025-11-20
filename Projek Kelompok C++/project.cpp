#include <iostream>
#include <queue>
using namespace std;

struct Proses {
    string nama;
    int durasi;
    int tunggu;
    int selesai;
};

int main() {
    int n, quantum;
    cout << "Masukkan jumlah proses: ";
    cin >> n;
    cout << "Masukkan quantum time: ";
    cin >> quantum;

    queue<Process> q;
    Process p[n];
    for (int i = 0; i < n; i++) {
        cout << "Nama proses: ";
        cin >> p[i].name;
        cout << "Burst time: ";
        cin >> p[i].burst;
        p[i].waiting = 0;
        p[i].turnaround = 0;
        q.push(p[i]);
    }

    int time = 0;
    cout << "\n=== Gantt Chart ===\n";
    while (!q.empty()) {
        Process cur = q.front();
        q.pop();

        int exec = min(cur.burst, quantum);
        cout << time << " | " << cur.name << " | ";
        time += exec;
        cur.burst -= exec;

        // Update waiting & turnaround
        for (int i = 0; i < n; i++) {
            if (p[i].name != cur.name && p[i].burst > 0) {
                p[i].waiting += exec;
            }
        }

        if (cur.burst > 0) {
            q.push(cur); // proses belum selesai, masuk lagi ke antrian
        } else {
            for (int i = 0; i < n; i++) {
                if (p[i].name == cur.name) {
                    p[i].turnaround = time;
                }
            }
        }
    }
    cout << time << "\n";

    // Hitung rata-rata waktu tunggu
    double totalWait = 0;
    for (int i = 0; i < n; i++) {
        totalWait += p[i].waiting;
        cout << p[i].name << " - Waiting: " << p[i].waiting
             << ", Turnaround: " << p[i].turnaround << endl;
    }
    cout << "Rata-rata waktu tunggu: " << totalWait / n << endl;

    return 0;
}
