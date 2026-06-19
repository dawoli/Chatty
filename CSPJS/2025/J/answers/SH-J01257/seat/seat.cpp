#include<bits/stdc++.h>
using namespace std;
int n,m;
int scr[110],trg,pl,ans1,ans2;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&scr[i]);
	trg=scr[1];
	sort(scr+1,scr+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(trg==scr[i])
		{
			pl=n*m-i+1;
			break;
		}
	}
	if(m!=0) ans1=(pl-1)/m+1;
	if(m!=0) pl%=m;
	if(pl==0) pl=m;
	if(ans1%2==1) ans2=pl;
	else ans2=n-pl+1;
	printf("%d %d",ans1,ans2);
	return 0;
}
