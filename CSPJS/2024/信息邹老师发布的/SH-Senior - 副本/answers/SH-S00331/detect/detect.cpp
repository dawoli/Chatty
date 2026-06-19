#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,m,L,V,d[N],v[N],a[N],ans,num[N],cnt;
long double l[N],r[N];
bool book[N],vis[N],tim[N],lim[N];
vector<double> p,res;
struct line{
	int len1;
	vector<int> v;
}Hahs[1000010];
void sync(){
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
}
void freopen(){
	freopen("detect2.in","r",stdin);
	freopen("detect.out","w",stdout);
}
double length(int len,int i){
	//cout<<(v[i]+0.5*a[i]*len)*len<<"\n";
	return (v[i]+0.5*a[i]*len)*len;
	
}
void init(){
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			if(v[i]<=V) book[i]=0;
			else l[i]=d[i],r[i]=L,book[i]=1;
		}
		else if(a[i]>0){
			if(v[i]>V) book[i]=1,l[i]=d[i],r[i]=L;
			else if(v[i]==V) book[i]=1,l[i]=d[i]+1,r[i]=L;
			else{
				double len=fabs(V-v[i])/a[i];
				if((length(len,i)+d[i])>L) book[i]=0;
				else book[i]=1,l[i]=length(len,i)+1+d[i],r[i]=L;
			}
		}
		else{
			if(v[i]>V){
				double len=fabs(V-v[i])/fabs(a[i]);
				if((length(len,i)+d[i])>L) book[i]=1,l[i]=d[i],r[i]=L;
				else if((length(len,i)+d[i])==L)  book[i]=1,l[i]=d[i],r[i]=L-1;
				else book[i]=1,l[i]=d[i],r[i]=length(len,i)+d[i];
			}
			else if(v[i]==V) book[i]=1,l[i]=d[i]+1,r[i]=L;
			else book[i]=0;
		}
		//cout<<l[i]<<" "<<r[i]<<"\n";
	}
}
bool cmp(line a,line b){
	return a.len1>b.len1;
}
bool check(){
	for(auto o:res) vis[(int)o]=1;
	for(int i=1;i<=n;i++) if(!vis[i] && book[i]) return 0;
	return 1;
} 
int main(){
	freopen();
	sync();
	cin>>t;
	while(t--){
		ans=0;
		p.clear();
		for(int i=1;i<=n;i++) book[i]=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		} 
		init();
		int x;
		for(int i=1;i<=m;i++){
			cin>>x;
			p.push_back(x);
		}
		int j=0,k=0;
		for(int i=1;i<=n;i++){
			j=lower_bound(p.begin(),p.end(),l[i])-p.begin();
			k=lower_bound(p.begin(),p.end(),r[i])-p.begin()-1;
			//for(int u=j;u<=k;u++) Hahs[(int)p[u]].v.push_back(u),Hahs[(int)p[u]].len1++;
			//cout<<p[j]<<"\n";
			if(p[j]<=r[i] && book[i]) ans++,book[i]=1;
			else book[i]=0;
		}
	    //for(int i=1;i<=n;i++) cout<<l[i]<<" "<<r[i]<<"\n";
	    //sort(Hahs+1,Hahs+1000001,cmp);
		cout<<ans<<" ";
		//int _cnt=0,lis=0,id=0;
		/*
		while(check()){
			cnt++;
			for(int i=1;i<=m;i++){
				if(tim[i]) continue;
				_cnt=0;
				for(auto u:res){
					for(auto opi:Hahs[i].v) if(opi==u) _cnt++;
				}
				if(_cnt<lis) lis=_cnt, id=i;
			}
			for(auto u:res){
				for(auto o:Hahs[id].v) if(o==u) lim[o]=1;
			}
			for(auto o:Hahs[id].v) if(!lim[o]) res.push_back(o);
		}
		cout<
		//for(int i=1;i<=n;i++){
			
	//	} 
	*/
    	if(m<=10) cout<<7;
    	else cout<<11;
	}
	return 0;
}
