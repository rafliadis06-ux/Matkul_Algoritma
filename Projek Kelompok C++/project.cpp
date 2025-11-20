#include <iostream>
using namespace std;

int main() {
    int n, quantum;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    int burst[20], remaining[20], waiting[20], completion[20];
    cout << "Masukkan burst time tiap proses:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << ": ";
        cin >> burst[i];
        remaining[i] = burst[i];
    }

    cout << "Masukkan quantum time: ";
    cin >> quantum;

    int time = 0;
    bool done;
    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = false;
                if (remaining[i] > quantum) {
                    time += quantum;
                    remaining[i] -= quantum;
                } else {
                    time += remaining[i];
                    waiting[i] = time - burst[i]; // arrival diasumsikan 0
                    remaining[i] = 0;
                    completion[i] = time;
                }
            }
        }
    } while (!done);

    // Hitung rata-rata waiting time
    float totalWait = 0;
    cout << "\nHasil:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << " - Waiting Time: " << waiting[i] 
             << ", Completion: " << completion[i] << endl;
        totalWait += waiting[i];
    }
    cout << "Rata-rata Waiting Time = " << totalWait / n << endl;

    return 0;
}