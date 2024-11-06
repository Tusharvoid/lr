#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

struct Process {
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int arrival_time;
};

void roundRobinScheduling(vector<Process>& processes, int time_quantum) {
    int time = 0;
    queue<Process*> ready_queue;
    vector<int> completion_order;

    for (auto& process : processes) {
        ready_queue.push(&process);
        process.remaining_time = process.burst_time;
    }

    while (!ready_queue.empty()) {
        Process* current_process = ready_queue.front();
        ready_queue.pop();

        if (current_process->remaining_time > 0) {
            if (current_process->remaining_time <= time_quantum) {
                time += current_process->remaining_time;
                current_process->remaining_time = 0;
                current_process->turnaround_time = time;
                completion_order.push_back(current_process->id);
            } else {
                time += time_quantum;
                current_process->remaining_time -= time_quantum;
                ready_queue.push(current_process);
            }
        }
    }

    for (auto& process : processes) {
        process.waiting_time = process.turnaround_time - process.burst_time;
    }

    cout << "\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (const auto& process : processes) {
        cout << setw(10) << process.id << "\t" << setw(9) << process.burst_time << "\t"
             << setw(12) << process.waiting_time << "\t" << setw(15) << process.turnaround_time << "\n";
    }

    float total_waiting_time = 0, total_turnaround_time = 0;
    for (const auto& process : processes) {
        total_waiting_time += process.waiting_time;
        total_turnaround_time += process.turnaround_time;
    }

    cout << "\nAverage Waiting Time: " << total_waiting_time / processes.size() << endl;
    cout << "Average Turnaround Time: " << total_turnaround_time / processes.size() << endl;
}

int main() {
    int n, time_quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> time_quantum;

    vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        processes[i].arrival_time = 0;
        cout << "Enter burst time for Process " << processes[i].id << ": ";
        cin >> processes[i].burst_time;
    }

    roundRobinScheduling(processes, time_quantum);

    return 0;
}
//Burst times: 5, 5, 5, 5
//Quantum time: 2