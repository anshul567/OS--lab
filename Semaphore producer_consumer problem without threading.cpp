#include<iostream>
using namespace std;
int S=1,E=5,F=0;
class PC
{
	public:

	void producer();
	void consumer();
	int Wait(int);
	int Signal(int);
};
int PC::Wait(int S)
{
	return (--S);
}
int PC::Signal(int S)
{
	return (++S);
}
void PC::producer()
{
	
		E=Wait(E);
		S=Wait(S);
		S=Signal(S);
		F=Signal(F);
		cout<<"S= "<<S<<"\tE="<<E<<"\tF= "<<F<<endl;
}
void PC::consumer()
{
	F=Wait(F);
	S=Wait(S);

	S=Signal(S);
	E=Signal(E);
			cout<<"S= "<<S<<"\tE="<<E<<"\tF= "<<F<<endl;
}
main()
{
	PC ob;
	int ch;
	while(1)
	{
		cout<<"1. for Producer"<<endl;		
		cout<<"2. for Consumer"<<endl;
		cout<<"Press 3 to Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: if(S==1&&E!=0)
			        {
			        	ob.producer();
					}
					else
					{
						cout<<"Buffer is full"<<endl;
					}
					break;
			case 2: if(S==1&&F!=0)	
			        {
			        	ob.consumer();
 				    }
 				    else
 				    {
 				    	cout<<"Buffer empty"<<endl;
					}
					break;
			case 3: exit(0);
			        break;
			default:
			      cout<<"Invalid output"<<endl;		
		}
		
	}
}
