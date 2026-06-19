#include<iostream>
#include<vector>
using namespace std;
const int Maxn=10001;
const int Inf=1000000001;
struct Road
{
	int P1,P2,P;
};
int N,M,K,A[Maxn][Maxn],C[11][Maxn];
long long Ans;
vector<Road> Choose;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=0;i<Maxn;i++) for(int j=0;j<Maxn;j++) A[i][j]=Inf;
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0;i<M;i++)
	{
		int U,V,W;
		scanf("%d %d %d",&U,&V,&W);
		A[U][V]=W;
		A[V][U]=W;
	}
	for(int i=0;i<K;i++)
	{
		int Loc;
		scanf("%d",&C[i][0]);
		for(int j=1;j<=N;j++) 
		{
			scanf("%d",&C[i][j]);
			if(C[i][j]==0) Loc=j;
		}
		for(int j=1;j<=N;j++)
		{
			A[Loc][j]=min(A[Loc][j],C[i][j]);
			A[j][Loc]=A[Loc][j];
		} 
	}
	for(int i=2;i<=N;i++)
	{
		Road G;
		long long Minn=Ans+Inf;
		for(int j=1;j<i;j++) 
		{
			if(Ans+A[i][j]<Minn)
			{
				Minn=Ans+A[i][j];
				G.P1=i;
				G.P2=j;
				G.P=A[i][j];
			}
		}
		Ans=Minn;
	}
	cout<<Ans<<"\n";
	return 0;
}
