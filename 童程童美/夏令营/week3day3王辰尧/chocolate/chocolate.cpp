#include<iostream>
using namespace std;
int main()
{
	freopen("chocolate.in","r",stdin);
	freopen("chocolate.out","w",stdout);
	int m,n,i=0;
	cin>>m>>n;
	if(m>n)swap(m,n);
	if(m==2){cout<<2;return 0;}
	while(m)
	{
		if((m-2)>=0){i+=4;m-=2;}
		if(i==4){i--;}
		if((m-2)==-1){i+=2;m-=1;}
	}
	cout<<i;
	return 0;
}
