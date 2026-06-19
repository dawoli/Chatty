#include<bits/stdc++.h>
using namespace std;

int N;
long long h0, h1, h2;
struct _subt
{
	int pos;
	long long diff;
}subt[3][100005];
int lenSubt[3];
int amWishes[3];
int T;

long long maxHPN;

bool cmp(_subt a, _subt b)
{
	return a.diff >= b.diff;
} 

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		amWishes[0]=0, amWishes[1]=0, amWishes[2]=0;
		lenSubt[0]=0, lenSubt[1]=0, lenSubt[2]=0;
		maxHPN = 0;
		cin>>N;
		for(int i=0;i<N;i++)
		{
			cin>>h0>>h1>>h2;
			if(h0>=h1&&h0>=h2)
			{
				subt[0][lenSubt[0]++]={i, h0 - max(h1,h2)};
				amWishes[0]++;
				maxHPN += h0;
			}
			else if(h1>=h0&&h1>=h2)
			{
				subt[1][lenSubt[1]++]={i, h1 - max(h0,h2)};
				amWishes[1]++;
				maxHPN += h1;
			}
			else
			{
				subt[2][lenSubt[2]++]={i, h2 - max(h0,h1)};
				amWishes[2]++;
				maxHPN += h2;
			}
		}
		for(int i=0;i<3;i++)
		{
			if(amWishes[i]<=N/2) continue;
			sort(subt[i],subt[i]+lenSubt[i],cmp);
			for(int j=N/2;j<lenSubt[i];j++) maxHPN -= subt[i][j].diff;
		}
		cout<<maxHPN<<endl;
	}
	return 0;
}
