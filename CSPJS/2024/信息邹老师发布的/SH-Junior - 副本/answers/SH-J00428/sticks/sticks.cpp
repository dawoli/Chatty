#include<cstdio>
using namespace std;
const long long Inf=1e9+9;
const long long Mod=1e9+7,Mod2=998244353;
typedef long long ll;

ll n;

inline void solve()
{
	scanf("%lld",&n);
	switch(n%7)
	{
		case 0:
			for(int i=1;i<=n/7;i++)
				printf("8");
			printf("\n");
			break;
		case 1:
			if(n==1)
			{
				printf("-1\n");
				return;
			}
			printf("10");
			for(int i=1;i<=(n-8)/7;i++)
				printf("8");
			printf("\n");
			break;
		case 2:
			printf("1");
			for(int i=1;i<=(n-2)/7;i++)
				printf("8");
			printf("\n");
			break;
		case 3:
			if(n==3)
			{
				printf("7\n");
				return;
			}
			if(n==10)
			{
				printf("23\n");
				return;
			}
			printf("200");
			for(int i=1;i<=(n-17)/7;i++)
				printf("8");
			printf("\n");
			break;
		case 4:
			if(n==4)
			{
				printf("4\n");
				return;
			}
			printf("20");
			for(int i=1;i<=(n-11)/7;i++)
				printf("8");
			printf("\n");
			break;
		case 5:
			printf("2");
			for(int i=1;i<=(n-5)/7;i++)
				printf("8");
			printf("\n");
			break;
		case 6:
			printf("6");
			for(int i=1;i<=(n-6)/7;i++)
				printf("8");
			printf("\n");
			break;
	}
	return;
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)
		solve();
	return 0;
}

