#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5+5;
int T;

int n,m,L,V,p[MAXN];
struct node{
	int d,v,a;
}car[MAXN];
struct node2{
	int lt,rt;
}q[MAXN];
bool flag[MAXN];

bool cmp(node x,node y){
	return x.d<y.d;
}

bool check(int i,int x){
	return car[i].v*car[i].v+2*car[i].a*(p[x]-car[i].d)>V*V;
}

void Solve1(){
	int ans=0,cnt=1;
	for(int i=1;i<=n;++i)
	{
		if(car[i].d>p[m])
			break;
		while(car[i].d>p[cnt]&&cnt<m)
			++cnt;
		if((car[i].a>=0&&car[i].v*car[i].v+2*car[i].a*(p[m]-car[i].d)>V*V)||(car[i].a<0&&car[i].v*car[i].v+2*car[i].a*(p[cnt]-car[i].d)>V*V))
			++ans,flag[i]=true;
	}
	cout<<ans<<" ";
}

void Solve2(){
	int ans=0,cnt=1,cur=0;
	bool is_AB=true,is_C=true,used_flag=false;
	for(int i=1;i<=n;++i)
	{
		if(!flag[i])
			continue;
		if(flag[i])
			used_flag=true;
		if(car[i].a<0)
			is_AB=false;
		if(car[i].a>=0)
			is_C=false;
	}
	if(!used_flag)
	{
		cout<<m<<endl;
		return;
	}
	if(is_AB)
	{
		cout<<m-1<<endl;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(car[i].d>p[m])
			break;
		if(!flag[i])
			continue;
		while(car[i].d>p[cnt]&&cnt<m)
			++cnt;
		int l=cnt,r=m;
		if(car[i].a==0)
		{
			q[++cur].lt=cnt;
			q[cur].rt=m;
		}
		else if(car[i].a>0)
		{
			while(l<=r-5)
			{
				int mid=(l+r)/2;
				if(check(i,mid))
					r=mid;
				else
					l=mid;
			}
			for(int j=l;j<=r;++j)
				if(check(i,j))
					l=j;
			q[++cur].lt=l;
			q[cur].rt=m;
		}
		else
		{
			while(l<=r-5)
			{
				int mid=(l+r)/2;
				if(check(i,mid))
					l=mid;
				else
					r=mid;
			}
			for(int j=l;j<=r;++j)
				if(check(i,j))
					l=j;
			q[++cur].lt=cnt;
			q[cur].rt=l;
		}
	}
	for(int i=1;i<=m;++i)
	{
		bool chk=false;
		for(int j=1;j<=cur&&!chk;++j)
			if(q[j].lt==i&&q[j].rt==i)
			{
				q[j].lt=m+1;
				++ans;
				chk=true;
			}
		for(int j=1;j<=cur;++j)
		{
			if(chk&&q[j].lt==i&&q[j].rt>=i)
				q[j].lt=m+1;
			if(!chk&q[j].lt==i&&q[j].rt>=i)
				++q[j].lt;
		}
	}
	cout<<m-ans<<endl;
	return;
}

signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(flag,false,sizeof(flag));
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;++i)
			cin>>car[i].d>>car[i].v>>car[i].a;
		for(int i=1;i<=m;++i)
			cin>>p[i];
		sort(car+1,car+n+1,cmp);
		Solve1();
		Solve2();
	}
	return 0;
}
