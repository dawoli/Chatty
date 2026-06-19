//prepare
#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
// prepare 
#include <cmath>
#include <algorithm>

constexpr int MAXN = 1e5 + 5;

int T, n, m, L, V;
	
struct Car
{
	int d, v, a;
} car[MAXN];

int mach[MAXN];

inline
double get_v_from_s(int i, int s2) 
{
	int d = car[i].d, v = car[i].v, a = car[i].a;
	return std::sqrt(v*v + 2*a*(s2 - d));
}
bool neverOverSpeed(int i)
{
	int d = car[i].d, v = car[i].v, a = car[i].a;
	if (a <= 0)
		return v <= V;
	return get_v_from_s(i, L) <= v*1.0;
}

int main() 
{
    cin.tie(nullptr) -> sync_with_stdio(false);
#ifndef DEBUG
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
#endif
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> L >> V;
		for (int i = 1; i <= n; ) 
		{
			cin >> car[i].d >> car[i].v >> car[i].a;
			if (neverOverSpeed(i))
				--n;
			else 
				++i;
		}
		for (int i = 1; i <= m; ++i)
			cin >> mach[i];
		std::sort(car+1, car+1+n, [](auto& a, auto& b){
			return a.d < b.d;
		});
		int mach_min = 0, o_s_size = 0;
		for (int i = 1; i <= n; ++i) // 车 
		{
			int j = std::lower_bound(mach+1, mach+1+m, car[i].d) - (mach+1);  // 第一个大于等于car.d 
			if (j == m)
				continue;
			for(; j <= m; ++j) // 所有测速仪 
			{
				if (get_v_from_s(i, mach[j]) > V*1.0) //超速 
				{
					mach_min = std::max(mach_min, j);
					o_s_size++;
					break;
				} 
			} 
		}
		cout << o_s_size << ' ' << (o_s_size? m-1: m) << endl;
	} 
#ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
#endif
}
