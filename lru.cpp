#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <climits>
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
                pagefaults++;
            }
        }
        
        indexes[page] = i;
    }

    int totalRequests = pages.size();
    double pageFaultRatio = static_cast<double>(pagefaults) / totalRequests;
    double pageHitRatio = static_cast<double>(pagehits) / totalRequests;

    cout << "The number of Page Faults are: " << pagefaults << "\n";
    cout << "The number of Hits are: " << pagehits << "\n";
    cout << "Page Fault Ratio: " << pageFaultRatio << "\n";
    cout << "Page Hit Ratio: " << pageHitRatio << "\n";

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

//7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1