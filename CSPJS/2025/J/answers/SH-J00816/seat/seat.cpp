#include<bits/stdc++.h>
using namespace std;
int n,m,an,a1,cnt=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a1);
	for(int i=1;i<n*m;i++)
	{
		cin>>an;
		if(an>a1) cnt++;
	}
	int n1=cnt/n;
	cnt=cnt-n*n1+1;
	printf("%d %d",n1+1,cnt);
	return 0;
 } 
