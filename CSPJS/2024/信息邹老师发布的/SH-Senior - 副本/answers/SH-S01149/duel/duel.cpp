#include <bits/stdc++.h>
using namespace std;
struct Node{
	int atk,num;
}b[100001]; 
int n,idx,cnt;  
int a[100001];
int main()
{
	ios::sync_with_stdio(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[idx].atk)
		{
			idx++;
			b[idx].atk=a[i];
			b[idx].num++;
		}
		else b[idx].num++;
	}
	for(int i=2;i<=idx;i++)
	{
		if(b[i].num<=b[i-1].num)
		{
			 cnt+=(b[i-1].num-b[i].num);
			 n-=b[i].num;
		}
		else
		{
			n-=(b[i-1].num+min(cnt,b[i].num-b[i-1].num));
			cnt-=min(cnt,b[i].num-b[i-1].num);
		}
		 
	}
	cout<<n;
	return 0;
}
