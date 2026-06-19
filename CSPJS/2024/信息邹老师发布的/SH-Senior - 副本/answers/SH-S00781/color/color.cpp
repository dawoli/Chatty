#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

template<typename T>
void read(T& x)
{
	T n = 0;
	int f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		n = n * 10 + ch - '0';
		ch = getchar();
	}
	x = n * f;
}

const int N = 2e5 + 10;


int ner, neb;
int T, n;
int64_t dp[N][2];
int64_t a[N]; 
int64_t ans;




int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);

	read(T);
	while(T--)
    {
        read(n);
        for(int i = 1;i <= n;i++) read(a[i]);
        neb = a[1], ner = 0;
        memset(dp, 0, n * sizeof(int64_t));
        //1 -> blue 0 -> red
        for(int i = 2;i <= n;i++)
        {
        	if(a[i] == neb or a[i] == ner)printf("a\n");
            dp[i][1] = max(dp[i - 1][1],dp[i - 1][0]) + (a[i] == neb?a[i]:0 );
            dp[i][0] = max(dp[i - 1][1],dp[i - 1][0]) + (a[i] == ner?a[i]:0 );
            if(dp[i][1] > dp[i][0])
            {
                neb = a[i];
            }else{
                ner = a[i];
            }
        }

        printf("%lld\n",max(dp[n][1], dp[n][0]));
    }

    return 0; 

}
