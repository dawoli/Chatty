#include<iostream>
#include<ctime>
#include<iomanip>
#include<cstdio>
#include<fstream> 
using namespace std;
int main()
{
	freopen("duel4.in","r",stdin);
	freopen("duel.out","w",stdout);
	srand(time(0));
	int n;
	cin>>n;
	int a[100001]={0};
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		a[temp]++; 
	}
	int b[100001]={0};
	int btop=0;
	for(int i=1;i<=100000;i++)
	{
		if(a[i]!=0)b[++btop]=i;
	}
	for(int i=2;i<=btop;i++)
	{
		if(a[b[i]]>=a[b[i-1]])n-=a[b[i-1]];
		else
		{
			n-=a[b[i]];
			a[b[i]]+=a[b[i-1]]; 
		}
	}
	cout<<n<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
