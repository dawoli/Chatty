#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3005;
struct car
{
	int d,vel,a;
}c[N];
int T,n,m,l,v,cnt,num;
int pos[N],times[N];
bool tag[N];
void init()
{
	cnt = 0;
	num = 0;
	memset(tag,false,sizeof(tag));
	memset(pos,0,sizeof(pos));
	memset(times,0,sizeof(times));
}
double cal_speed(car x,int p)
{
	ll tmp = x.vel * x.vel + 2 * x.a * (p - x.d);
	if(tmp < 0)
		return -1.0;
	return sqrt(tmp);
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	while(T--)
	{
		/*Init Part*/
		vector <int> points[N];
		init();
		cin >> n >> m >> l >> v;
		for(int i=1;i<=n;i++)
			cin >> c[i].d >> c[i].vel >> c[i].a;
		for(int i=1;i<=m;i++)
			cin >> pos[i];
		sort(pos+1,pos+m+1);
		/*Cal Car Part*/
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(c[i].d > pos[j])
					continue;
				double now_v = cal_speed(c[i],pos[j]);
				if(now_v <= -1.0)
					break;
				if(now_v > (double)v)
				{
					tag[i] = true;
					times[j] ++;
					points[j].push_back(i);
					if(c[i].a >= 0)
					{
						for(int k=j+1;k<=m;k++)
						{
							times[k] ++;
							points[k].push_back(i);
						}
						break;
					}
				}
				else if(c[i].a <= 0)
					break;
			}
			if(tag[i])
				cnt ++;
		}
		cout << cnt << " ";
		/*Delete Part*/
		memset(tag,false,sizeof(tag));
		while(cnt > 0)
		{
			vector<int> rec;
			bool first_time[N];
			memset(first_time,false,sizeof(first_time));
			/*Finder*/
			int now = -1, mx = 0;
			for(int i=1;i<=m;i++)
				if(times[i] > mx)
				{
					now = i;
					mx = times[i];
				}
			/*Finder Ends*/
			cnt -= times[now];
			for(int i:points[now])
				if(tag[i] == false)
				{
					tag[i] = true;
					rec.push_back(i);
					first_time[i] = true;
				}
			for(int i=1;i<=m;i++)
				for(int j=0;j<points[i].size();j++)
					if(first_time[points[i][j]] && tag[points[i][j]])
						times[i] --;		
			for(int i=1;i<=m;i++)
				first_time[i] = false;
//			for(int i=1;i<=m;i++)
//				for(int j=0;j<points[i].size();j++)
//					for(int k:rec)
//						if(k == points[i][j])
//							times[i] --;
			num ++;
		}
		cout << m - num << endl;
	}
	return 0;
}
