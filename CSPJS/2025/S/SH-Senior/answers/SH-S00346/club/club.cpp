#include <bits/stdc++.h>
using namespace std;

int t,n,n2;
const int N=1e5+100;
struct Stu
{
	int a,b,c;
	int d1,d2;
}stu[N];
int cnt[4];
long long ans;

int read()
{
	char ch=getchar();
	int res=0,f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}
bool cmp(Stu A,Stu B)
{
	if(A.d1==B.d1)
	{
		if(A.d2==B.d2)
		{
			if(A.a==B.a)
			{
				if(A.b==B.b)
				{
					return A.c>=B.c;
				}
				return A.b>B.b;
			}
			return A.a>B.a;
		}
		return A.d2>B.d2;
	}
	return A.d1>B.d1;
}
int solve(Stu s)
{
	int mx1,mx2,mx3,id1,id2,id3;
	if(s.a>=s.b&&s.a>=s.c)
	{
		mx1=s.a,id1=1;
		mx2=max(s.b,s.c);
		id2=s.b>=s.c?2:3;
		mx3=min(s.b,s.c);
		id3=s.b<s.c?2:3;
	}
	else if(s.b>=s.a&&s.b>=s.c)
	{
		mx1=s.b,id1=2;
		mx2=max(s.a,s.c);
		id2=s.a>=s.c?1:3;
		mx3=min(s.a,s.c);
		id3=s.a<s.c?1:3;
	}
	else
	{
		mx1=s.c,id1=3;
		mx2=max(s.a,s.b);
		id2=s.a>=s.b?1:2;
		mx3=min(s.a,s.b);
		id3=s.a<s.b?1:2;
	}
//	printf("%d %d %d %d %d %d %d %d %d\n",mx1,mx2,mx3,id1,id2,id3,cnt[1],cnt[2],cnt[3]);
	if(cnt[id1]<n2)
	{
		++cnt[id1];
		return mx1;
	}
	else
	{
		if(cnt[id2]<n2)
		{
			++cnt[id2];
			return mx2;
		}
		else
		{
			++cnt[id3];
			return mx3;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	t=read();
	while(t--)
	{
		ans=0;
		memset(cnt,0,sizeof(cnt));
		n=read();
		n2=n/2;
		for(int i=1;i<=n;i++)
		{
			stu[i].a=read(),stu[i].b=read(),stu[i].c=read();
			int aa=stu[i].a,bb=stu[i].b,cc=stu[i].c;
			if(aa<bb) swap(aa,bb);
			if(bb<cc) swap(bb,cc);
			if(aa<bb) swap(aa,bb);
			stu[i].d1=aa-bb;
			stu[i].d2=aa-cc;
		}
		sort(stu+1,stu+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
//			printf("%d %d %d\n",stu[i].a,stu[i].b,stu[i].c);
			int temp=solve(stu[i]);
//			printf("%d\n",temp);
			ans+=temp;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
