#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int n,r[100010];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&r[i]);
	sort(r+1,r+n+1);
	for(int i=n;i>=1;--i) s.push(r[i]);
	int ans=n,top=1;
	for(int i=1;i<=n;++i)
	    if(r[i]>r[top])
	    {
	    	ans--;
			s.pop();
			top=2; 
		}
	printf("%d",ans);
	return 0;
}
