#include<bits/stdc++.h>
using namespace std;
int score[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int N,M,i,x=1,y=1,a1;
	scanf("%d %d",&N,&M);
	for(i=1;i<=N*M;++i)
		scanf("%d",&score[i]);
	a1=score[1];
	sort(score+1,score+1+N*M,greater<int>());
	for(i=1;i<=N*M;)
	{
		while(y<=M&&score[i]!=a1)
			i++,y++;
		if(y==M+1)
			y=M,i--;
		if(score[i]==a1)
		{
			printf("%d %d",x,y);
			return 0;
		}
		x++,i++;
		if(score[i]==a1)
		{
			printf("%d %d",x,y);
			return 0;
		}
		while(y>=1&&score[i]!=a1)
			i++,y--;
		if(y==0)
			y=1,i--;
		if(score[i]==a1)
		{
			printf("%d %d",x,y);
			return 0;
		}
		x++,i++;
		if(score[i]==a1)
		{
			printf("%d %d",x,y);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
