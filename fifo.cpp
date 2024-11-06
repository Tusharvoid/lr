#include <iostream>
#include <queue>
using namespace std;

const int N = 100005;
int n;
int frame_size;
int pages[N];
bool mark[N] = {false};

void fifo_page_replacement() {
    queue<int> Q;
    int page_faults = 0;
    int hits = 0;

    for (int i = 0; i < n; i++) {
        if (mark[pages[i]]) {
            hits++;
        } else {
            if (Q.size() >= frame_size) {
                int p = Q.front();
                mark[p] = false;
                Q.pop();
            }
            Q.push(pages[i]);
            mark[pages[i]] = true;
            page_faults++;
        }
    }

    cout << "\nTotal Page Faults: " << page_faults << "\n";
    cout << "Total Page Hits: " << hits << "\n";
    float hit_ratio = (static_cast<float>(hits) / n) * 100;
    float fault_ratio = (static_cast<float>(page_faults) / n) * 100;
    cout << "Page Fault Ratio: " << fault_ratio << "%\n";
    cout << "Page Hit Ratio: " << hit_ratio << "%\n";
}

int main() {
    cout << "Enter Number of Frames: ";
    cin >> frame_size;
    cout << "Enter Page String Length: ";
    cin >> n;
    cout << "Enter Page References:\n";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    
    fifo_page_replacement();
    return 0;
}
//7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1