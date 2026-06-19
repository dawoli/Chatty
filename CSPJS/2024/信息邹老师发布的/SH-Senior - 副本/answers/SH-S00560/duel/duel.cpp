#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
//int q[100005];
int front=1,rear=1;

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++)
	//	cout<<a[i];
	while(rear<=n)
	{
		if(a[front]==a[rear])rear++;
		if(a[front]<a[rear])
		{
			front++;
			rear++;
		}
	}
	
	
	//cout<<rear<<endl;
	cout<<rear-front;
	
	return 0;
}
