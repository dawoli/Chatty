#include<bits/stdc++.h>
using namespace std;
int A[21],B[21];
struct car{
	int d,v,a;
};
car che[100010];
void chaosu(int n,int m,int L,int V,int hao)
{
	int road[L]={0},moniter[m]={0},ans=0;
	bool moniterflag[m]={0};
	for(int i=0;i<n;i++)
	{
		cin>>che[i].d>>che[i].v>>che[i].a;
	}
	for(int i=0;i<m;i++)
	{
		cin>>moniter[i];
	}
	sort(moniter,moniter+m);
	float chao[n];
	for(int i=0;i<n;i++)
	{
		if(che[i].a!=0)
		{
			chao[i]=che[i].d+(V*V-che[i].v*che[i].v)/(2*che[i].a);
		}
		else
		{
			if(che[i].v<=V)
			{
				chao[i]=L+1;
			}
			else
			{
				chao[i]=che[i].d;
			}
		}
		if(chao[i]<moniter[m-1])
		{
			A[hao]++;
			moniterflag[m-1]=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!moniterflag[i])
		{
			B[hao]++;
		}
	}
	B[hao]=m-B[hao];
}

int main()
{
	//freopen("detect.in","r",stdin);
	//freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		chaosu(n,m,L,V,i);
	}
	for(int i=0;i<T;i++)
	{
		cout<<A[i]<<" "<<B[i]<<endl;
	}
	return 0;
}
