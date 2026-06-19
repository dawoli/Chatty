#include<iostream>
#include<queue>
using namespace std;
const int maxn=100001;
int T,N,A[maxn][4],Num[4];
long long Ans[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	for(int X=0;X<T;X++)
	{
		priority_queue<int> Q[4];
		for(int i=0;i<3;i++) Num[i]=0;
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d %d %d",&A[i][0],&A[i][1],&A[i][2]);
			int maxx=max(max(A[i][0],A[i][1]),A[i][2]);
			Ans[X]+=maxx;
			for(int j=0;j<3;j++)
			{
				if(A[i][j]==maxx)
				{
					Num[j]++;
					int g=-20000;
					for(int k=0;k<3;k++) if(j!=k) g=max(g,A[i][k]-A[i][j]);
					Q[j].push(g);
					break;
				}
			}
		}
		for(int i=0;i<3;i++)
		{
			if(Num[i]>N/2)
			{
				while(Num[i]>N/2)
				{
					Ans[X]+=Q[i].top();
					Q[i].pop();
					Num[i]--;
				}
			}
		}
	}
	for(int i=0;i<T;i++) cout<<Ans[i]<<"\n";
	return 0;
}
