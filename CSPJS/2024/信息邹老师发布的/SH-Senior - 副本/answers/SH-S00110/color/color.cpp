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
	string FILENAME="color";
	if(FILENAME!="")
	{
		freopen((FILENAME+".in").c_str(),"r",stdin);
		freopen((FILENAME+".out").c_str(),"w",stdout);
	}else puts("Warning: No file IO.\n");
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
}
int T,n,a[200009];
long long rst[1000009],rsttag;
struct segment{long long mx,tg;}tr[1000009];
inline void brush(int u,long long tg){tr[u].tg+=tg;tr[u].mx+=tg;}
inline void pushdown(int u){
	brush(u<<1,tr[u].tg);
	brush((u<<1)|1,tr[u].tg);
	tr[u].tg=0;
}
inline void pushup(int u){tr[u].mx=max(tr[u<<1].mx,tr[(u<<1)|1].mx);}
inline void change(int u,int l,int r,int p,long long C)
{
	if(l==r){tr[u]={C,0};return;}
	int mid=(l+r)>>1;
	pushdown(u);
	p<=mid?change(u<<1,l,mid,p,C):change((u<<1)|1,mid+1,r,p,C);
	pushup(u);
}
inline void add(int u,int l,int r,int L,int R,long long A)
{
	if(l>R||r<L)return;
	if(L<=l&&r<=R)
	{
		brush(u,A);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(u);
	add(u<<1,l,mid,L,R,A);
	add((u<<1)|1,mid+1,r,L,R,A);
	pushup(u);
}
inline long long qmax(int u,int l,int r,int L,int R)
{
	if(l>R||r<L)return -1145141919810114514ll;
	if(L<=l&&r<=R)return tr[u].mx;
	int mid=(l+r)>>1;
	pushdown(u);
	return max(qmax(u<<1,l,mid,L,R),qmax((u<<1)|1,mid+1,r,L,R));
}
inline void solve()
{
	n=read<int>();
	for(int i=1;i<=n;++i)a[i]=read<int>(),rst[a[i]]=-1145141919810114514ll;
	for(int i=1;i<=(n<<2)+25;++i)tr[i]=tr[0];
	rsttag=0;
	for(int i=1;i<=n;++i)
	{
		long long fi1=max(qmax(1,0,n-1,0,i-2),0ll);
		//if(rst[a[i]]>=0)rst[a[i]]+=a[i];
		fi1=max(fi1,rst[a[i]]+a[i]+rsttag);
		if(a[i]==a[i-1])add(1,0,n-1,0,i-2,a[i]),rsttag+=a[i];
		rst[a[i-1]]=max(rst[a[i-1]],fi1-rsttag);
		change(1,0,n-1,i-1,fi1);
	}
	printf("%lld\n",qmax(1,0,n-1,0,n-1));
}
inline void main_solve()
{
	tr[0]={-1145141919810114514ll,0};
	T=read<int>();
	while(T--)solve();
}
int main()
{
	main_init();
	main_solve();
	return 0;
}
