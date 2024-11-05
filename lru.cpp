#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include<climits>
using namespace std;

int pageFaults(const vector<int>& pages, int capacity) {
    unordered_set<int> memory;
    unordered_map<int, int> indexes;
    int pagefaults = 0;
    int pagehits = 0;

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];

        if (memory.find(page) != memory.end()) {
            pagehits++;
            cout << "Page " << page << " page hit. Memory: ";
        } else {
            if (memory.size() < capacity) {
                memory.insert(page);
            } else {
                int lru_page = -1, min_index = INT_MAX;
                for (int p : memory) {
                    if (indexes[p] < min_index) {
                        min_index = indexes[p];
                        lru_page = p;
                    }
                }
                memory.erase(lru_page);
                memory.insert(page);
                cout << "Page " << lru_page << " replaced by " << page << ". Memory: ";
                pagefaults++;
            }
        }
        
        indexes[page] = i;

        for (int p : memory) {
            cout << p << " ";
        }
        cout << endl;
    }

    cout << "The number of Page Faults are: " << pagefaults << "\n";
    cout << "The number of Hits are: " << pagehits << "\n";
    return pagefaults;
}

int main() {
    int capacity, numPages;

    cout << "Enter the number of frames: ";
    cin >> capacity;

    cout << "Enter the number of pages in the reference string: ";
    cin >> numPages;

    vector<int> pages(numPages);

    cout << "Enter the page reference string: ";
    for (int i = 0; i < numPages; i++) {
        cin >> pages[i];
    }

    pageFaults(pages, capacity);

    return 0;
}