import java.util.Scanner;

public class sjf {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter number of processes: ");
        int n = s.nextInt();

        int[] pid = new int[n]; 
        int[] bt = new int[n];  
        int[] at = new int[n];  
        int[] ct = new int[n];  
        int[] tat = new int[n]; 
        int[] wt = new int[n];  
        boolean[] completed = new boolean[n]; 

        
        for (int i = 0; i < n; i++) {
            System.out.print("Enter process ID for process " + (i + 1) + ": ");
            pid[i] = s.nextInt();
            System.out.print("Enter burst time for process " + (i + 1) + ": ");
            bt[i] = s.nextInt();
            System.out.print("Enter arrival time for process " + (i + 1) + ": ");
            at[i] = s.nextInt();
        }

        int currentTime = 0;
        int completedProcesses = 0;

        while (completedProcesses < n) {
            int shortestJobIndex = -1;
            int minBurstTime = Integer.MAX_VALUE;

            
            for (int i = 0; i < n; i++) {
                if (at[i] <= currentTime && !completed[i] && bt[i] < minBurstTime) {
                    minBurstTime = bt[i];
                    shortestJobIndex = i;
                }
            }

            if (shortestJobIndex == -1) { 
                currentTime++;
            } else {
                
                currentTime += bt[shortestJobIndex];
                ct[shortestJobIndex] = currentTime;
                tat[shortestJobIndex] = ct[shortestJobIndex] - at[shortestJobIndex];
                wt[shortestJobIndex] = tat[shortestJobIndex] - bt[shortestJobIndex];
                completed[shortestJobIndex] = true;
                completedProcesses++;
            }
        }

        // Display results
        System.out.println("\nProcess ID\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time");
        for (int i = 0; i < n; i++) {
            System.out.println(pid[i] + "\t\t" + bt[i] + "\t\t" + at[i] + "\t\t" + ct[i] + "\t\t" + tat[i] + "\t\t" + wt[i]);
        }
    }
}
//tat=ct-at
//wt=tat-bt
//burst time  less will come first 
//3,4 4,2 2,1 4,4 