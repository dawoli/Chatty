#include <iostream>
#include <string>
//password:GL@17SXYZ
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    bool pd[20]={false},pc[20]={false},ph[20]={false},ps[20]={false};
    int n,num,tot=0;
    string poker;
    cin>>n;
    for(int i=1;i<=n;i++)
	{
	   cin>>poker;
	    if(poker[1]=='A')
	   		num=1;
		else if(poker[1]=='T')
			num=10;
		else if(poker[1]=='J')
			num=11;
		else if(poker[1]=='Q')
			num=12;
		else if(poker[1]=='K')
			num=13;
		else
		{
			num=poker[1]-'0';
		}
		if(poker[0]=='D'){
		
			if(!pd[num])
			{
				tot++;
				pd[num]=true;
			}
		}
		if(poker[0]=='C')
		{
			if(!pc[num]){
			
				tot++;
				pc[num]=true;
			}
		}
		if(poker[0]=='H')
		{
			if(!ph[num])
			{
				tot++;
				ph[num]=true;
			}
		}
		if(poker[0]=='S')
		{
			if(!ps[num])
			{
				tot++;
				ps[num]=true;
			}
		}
	}
	cout<<52-tot;
	
	
}
