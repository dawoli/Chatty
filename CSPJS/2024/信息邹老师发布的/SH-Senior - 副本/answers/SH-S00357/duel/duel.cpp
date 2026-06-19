#include<bits/stdc++.h>
using namespace std;
const int MAX=100001;
int r[MAX];
int n,ans=0;
queue<int> qu;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
	}
	sort(r,r+n);
	for(int i=0;i<n;i++)
	{
		qu.push(r[i]);
		if(qu.front()<qu.back())
		{
			qu.pop();
		}
	}
	while(!qu.empty())
	{
		ans++;
		qu.pop();
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
