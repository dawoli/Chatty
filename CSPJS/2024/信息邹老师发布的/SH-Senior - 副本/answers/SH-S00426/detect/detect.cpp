#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int T, n , m, L, d[MAXN], v[MAXN], a[MAXN], p[MAXN], cnt, vis[MAXN], num;
pair<int, int> ranges[MAXN];
long long V;
int GetFirstDetector(int s)
{
	int result=0,l=1, r=m, mid=(l+r)>>1;
	while(mid!=l&&mid!=r)
	{
		if(s>p[mid])
		{
			l=mid;mid=(l+r)>>1;
		}
		else if(s<p[mid])
		{
			r=mid;mid=(l+r)>>1;
		}
		else if(s == p[mid])
		{
			return mid;
		}
	}
	if(s>p[l])
	{
		result = r;
	}
	else
	{
		result = l;
	}
	return result;
}
pair<int,int> GetIntersection(pair<int,int> a, pair<int, int> b)
{
	pair<int, int> result;
	result.first=max(a.first, b.first);
	result.second=min(a.second, b.second);
	if(result.first>result.second)
	{
		result.first=result.second=0;
	}
	return result;
}
bool cb(pair<int, int> a, pair<int, int> b)
{
	return ((a.second-a.first)<=(b.second-b.first));
}
bool cb2(pair<int, int> a, pair<int, int> b)
{
	return a.first<=b.first;
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>L>>V;
		for(int i=0;i<=n;i++)
		{
			ranges[i].first=ranges[i].second=0;vis[i]=0;
		}
		V=V*V;
		cnt=num=0;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		
		for(int i=1;i<=n;i++)
		{
			int fd = GetFirstDetector(d[i]), flag=0, detectors[MAXN], cntR=0;
			//cout<<"fd:"<<p[fd]<<endl;
			for(int j=fd;j<=m;j++)
			{
				int tempV = v[i]*v[i] + 2*a[i]*(p[j] - d[i]);
				//tepan
				if(tempV>V&&a[i]>=0)//chaosu
				{
					ranges[i].first=j;
					ranges[i].second=m;
					flag=1;
					break;
				}
				else if(tempV<=V&&a[i]<=0)//buchaosu
				{
					break;
				}
				if(tempV>V)
				{
					flag=1;
					detectors[++cntR]=j;
				}
			}
			if(ranges[i].first==0&&cntR!=0)
			{
				ranges[i].first=detectors[1];
				ranges[i].second=detectors[cntR];
			}
			if(flag==1)
			{
				cnt++;
			}
		}
		int sum[MAXN], index = 0;
		for(int i=1;i<=n;i++)
		{
			index = 0;
			if(vis[i]||ranges[i].first == 0)
			{
				continue;
			}
			for(int j=1;j<=n;j++)
			{
				if(vis[j]||ranges[j].first == 0)
				{
					continue;
				}
				pair<int, int> temp;
				temp.first=temp.second=j;
				if(GetIntersection(temp, ranges[i]).first!=0)
				{
					sum[j]++;
				}
			}
			for(int j = 1;j<=n;j++)
			{
				if(sum[j]>sum[index])
				{
					index = j;
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(vis[j]||ranges[j].first == 0)
				{
					continue;
				}
				pair<int, int> temp;
				temp.first=temp.second=index;
				if(GetIntersection(temp, ranges[i]).first!=0)
				{
					vis[j] = 1;
				}
			}
		}
		cout<<cnt<<" "<<m-num<<endl;
	}
}
