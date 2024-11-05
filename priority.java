import java.lang.*;
import java.util.*;
public class priority{
public static void main(String[] args){
	Scanner s=new Scanner(System.in);
	System.out.print("enter number of processes");
	int n=s.nextInt();
	int pid[]=new int[n];
	int bt[]=new int[n];
	int at[]=new int[n];
	int pn[]=new int[n];
	int twt[]=new int[n];
	for(int i=0;i<n;i++){
		System.out.print("enter the process number"+i+":");
		pid[i]=s.nextInt();
		System.out.print("enter the burst time for number"+  i +":");
		bt[i]=s.nextInt();
		System.out.print("enter the arrival number"+ i+":");
		at[i]=s.nextInt();
		System.out.print("enter the priority number"+ i+":");
		pn[i]=s.nextInt();
	}
	
for(int i=0;i<n-1;i++){
	for(int j=0;j<n-1;j++){
	if(pn[j]>pn[j+1]){
		int temp=pid[j];
			pid[j+1]=pid[j];
			pid[j+1]=temp;
			
			bt[j+1]=bt[j];
			bt[j+1]=temp;
			
			at[j+1]=at[j];
			at[j+1]=temp;
			
			pn[j+1]=pn[j];
			pn[j+1]=temp;
	}
	}
}
System.out.println("PID\tBT\tAT\tPN");
for(int i=0;i<n;i++){
System.out.println(pid[i]+"\t"+bt[i]+"\t"+at[i]+"\t"+pn[i]);
}
s.close();
} 
} 
