#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=200009;
const int T=5e6+9;
int n,q,ans[N];
string s[N][3],t[N][3];
vector<int> ls[T][2],lt[T][2];
int bit[T],x[N],y[N],f[N],g[N];
int LSB(int x){return x&(-x);}
void add(int x,int k){for(;x<=T-9;x+=LSB(x)) bit[x]+=k;}
int rsq(int x){
	int sum=0;
	for(;x;x-=LSB(x)) sum+=bit[x];
	return sum;
}
int maxL=0,len=0;
struct Node{
	int hx,hy;
	bool id;
	int num;
}c[N];
bool cmp(const Node&A,const Node&B){
	if(A.hx!=B.hx) return A.hx<B.hx;
	if(A.hy!=B.hy) return A.hy<B.hy;
	return A.id<B.id;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++) cin>>t[i][1]>>t[i][2];
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i][1].size();j++)
			if(s[i][1][j]=='a'&&s[i][2][j]=='b') x[i]=j;
			else if(s[i][1][j]=='b'&&s[i][2][j]=='a') y[i]=j;
		maxL=max(maxL,abs(x[i]-y[i]));
		if(x[i]>y[i]){
			ls[x[i]-y[i]][0].push_back(i);
			y[i]=s[i][1].size()-y[i];
		}
		else{
			ls[y[i]-x[i]][1].push_back(i);
			x[i]=s[i][1].size()-x[i];
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=0;j<t[i][1].size();j++)
			if(t[i][1][j]=='a'&&t[i][2][j]=='b') f[i]=j;
			else if(t[i][1][j]=='b'&&t[i][2][j]=='a') g[i]=j;
		maxL=max(maxL,abs(f[i]-g[i]));
		if(f[i]>g[i]){
			lt[f[i]-g[i]][0].push_back(i);
			g[i]=t[i][1].size()-g[i];
		}
		else{
			lt[g[i]-f[i]][1].push_back(i);
			f[i]=t[i][1].size()-f[i];
		}
	}
	/*for(int i=1;i<=q;i++){
		for(int j=0;j<t[i][1].size();j++)
			if(t[i][1][j]=='a'&&t[i][2][j]=='b') f[i]=j;
			else if(t[i][1][j]=='b'&&t[i][2][j]=='a') g[i]=j;
		if(f[i]>g[i]) lt[f[i]-g[i]][0].push_back(i);
		else lt[g[i]-f[i]][1].push_back(i);
		maxL=max(maxL,abs(f[i]-g[i]));
	}*/
	for(int i=1;i<=maxL;i++){
		for(int j=0;j<2;j++){
			if(ls[i][j].size()==0||lt[i][j].size()==0) continue;
		//	cout<<i<<" "<<j<<endl;
			len=0;
			for(int u=0;u<ls[i][j].size();u++)
				c[++len]=(Node){x[ls[i][j][u]],y[ls[i][j][u]],0,ls[i][j][u]};
			for(int u=0;u<lt[i][j].size();u++)
				c[++len]=(Node){f[lt[i][j][u]],g[lt[i][j][u]],1,lt[i][j][u]};
			sort(c+1,c+len+1,cmp);
			for(int u=1;u<=len;u++){
				if(c[u].id==0) add(c[u].hy,1);
				else ans[c[u].num]=rsq(c[u].hy);
			}
			for(int u=1;u<=len;u++)
				if(c[u].id==0) add(c[u].hy,-1);
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
	return 0;
} 
