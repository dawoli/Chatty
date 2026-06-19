#include<bits/stdc++.h>
using namespace std;
struct T
{
	int a, id;
} t[105];
int n, m;
bool cmp(T x, T y)
{
	return x.a > y.a;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> t[i].a;
		t[i].id = i;
	}
	sort(t + 1, t + n * m + 1, cmp);
	int x;
	for(int i = 1; i <= n * m; i++)
	{
		if(t[i].id == 1)
		{
			x = i;
			break;
		}
	}
	int s = x / m, y = x % m;
	if(y == 0)
	{
		cout << s << " ";
	}
	else
	{
		s++;
		cout << s << " ";
	}
	if(s % 2)
	{
		cout << (y == 0? m : y);
	}
	else
	{
		cout << (y == 0? 1: m - y + 1);
	}
	// 至若春和景明，波澜不惊，上下天光，一碧万顷，沙鸥翔集，锦鳞游泳，岸芷汀兰，郁郁青青。而或长烟一空，皓月千里，浮光跃金，静影沉璧，渔歌互答，此乐何极！登斯楼也，则有……把酒临风，其喜洋洋者也。
	// 嗟夫，予尝求古仁人之心，或异二者之为，何哉？不以物喜，不以己悲，居庙堂之高则忧其民，处江湖之远则忧其君。是进亦忧，退亦忧，然则何时而乐耶？其必曰：“先天下之忧而忧，后天下之乐而乐”呼，噫！吾谁与归？时六年九月十五日。 
	return 0;
 } 
