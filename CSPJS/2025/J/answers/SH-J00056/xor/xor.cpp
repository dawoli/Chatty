#include<bits/stdc++.h>
using namespace std;
int a[500005];
struct Node
{
	int st,ed;
}gs_a[500005];
bool px(Node x,Node y)
{
	if(x.st==y.st)
	{
		return x.ed<y.ed;
	}
	return x.st<y.st;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int li_i=1;li_i<=n;li_i++)
	{
		cin>>a[li_i];
	}
	int li_cnt=0;
	for(int li_i=1;li_i<=n;li_i++)
	{
		for(int li_j=0;li_j<=n-li_i;li_j++)
		{
			int li_ans=a[li_i];
			for(int li_k=li_i+1;li_k<=li_i+li_j;li_k++)
			{
				li_ans=li_ans^a[li_k];
			}
			if(li_ans==k)
			{
				li_cnt++;
				li_i=li_i+li_j;
				break;
			}
		}
	}
	cout<<li_cnt;
	return 0;
}
