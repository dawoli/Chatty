#include<bits/stdc++.h>
using namespace std;
int n,m,R,idx;
int sc[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>R;
	for(int i=1;i<n*m;i++)
	{
		cin>>sc[i];
	}	
	sort(sc+1,sc+(n*m),cmp);
	for(int i=1;i<n*m;i++)
	{
		if(R>sc[i])
		{
			idx=i;
			break;
		}
	}
	int mm=(idx%n==0?idx/n:idx/n+1),nn;
	if(mm%2==1)
	{
		nn=(idx%n==0?n:idx%n);
	}
	else
	{
		nn=n-idx%n+1;
	}
	cout<<mm<<" "<<nn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
