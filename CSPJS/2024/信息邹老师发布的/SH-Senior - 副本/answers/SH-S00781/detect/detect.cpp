#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<stdint.h>
#include<cmath>

/*
15:32 upd 又是区间？

16:26 upd st表好像能行
单点修改， 区间查询， 这是树状数组

16:36 upd 从0到pmax扫一遍就行了

a < 0 视为往南边加速
a = 0 即答案不为0 （真的有这种情况吗
a > 0 视为往北边加速

vi 全部大于0 即a < 0的车 若vi不大于V则不会超速
                        ！！！ a < 0的不会返回， v = 0直接离开了

1. 对于每辆车有一个点， 这个点向右的即为超速区间 （a >= 0)适用
2. 对于每辆车有一个点， 初始位置到这个点的为超速区间 (a < 0 , vi > V)适用

测不到的直接丢掉

1好做 对于1 区间取交（端点取最大的） 从北向南找 第一个在区间里的 测速仪留着， 其他全关
2好做（吗？） 等会再说， 60pts也是分


不用longlong好诶
*/

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
template<typename T, typename... Args>
void read(T &x, Args & ... args)
{
    read<T>(x);
    read(args...);
}

const int N =  1e5 + 10;
const int MAXL = 1e6 + 10;


int32_t T, n, m, V, L, idx_car;
int32_t v[N], d[N], a[N], p[N];
int32_t pre_p[MAXL]; //p的按距离前缀和

int32_t ans1, ans2;

int32_t detectd[N];


void check(int i)
{
    printf("v:%d d:%d a:%d", v[i], d[i], a[i]);

}




int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);

    read(T);

    while(T--)
    {
        idx_car = 0;
        read(n, m, L, V);

        memset(detectd, 0x3f, n * sizeof (int32_t) );
        memset(pre_p, 0, n * sizeof (int32_t));
        ans1 = ans2 = 0;

        for(int di, vi, ai, i = 1;i <= n;i++)
        {
            read(di, vi, ai);

            if(ai <= 0 and vi <= V)continue;
            else if( ai > 0 and ((int)ceil(sqrt(1.0 * vi * vi + 2.0 * ai * (L - di))) <= V )  )continue;
            else
            {
                d[++idx_car] = di;
                v[idx_car] = vi;
                a[idx_car] = ai;
            }
        }
        for(int i = 1;i <= m;i++) read(p[i]);

        for(int pidx = 1,i = p[pidx];i <= L + 1;i++)
        {
            if(i == p[pidx])
            {
                pre_p[i] = pre_p[i - 1] + 1;
                pidx++;
            }
            else
            {
                pre_p[i] = pre_p[i - 1];
            }
        }

        for(int i = 1;i <= idx_car;i++)
        {
            if(a[i] >= 0 and v[i] > V) detectd[i] = d[i];
            else if(a[i] >= 0)detectd[i] = min(d[i] + (int)floor( (1.0 * V * V - 1.0 * v[i] * v[i]) / (2.0 * a[i])) + 1, L);
            else detectd[i] = min(d[i] + (int)ceil( (1.0 * v[i] * v[i] - 1.0 * V * V) / (2.0 * -a[i])) - 1,L);

//            check(i);printf(" %d \n", detectd[i]);

            if(a[i] < 0 and pre_p[detectd[i]] - pre_p[d[i] - 1] > 0)ans1++;
            else if(a[i] >= 0 and pre_p[L + 1] - pre_p[detectd[i] - 1] != 0)ans1++;
        }
        printf("%d ",ans1);

        for(int i = 1;i <= idx_car;i++)
        {
            if(a[i] >= 0) continue; // 所有a大于0的留最北端一个就好了
            if(a[i] < 0)//真不会（）
            {
        	    if(pre_p[detectd[i]] - pre_p[d[i] - 1] == 1) ans2++;
        	    for(int j = p[pre_p[d[i]] + 1];j <= L;j++)pre_p[j]--;
		    }
		}
        printf("%d\n", m - (ans2 + ans1==0?0:1));


    }

    return 0;
}
