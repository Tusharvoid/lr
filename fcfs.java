import java.util.*;
public class fcfs{

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of process: ");
		int process = sc.nextInt();
		int processId[] = new int[process];
		int burstTime[] = new int[process]; 
		int arrivalTime[] = new int[process];
		int completionTime[] = new int[process];
		int turnarroundTime[] = new int[process];
		int waitingTime[] = new int[process];
		int currentTime=0;
		
		
		for(int i=0; i<process ; i++){
			processId[i] = i+1;
			System.out.println("Enter Burst time for process for " + (i+1));
			burstTime[i] = sc.nextInt();
			arrivalTime[i] = i;
			completionTime[i] = currentTime+burstTime[i];
			turnarroundTime[i] = completionTime[i] - arrivalTime[i];
			waitingTime[i] = turnarroundTime[i] - burstTime[i];
			currentTime+= burstTime[i];
		}
		
		int sum_TAT = 0;
		int sum_WT=0;
		for(int i=0 ; i<process; i++){
			sum_TAT += turnarroundTime[i];
			sum_WT += waitingTime[i];
		}
		
		System.out.println("processId"+ "    "+ "burst Time"+"   "+"Arrival Time"+"    "+"Turn arround time"+"   "+ "Waiting time" +"   " );
		for(int i=0; i<process ; i++){
			System.out.println(processId[i]+ "    "+ burstTime[i]+"   "+arrivalTime[i]+"    "+turnarroundTime[i]+"   "+ waitingTime[i] +"   " );
		}
		System.out.println("Avg TAT = "+ (sum_TAT/process));
		System.out.println("Avg WT = "+ (sum_WT/process));
		sc.close();
	} 

}
