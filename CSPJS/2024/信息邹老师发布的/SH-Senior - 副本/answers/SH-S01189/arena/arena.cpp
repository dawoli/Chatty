#include<iostream>
using namespace std;
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a1[100001]={0};
	int a2=[100001]={0};
	int c[100001]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i];
	}
	for(int i=1;i<=m;i++)cin>>c[i];
	for(int i=1;i<=m;i++)
	{
		int result=0;
		int temp[5];
		cin>>temp[0]>>temp[1]>>temp[2]>>temp[3];
		for(int j=1;j<=n;j++)
		{
			cin>>a2[j];
			result=result^j*a1[j]^temp[j%4];	
		} 
		cout<<result<<endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
