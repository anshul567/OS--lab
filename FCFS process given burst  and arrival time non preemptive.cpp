#include<iostream>
using namespace std;
    int n;
	void show(float x[])
	{
		for(int i=0;i<n;i++)
		{
			cout<<x[i]<<endl;
		}
	}
	void avg(float x[])
	{
		float c=0;
		for(int i=0;i<n;i++)
		{
		  c=c+x[i];
		}
		cout<<c/n<<endl;
	}
main()
{
	cout<<"Enter the no. of processes"<<endl;
	cin>>n;
	float WT[n],TAT[n],BT[n],CT[n],AT[n];
	
	//here WT=wating time,TAT=turn around time,BT=burst time of the process
	//AT=Arrival time,CT=completion time
	
	cout<<"Enter the Arrival time of processes"<<endl;
	for(int i=0;i<n;i++)
	cin>>AT[i];
	cout<<"Enter the Burst time of processes"<<endl;
	for(int i=0;i<n;i++)
	cin>>BT[i];
	CT[0]=BT[0];
	for(int i=1;i<n;i++)
	CT[i]=CT[i-1]+BT[i];
	for(int i=0;i<n;i++)
	TAT[i]=CT[i]-AT[i];
	for(int i=0;i<n;i++)
	WT[i]=TAT[i]-BT[i];
	cout<<".....Completion Time....."<<endl;
	show(CT);
	cout<<"....Turn Around Time...."<<endl;	
	show(TAT);
	cout<<"......Waiting Time......"<<endl;
	show(WT);
	cout<<"Average Completion Time = ";
	avg(CT);
	cout<<"Average Waiting Time = ";
	avg(WT);
	cout<<"Average Turn Around Time = ";
	avg(TAT);
}
