#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	char buf[1<<16],*p1,*p2,ibuf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,sizeof(buf),stdin)),p1==p2?EOF:*p1++)
	int rd(int x=0,int f=1)
	{
		for(;!isdigit(ibuf);ibuf=getchar())if(ibuf=='-')f=-1;
		for(;isdigit(ibuf);ibuf=getchar())x=x*10+(ibuf^48);
			return x*f;
	}
	int rds(char*s,int n=0)
	{
		for(;!isgraph(ibuf);ibuf=getchar());
		for(;isgraph(ibuf);ibuf=getchar())s[n++]=ibuf;
			return s[n]=0,n;
	}
}
using IO::rd;using IO::rds;
const int M=11000000;
int tr[M][26];
int rt[M];//for cores
int tot=1;//empty
int bit[M];
int hd[M],id[400040],ne[400040],tt=1;
int ans[200020];
int dfn=1;
int in[M],out[M];
char s[5000500],t[5000500];
vector<int>rts;//ltrees and rtrees
int CN[400040],LN[400040],RN[400040];
int CQ[400040],LQ[400040],RQ[400040];
void add(int x,int y)
{
	id[tt]=y;ne[tt]=hd[x];hd[x]=tt++;
}
void dfs1(int x)
{
	// cerr<<"RD: "<<x<<endl;
	in[x]=dfn++;
	for(int i=0;i<26;i++)if(tr[x][i])dfs1(tr[x][i]);
	out[x]=dfn;
}
void upd(int x,int v)
{
	for(;x<M;x+=x&-x)bit[x]+=v;
}
int qry(int x)
{
	int res=0;
	for(;x;x&=x-1)res+=bit[x];
		return res;
}
void dfs(int x)
{
	for(int i=hd[x];i;i=ne[i])
	{
		int j=id[i];
		if(j<0)
		{
			j=-j;
			// cerr<<"UPD: "<<RN[j]<<endl;
			upd(in[RN[j]],1);
			upd(out[RN[j]],-1);
		}
	}
	for(int i=hd[x];i;i=ne[i])
	{
		int j=id[i];
		if(j>0)
		{
			ans[j]+=qry(in[RQ[j]]);
		}
	}
	for(int i=0;i<26;i++)if(tr[x][i])dfs(tr[x][i]);
	for(int i=hd[x];i;i=ne[i])
	{
		int j=id[i];
		if(j<0)
		{
			j=-j;
			upd(in[RN[j]],-1);
			upd(out[RN[j]],1);
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cout.tie(0);
	// cerr<<"START"<<endl;
	int n=rd(),q=rd();
	int RT=tot++;
	for(int i=1;i<=n;i++)
	{
		int m=rds(s);rds(t);
		int p=0,q=m;
		while(p<q&&s[p]==t[p])p++;
		while(p<q&&s[q-1]==t[q-1])q--;
		// cerr<<p<<' '<<q<<endl;
		int P=RT;
		for(int i=p;i<q;i++)
		{
			int&x=tr[P][s[i]-'a'];
			if(!x)x=tot++;
			P=x;
		}
		for(int i=p;i<q;i++)
		{
			int&x=tr[P][t[i]-'a'];
			if(!x)x=tot++;
			P=x;
		}
		CN[i]=P;
		// cerr<<"CN: "<<i<<' '<<P<<endl;
		int&x=rt[P];
		if(!x)x=tot++,tot++,rts.push_back(x);
		// cerr<<"COREROOT: "<<x<<endl;
		//x,x+1 are the roots
		P=x;
		for(int i=p-1;i>=0;i--)
		{
			int&x=tr[P][s[i]-'a'];
			if(!x)x=tot++;
			P=x;
		}
		LN[i]=P;
		// cerr<<"LN: "<<i<<' '<<P<<endl;
		add(P,-i);
		P=x+1;
		for(int i=q;i<m;i++)
		{
			int&x=tr[P][s[i]-'a'];
			if(!x)x=tot++;
			P=x;
		}
		RN[i]=P;
		// cerr<<"RN: "<<i<<' '<<P<<endl;
	}
	for(int i=1;i<=q;i++)
	{
		int m=rds(s);int m2=rds(t);
		if(m!=m2)continue;
		int p=0,q=m;
		while(p<q&&s[p]==t[p])p++;
		while(p<q&&s[q-1]==t[q-1])q--;
		// cerr<<p<<' '<<q<<endl;
		int P=RT;
		for(int i=p;i<q;i++)
		{
			int&x=tr[P][s[i]-'a'];
			if(!x)x=tot++;
			P=x;
		}
		for(int i=p;i<q;i++)
		{
			int&x=tr[P][t[i]-'a'];
			if(!x)x=tot++;
			P=x;
		}
		CQ[i]=P;
		// cerr<<"CQ: "<<i<<' '<<P<<endl;
		int&x=rt[P];
		if(!x)x=tot++,tot++,rts.push_back(x);
		// cerr<<"COREROOT: "<<x<<endl;
		//x,x+1 are the roots
		P=x;
		for(int i=p-1;i>=0;i--)
		{
			int&x=tr[P][s[i]-'a'];
			if(!x)x=tot++;
			P=x;
		}
		LQ[i]=P;
		// cerr<<"LQ: "<<i<<' '<<P<<endl;
		add(P,i);
		P=x+1;
		for(int i=q;i<m;i++)
		{
			int&x=tr[P][s[i]-'a'];
			if(!x)x=tot++;
			P=x;
		}
		RQ[i]=P;
		// cerr<<"RQ: "<<i<<' '<<P<<endl;
	}
	// cerr<<"TRIES"<<endl;
	for(int x:rts)dfs1(x+1);
	// cerr<<"DFNS"<<endl;
	for(int x:rts)dfs(x);
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	// cerr<<"END"<<endl;
}