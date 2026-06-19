#include<bits/stdc++.h>
using namespace std;

int T,n,i,j,flag,t0,t1,tmp,res,A[300000],book[300000];
void dfs(int s,int v)
{
	if(s == n)
	{
		res = max(res,v);
		return;
	}
	int f = 1,i,t = 0;
	book[s] = 1;
	for(int i = s-1;i >= 0;i--)
	{
		if(book[i] == 1)
		{
			t = A[s] == A[i]?A[s]:0;
			break;
		}
	}
	dfs(s+1,v+t);
	book[s] = -1;
	for(int i = s-1;i >= 0;i--)
	{
		if(book[i] == -1)
		{
			t = A[s] == A[i]?A[s]:0;
			break;
		}
	}
	dfs(s+1,v+t);
	return;
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		res = 0;
		for(i = 0;i < n;i++)cin>>A[i];
		dfs(0,0);
		cout<<res;
		if(T != 0)cout<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
