#include <iostream>
#include <queue>
using namespace std;

const int N = 100005; // Maximum number of pages
int n; // Number of pages
int frame_size; // Number of frames
int pages[N]; // Array to hold the page references
bool mark[N] = {false}; // Array to mark page presence in frames

void fifo_page_replacement() {
    queue<int> Q; // Queue to hold pages in memory
    int page_faults = 0; // Count of page faults
    int hits = 0; // Count of hits

    for (int i = 0; i < n; i++) {
        if (mark[pages[i]]) {
            hits++; // Page hit
        } else {
            if (Q.size() >= frame_size) {
                int p = Q.front(); // Get the oldest page
                mark[p] = false; // Mark it as not present
                Q.pop(); // Remove it from the queue
            }
            Q.push(pages[i]); // Add the new page
            mark[pages[i]] = true; // Mark the new page as present
            page_faults++; // Count the page fault
        }
    }

    // Output results
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
        cin >> pages[i]; // Input pages
    }
    
    fifo_page_replacement(); // Call the FIFO page replacement function
    return 0;
}