#include <bits/stdc++.h>
using namespace std;
template<typename TN> inline TN read()
{
	char ch=getchar();
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	TN rst=0;
	bool mns=0;
	if(ch=='-')
	{
		mns=1;
		ch=getchar();
	}
	while('0'<=ch && ch<='9')
	{
		rst=(rst<<1)+(rst<<3)+ch-'0';
		ch=getchar();
	}
	return mns?-rst:rst;
}
inline void main_init()
{
	string FILENAME="detect";
	if(FILENAME!="")
	{
		freopen((FILENAME+".in").c_str(),"r",stdin);
		freopen((FILENAME+".out").c_str(),"w",stdout);
	}else puts("Warning: No file IO.\n");
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
}
int T,n,m,End,V,ans,p[100009],L[1000009],R[1000009],lst[100009],f[100009];
array<int,3> a[100009];
list<int> q;
inline int sq(int u){return u*u;}
inline void solve()
{
	n=read<int>();
	m=read<int>();
	End=read<int>();
	V=sq(read<int>());
	for(int i=1;i<=n;++i)a[i]={read<int>(),sq(read<int>()),read<int>()};
	for(int i=1;i<=m;++i)p[i]=read<int>();
	p[m+1]=End+1,p[0]=-1;
	for(int i=0;i<=End;++i)L[i]=R[i]=0;
	for(int i=1;i<=m;++i)
	{
		for(int j=p[i+1]-1;j>=p[i];--j)L[j]=i;
		for(int j=p[i-1]+1;j<=p[i];++j)R[j]=i;
		lst[i]=0;
	}
	for(int i=p[m]+1;i<=End;++i)R[i]=m+1;
	ans=0;
	for(int i=1;i<=n;++i)
	{
		if(R[a[i][0]]>m)continue;;
		int l,r; 
		if(a[i][2]>0)
		{
			l=max((V-a[i][1])/(a[i][2]<<1)+1,0);
			r=End;
		}else if(a[i][2]==0){
			if(a[i][1]<=V)continue;
			l=0,r=End;
		}else{
			if(a[i][1]<=V)continue;
			l=0;
			r=a[i][1]-V;
			if(r%((-a[i][2])<<1))r/=((-a[i][2])<<1);
			else r=r/((-a[i][2])<<1)-1;
		}
		l+=a[i][0],r+=a[i][0];
		r=min(r,End);
		if(l>r)continue;
		l=R[l],r=L[r];
		if(l>r)continue;
		++ans;
		lst[r]=max(lst[r],l);
	}
	printf("%d ",ans);
	while(!q.empty())q.pop_back();
	q.push_back(0);
	for(int i=1,frm=0;i<=m+1;++i)
	{
		frm=max(frm,lst[i-1]);
		while(!q.empty()&&q.front()<frm)q.pop_front();
		f[i]=q.empty()?0:f[q.front()]+1;
		while(!q.empty()&&f[q.back()]>=f[i])q.pop_back();
		q.push_back(i);
	}
	printf("%d\n",m-f[m+1]+1); 
}
inline void main_solve()
{
	T=read<int>();
	while(T--)solve();
}
int main()
{
	main_init();
	main_solve();
	return 0;
}

