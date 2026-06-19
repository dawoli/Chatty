#include <bits/stdc++.h>
using namespace std;
int car[100000][3],a,b,L,limv,o,T,c[100000],k,i,j,p,all;
int main()
{
	freopen(detect.in,"r",stdin);
	freopen(detect.out,"w",stdout);
	cin>>T;
	for(o=1;o<=T;o++)
	{
		k=0;
		p=0;
		memset(c,0,sizeof(c));
		memset(car,0,sizeof(car));
		cin>>a,b,L,limv;
		for(i=1;i<=a;i++)
		{
			for(j=1;j<=3;j++)
			cin>>car[i][j];
		}
		for(i=1;i<=b;i++)
		{
			cin>>c[i];
			if(k>c[i]) k=c[i];
			if(p<c[i]) p=c[i];
		}
		for(i=1;i<=a;i++)
		{
			if(car[i][1]>k&&car[i][1]<p)
			  if(car[i][2]>limv) all++;
		}
		cout<<all<<" "<<b-1<<endl;	
	}
	return 0;
}
