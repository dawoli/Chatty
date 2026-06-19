#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long,long long>
#define x first
#define s second
#define mp make_pair
const int N=2e5+10,M=5e6+10;
const int P1=131,M1=998244353,P2=17,M2=1e9+7;
int n,q;
map<pair<pii,pii>,int> v;
int cnt=0;
struct node{
	int x,y,k,id,t;
}a[2*N];
int ans[N];
bool cmp(node l,node r){
	if(l.k==r.k){
		if(l.x==r.x){
			if(l.y==r.y){
				return l.id<r.id;
			}
			return l.y<r.y;
		}
		return l.x<r.x;
	}
	return l.k<r.k;
}
int len=0;
int c[M];
inline int l(int x){
	return x&(-x);
} 
inline void add(int x,int d){
	
	while(x<=5e6+2){
		c[x]+=d;
		x+=l(x);
	}
	
	//for(int i=x;i<=5e6;i++) c[i]+=d;
	return;
}
inline int ask(int x){
	
	int res=0;
	while(x){
		res+=c[x];
		x-=l(x); 
	} 
	return res;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	string s1,s2;
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		if(s1==s2) continue;
		l=0;r=s1.length()-1;
		while(s1[l]==s2[l]){
			l++;
		}
		while(s1[r]==s2[r]){
			r--;
		}
		long long a1=0,a2=0,a3=0,a4=0;
		for(int j=l;j<=r;j++){
			a1=(a1*P1+s1[j]-'a'+1)%M1;
			a2=(a2*P1+s2[j]-'a'+1)%M1;
			a3=(a3*P2+s1[j]-'a'+1)%M2;
			a4=(a4*P2+s2[j]-'a'+1)%M2;
		}
		if(!v[mp(mp(a1,a2),mp(a3,a4))]) v[mp(mp(a1,a2),mp(a3,a4))]=++cnt;
		a[++len]={l+1,s1.length()-r,v[mp(mp(a1,a2),mp(a3,a4))],0,-1};
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		l=0;r=s1.length()-1;
		while(s1[l]==s2[l]){
			l++;
		}
		while(s1[r]==s2[r]){
			r--;
		}
		long long a1=0,a2=0,a3=0,a4=0;
		for(int j=l;j<=r;j++){
			a1=(a1*P1+s1[j]-'a'+1)%M1;
			a2=(a2*P1+s2[j]-'a'+1)%M1;
			a3=(a3*P2+s1[j]-'a'+1)%M2;
			a4=(a4*P2+s2[j]-'a'+1)%M2;
		}
		if(!v[mp(mp(a1,a2),mp(a3,a4))]) ans[i]=0;
		else a[++len]={l+1,s1.length()-r,v[mp(mp(a1,a2),mp(a3,a4))],1,i};
	}
	//for(int i=1;i<=len;i++) cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].k<<" "<<a[i].id<<" "<<a[i].t<<'\n';
	sort(a+1,a+1+len,cmp);
	//cout<<'\n';
	//for(int i=1;i<=len;i++) cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].k<<" "<<a[i].id<<" "<<a[i].t<<'\n';
	int lst=1;
	for(int i=1;i<=len;i++){
		//for(int j=1;j<=10;j++) cout<<ask(j)<<" ";
		//cout<<'\n';
		if(a[i].id==1){
			ans[a[i].t]=ask(a[i].y);
		}
		else{
			add(a[i].y,1);
			//cout<<a[i].y<<"<-in\n";
		}
		if(a[i].k!=a[i+1].k){
			
			for(int j=lst;j<=i;j++){
				if(a[j].id==0) add(a[j].y,-1);
			}
			lst=i+1;
			
			
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
	

}
