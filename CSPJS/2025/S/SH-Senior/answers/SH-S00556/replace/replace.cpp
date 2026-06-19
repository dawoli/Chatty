#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=5e6+5,mod=1e9+7,P=97;
string a[N],b[N];
struct node{
	ll hf,hb,lf,lb,flag,h1,h2;
}e[N];
map<pair<int,int>,int> mp;
vector<pair<int,int>> c[N];
vector<int> d[N];
ll t1[M],t2[M];
struct ddd{
	int mid,l,r,idx,ans;
}pro[N];
int tr[M];
bool cmp(int x,int y){return pro[x].l<pro[y].l;}
int lowbit(int x){
	return x&(-x);
} 
void add(int x,int y){
	for(;x<M;x+=lowbit(x)) tr[x]+=y;
	return;
}
int ask(int x){
	int ans=0;
	for(;x;x^=lowbit(x)) ans+=tr[x];
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q,cnt=0;
	cin>>n>>q;
	if(n<=100000 || q==1){
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			int len=a[i].size(),fir=-1,las=len;
			for(int j=0;j<len;j++){
				if(a[i][j]!=b[i][j]){
					fir=j;
					break;
				}
			}
			for(int j=len-1;j>=0;j--){
				if(a[i][j]!=b[i][j]){
					las=j;
					break;
				}
			}
			if(fir==-1){
				e[i].flag=0;
				continue;
			}
			e[i].flag=1;
			ll h1=0,h2=0;
			for(int j=fir;j<=las;j++) h1=(h1*P+a[i][j]-'a'+1)%mod;
			for(int j=fir;j<=las;j++) h2=(h2*P+b[i][j]-'a'+1)%mod;
			e[i].h1=h1,e[i].h2=h2;
//			if(!mp[{h1,h2}]) mp[{h1,h2}]=++cnt;
//			c[mp[{h1,h2}]].push_back(i);
			e[i].lf=fir;
			ll h=0;
			for(int j=fir-1;j>=0;j--) h=(h*P+a[i][j]-'a'+1)%mod;
			e[i].hf=h;
			e[i].lb=len-las-1;
			h=0;
			for(int j=las+1;j<len;j++) h=(h*P+a[i][j]-'a'+1)%mod;
			e[i].hb=h;
		}
		while(q--){
			string x,y;
			cin>>x>>y;
			if(x.size()!=y.size()){
				cout<<"0\n";
				continue;
			}
			int len=x.size(),fir=-1,las=len;
			for(int j=0;j<len;j++){
				if(x[j]!=y[j]){
					fir=j;
					break;
				}
			}
			for(int j=len-1;j>=0;j--){
				if(x[j]!=y[j]){
					las=j;
					break;
				}
			}
			ll h1=0,h2=0;
			for(int j=fir;j<=las;j++) h1=(h1*P+x[j]-'a'+1)%mod;
			for(int j=fir;j<=las;j++) h2=(h2*P+y[j]-'a'+1)%mod;
//			if(!mp[{h1,h2}]) mp[{h1,h2}]=++cnt;
//			c[mp[{h1,h2}]].push_back(i);
			for(int i=fir-1,j=1;i>=0;i--,j++) t1[j]=(t1[j-1]*P+x[i]-'a'+1)%mod;
			for(int i=las+1,j=1;i<len;i++,j++) t2[j]=(t2[j-1]*P+x[i]-'a'+1)%mod;
			int ans=0;
			for(int i=1;i<=n;i++){
				if(e[i].flag==1 && e[i].h1==h1 && e[i].h2==h2 && e[i].lf<=fir && t1[e[i].lf]==e[i].hf && e[i].lb<=len-las-1 && t2[e[i].lb]==e[i].hb) ans++;
			}
			cout<<ans<<"\n";
		}
	}
	else {
		
		
		
		
		
		
		
		
		
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			int len=a[i].size(),fir=-1,las=len;
			for(int j=0;j<len;j++){
				if(a[i][j]!=b[i][j]){
					fir=j;
					break;
				}
			}
			for(int j=len-1;j>=0;j--){
				if(a[i][j]!=b[i][j]){
					las=j;
					break;
				}
			}
			if(fir==-1) continue;
			c[las-fir+1].push_back({fir+1,len-las});
		}
		for(int i=1;i<=q;i++){
			string x,y;
			cin>>x>>y;
			if(x.size()!=y.size()){
				
				continue;
			}
			int len=x.size(),fir=-1,las=len;
			for(int j=0;j<len;j++){
				if(x[j]!=y[j]){
					fir=j;
					break;
				}
			}
			for(int j=len-1;j>=0;j--){
				if(x[j]!=y[j]){
					las=j;
					break;
				}
			}
			pro[i]={las-fir+1,fir+1,len-las,i,0};
			d[las-fir+1].push_back(i);
		}
		for(int i=1;i<=n;i++){
			sort(c[i].begin(),c[i].end());
			sort(d[i].begin(),d[i].end(),cmp);
			int lc=c[i].size(),ld=d[i].size();
			int j=0;
			for(int k=0;k<ld;k++){
				while(j<lc && c[i][j].first<=pro[d[i][k]].l){
					add(c[i][j].second,1);
					j++;
				}
				pro[d[i][k]].ans=ask(pro[d[i][k]].r);
			}
			while(j>0){
				j--;
				add(c[i][j].second,-1);
			}
		}
		for(int i=1;i<=q;i++){
			cout<<pro[i].ans<<"\n";
		}
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,mod=1e9+7,P=97;
string a[N],b[N];
struct node{
	int hf,hb,lf,lb;
}e[N];
map<pair<int,int>,int> mp;
vector<int> c[N],d[N];

int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q,cnt=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		int len=a[i].size(),fir=-1,las=len;
		for(int j=0;j<len;j++){
			if(a[i][j]!=b[i][j]){
				fir=j;
				break;
			}
		}
		for(int j=len-1;j>=0;j--){
			if(a[i][j]!=b[i][j]){
				las=j;
				break;
			}
		}
		if(fir==-1) continue;
		ll h1=0,h2=0;
		for(int j=fir;j<=las;j++) h1=(h1*P+a[i][j]-'a')%mod;
		for(int j=fir;j<=las;j++) h2=(h2*P+b[i][j]-'a')%mod;
		if(!mp[{h1,h2}]) mp[{h1,h2}]=++cnt;
		c[mp[{h1,h2}]].push_back(i);
		e[i].lf=fir;
		ll h=0;
		for(int j=0;j<fir;j++) h=(h*P+a[i][j]-'a')%mod;
		e[i].hf=h;
		e[i].lb=len-las-1;
		
	}
	
	return 0;
}
*/
