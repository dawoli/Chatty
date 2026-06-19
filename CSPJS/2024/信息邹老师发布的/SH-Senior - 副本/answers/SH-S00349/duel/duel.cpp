#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int a[N];
bool f[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,left;
	cin>>n;
	left=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	queue<int> q;
	q.push(1);
	for(int i=2;i<=n;i++)
	{
		q.push(i);
		if(a[i]>a[q.front()])
		{
			q.pop();
			left--;
		}
	}
	cout<<left;
	return 0;
}
