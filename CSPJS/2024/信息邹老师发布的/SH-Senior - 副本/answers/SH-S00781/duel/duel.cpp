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

int const N = 1e5 + 10;
int r[N];
int sum[N], idx;
int n;
int last = 0,ans = 0;

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);

//  样例全过 
//  O(nlogn + n + n) sum前缀和可以离散化一下 
    read(n);
    ans = n;
    for(int i = 1;i <= n;i ++)
    {
        read(r[i]);
        if(sum[r[i]] == 0) idx++;
        sum[r[i]]++;
    }

    sort(r + 1, r + 1 + n); //nlogn

    for(int i = 1;i <= r[n];i++) sum[i] += sum[i - 1];

    last = sum[r[1]];

    for(int i = sum[r[1]] + 1;i <= n;)
    {
        int now = sum[r[i]] - sum[r[i - 1]];
        if(now >= last)
        {
            ans -= last;
			last = now;
        }
        else if(now < last)
        {
            ans -= now;
        }
        i += now;
    }

    printf("%d\n", ans);
    return 0;
}
