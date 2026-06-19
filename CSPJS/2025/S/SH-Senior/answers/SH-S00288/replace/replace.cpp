#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,V=5e6+5,Vl=6e6+5;
int s[Vl][26],t[Vl][26];
int c[V],rs[V],rt[V],t1,t2;
vector<int> is[V];int lx,rx,le;
map<int,int> to[V];int tot=1;
int n,q,w[N],l[N],r[N];
string s1[N],s2[N],tl,tr;

void insr(int p,int q,int x){
	// cerr<<"insr: "<<x<<" "<<r[x]<<"\n";
	int qt=rt[q];//cerr<<c[qt]<<"\n";
	rt[p]=++t2;int z;
	for(int i=0;i<26;i++)
		t[rt[p]][i]=t[qt][i];
	c[rt[p]]=c[qt];
	int pt=rt[p];//cerr<<c[rt[p]]<<"\n";
	for(int i=r[x]+1;i<w[x];i++){
		// cerr<<pt<<" "<<qt<<"\n";
		z=s1[x][i]-'a';
		qt=t[qt][z];
		t[pt][z]=++t2;
		pt=t[pt][z];
		for(int j=0;j<26;j++)
			t[pt][j]=t[qt][j];
		c[pt]=c[qt];
	}c[pt]++;//cerr<<c[rt[p]]<<"\n";
}

void insl(int p,int x){
	// cerr<<"insl: "<<p<<" "<<x<<"\n";
	if(!rs[p])rs[p]=++t1;int pt=rs[p],z;
	for(int i=l[x]-1;i>=0;i--){
		z=s1[x][i]-'a';
		if(!s[pt][z])s[pt][z]=++t1;
		pt=s[pt][z];
	}is[pt].push_back(x);
}

void add(int x){
	int p=1,z;
	for(int i=l[x];i<=r[x];i++){
		z=(s1[x][i]-'a')*26+(s2[x][i]-'a');
		if(!to[p][z])to[p][z]=++tot;
		p=to[p][z];
	}insl(p,x);
}

void work(int x,int f){
	// cerr<<"work: "<<x<<" "<<f<<"\n";
	rt[x]=rt[f];//cerr<<c[rt[f]]<<"\n";
	for(auto i:is[x])insr(x,x,i);
	for(int i=0;i<26;i++)
		if(s[x][i])work(s[x][i],x);
}

void init(int x){//cerr<<"init: "<<x<<"\n";
	work(rs[x],0);
	for(auto i:to[x])init(i.second);
}

int askr(int p){
	int z,res=c[p];
	for(int i=rx+1;i<le;i++){
		z=(tl[i]-'a');
		p=t[p][z];if(!p)return res;
		res+=c[p];
	}return res;
}

int askl(int p){
	int z;
	for(int i=lx-1;i>=0;i--){
		z=(tl[i]-'a');
		if(!s[p][z])break;
		p=s[p][z];
	}return askr(rt[p]);
}

int get(){
	int p=1,z;
	for(int i=lx;i<=rx;i++){
		z=(tl[i]-'a')*26+(tr[i]-'a');
		p=to[p][z];if(!p)return 0;
	}return askl(rs[p]);
}

void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		w[i]=s1[i].length();
		l[i]=r[i]=-1;
		for(int j=0;j<w[i];j++)
			if(s1[i][j]!=s2[i][j]){l[i]=j;break;}
		for(int j=w[i]-1;j>=0;j--)
			if(s1[i][j]!=s2[i][j]){r[i]=j;break;}
		//cerr<<l[i]<<" "<<r[i]<<"\n";
		if(r[i]!=-1)add(i);
	}init(1);
	for(int i=1;i<=q;i++){
		cin>>tl>>tr;
		if(tl.length()!=tr.length())
			{cout<<"0\n";continue;}
		le=tl.length();lx=rx=-1;
		for(int j=0;j<le;j++)
			if(tl[j]!=tr[j]){lx=j;break;}
		for(int j=le-1;j>=0;j--)
			if(tl[j]!=tr[j]){rx=j;break;}
		cout<<get()<<"\n";
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T=1;while(T--)solve();
}