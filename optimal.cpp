#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int frame_size;
vector<int> pages;

void optimal_page_replacement() {
    vector<int> frame;
    int page_faults = 0;
    int hits = 0;

    for (int i = 0; i < n; i++) {
        int current_page = pages[i];

        if (find(frame.begin(), frame.end(), current_page) != frame.end()) {
            hits++;
        } else {
            page_faults++;

            if (frame.size() < frame_size) {
                frame.push_back(current_page);
            } else {
                int farthest = -1;
                int index_to_replace = -1;
                
                for (int j = 0; j < frame.size(); j++) {
                    int next_use = -1;

                    for (int k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k]) {
                            next_use = k;
                            break;
                        }
                    }

                    if (next_use == -1) {
                        index_to_replace = j;
                        break;
                    }

                    if (next_use > farthest) {
                        farthest = next_use;
                        index_to_replace = j;
                    }
                }
                frame[index_to_replace] = current_page;
            }
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
    pages.resize(n);
    cout << "Enter Page References:\n";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    
    optimal_page_replacement();
    return 0;
}
//7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1