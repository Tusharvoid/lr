#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; // Number of pages
int frame_size; // Number of frames
vector<int> pages; // Vector to hold the page references

void optimal_page_replacement() {
    vector<int> frame; // Vector to hold the current pages in frames
    int page_faults = 0; // Count of page faults
    int hits = 0; // Count of hits

    for (int i = 0; i < n; i++) {
        int current_page = pages[i];

        // Check if the page is already in the frame
        if (find(frame.begin(), frame.end(), current_page) != frame.end()) {
            hits++; // Page hit
        } else {
            page_faults++; // Page fault occurs

            // If the frame is not full, add the new page
            if (frame.size() < frame_size) {
                frame.push_back(current_page);
            } else {
                // Find the page to replace
                int farthest = -1;
                int index_to_replace = -1;
                
                for (int j = 0; j < frame.size(); j++) {
                    int next_use = -1;

                    // Find when this frame will be used again
                    for (int k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k]) {
                            next_use = k;
                            break;
                        }
                    }

                    // If the page is not found in future references, it is a candidate for replacement
                    if (next_use == -1) {
                        index_to_replace = j;
                        break;
                    }

                    // Update farthest if this page will be used later
                    if (next_use > farthest) {
                        farthest = next_use;
                        index_to_replace = j;
                    }
                }
                // Replace the page
                frame[index_to_replace] = current_page;
            }
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
    pages.resize(n); // Resize the pages vector to hold n elements
    cout << "Enter Page References:\n";
    for (int i = 0; i < n; i++) {
        cin >> pages[i]; // Input pages
    }
    
    optimal_page_replacement(); // Call the optimal page replacement function
    return 0;
}