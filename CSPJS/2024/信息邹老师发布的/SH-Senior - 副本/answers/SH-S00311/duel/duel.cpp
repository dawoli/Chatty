//100
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int n,a[N],cnt;
priority_queue<int,vector<int>,greater<int> > q1,q2;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		q1.push(a[i]);//de
		q2.push(a[i]);//at
	}
	cnt=n;
//	sort(a+1,a+n+1);
	for(int i=1;i<=2*n;i++)
	{
		if(q1.empty()||q2.empty()) break;
		if(q1.top()>=q2.top())
		{
			q2.pop();
			continue;
		}
		q1.pop(); q2.pop(); cnt--;
	}
	printf("%d",cnt);
	return 0;
}

