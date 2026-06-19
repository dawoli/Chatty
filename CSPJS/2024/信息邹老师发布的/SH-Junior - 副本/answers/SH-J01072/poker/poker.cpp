#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","w",stdin);
	freopen("poker.out","r",stdout);
	bool power[5][15]={};
	char k=0,n=0;
	int a=0,tk=0,tn=0,s=52;
	scanf("%d",&a);
	for(int i=0;i<=a;i++)
	{
		scanf("%c%c",&k,&n);
		if(k=='D')
			tk=0;
		else if(k=='C')
			tk=1;
		else if(k=='H')
			tk=2;
		else
			tk=3;
		if('2'<=n&&n<='9')
			tn=n-'0';
		else if(n=='A')
			tn=1;
		else if(n=='T')
			tn=10;
		else if(n=='J')
			tn=11;
		else if(n=='Q')
			tn=12;
		else
			tn=13;
		power[tk][tn]=true;
	}
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			if(power[i][j])
				s--;
	printf("%d",52-a);
	return 0;
}
