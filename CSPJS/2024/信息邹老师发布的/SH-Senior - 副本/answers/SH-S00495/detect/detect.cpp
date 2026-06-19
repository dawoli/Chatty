#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll T,n,m,L,V;
ll d[N],v[N],a[N],p[N],f[N],h[N];
struct line{
	ll l,r;
}c[N];
ll cnt=0;
bool cmp(const line&a,const line&b){
	return a.l<b.l||a.l==b.l&&a.r<b.r;
}
void input(){
	cin>>n>>m>>L>>V;
	for(ll i=1;i<=n;i++){
		cin>>d[i]>>v[i]>>a[i];
	}
	for(ll i=1;i<=m;i++){
		cin>>p[i];
	}
}
bool isrightnotok[N];//isrightnotok[i]=1表示右边的都不能去掉
ll ok[N];//OK[i]=1表示不能去掉 
void solve1(){
	ll ans=0;
	for(ll i=1;i<=n;i++){
		if(v[i]<=V&&a[i]<=0) continue;//初不超速且不加速
		else if(v[i]>V&&a[i]>=0){//初就超速还不减速
			ll k=upper_bound(p+1,p+m+1,d[i])-(p+1);
			if(k+1>m) continue;
			else{
				ans++;
				//ok[k+1]=1;
				//isrightnotok[k+1]=1;
				c[++cnt]=(line){k+1,m};
			} 
		} 
		else if(v[i]<=V&&a[i]>0){//加速到超速 
			double dis=(V*V-v[i]*v[i])*1.00000000/(2*a[i]);
			double pos=d[i]+dis;
			//cout<<"pos= "<<pos<<endl; 
			ll k=upper_bound(p+1,p+m+1,pos)-(p+1);
			//cout<<"k= "<<k<<endl;
			if(k+1>m) continue;
			else{
				ans++;
				//ok[k+1]=1;
				//isrightnotok[k+1]=1;
				//if(p[k]==d[i]) c[++cnt]=(line){k,k2};
				//else c[++cnt]=(line){k+1,k2};
				c[++cnt]=(line){k+1,m};
			}
		}
		else if(v[i]>V&&a[i]<0){//减速到不超速 
			double dis=(V*V-v[i]*v[i])*1.00000000/(2*a[i]);
			double pos=d[i]+dis;
			ll k=upper_bound(p+1,p+m+1,d[i])-(p+1);
			//cout<<k<<endl;
			ll k2=lower_bound(p+1,p+m+1,pos)-(p+1);
			//cout<<k2<<endl;
			if(p[k]!=d[i]&&k2==k) continue;
			if(p[k]==d[i]||(k2>k)){
				ans++;
				/*if(p[k]==d[i])
					for(ll j=k;j<=k2;j++) ok[j]=1;
				else
					for(ll j=k+1;j<=k2;j++) ok[j]=1;
				*/
				if(p[k]==d[i]) c[++cnt]=(line){k,k2};
				else c[++cnt]=(line){k+1,k2};
			}
		}
	}
	cout<<ans<<" ";
}
//vector<ll> t[N];
void solve2(){
	ll ans2=0;
	fill(f,f+N,0);
	fill(h,h+N,0);
	vector<ll> t[N];
	//sort(c+1,c+1+cnt,cmp);
	/*for(ll i=1;i<=cnt;i++){
		cout<<c[i].l<<" "<<c[i].r<<endl;
	}*/
	for(ll i=1;i<=cnt;i++){
		f[c[i].l]++;
		f[c[i].r+1]--;
		for(ll j=c[i].l;j<=c[i].r;j++) t[j].push_back(i);
	}
	for(ll i=1;i<=m;i++){
		h[i]=h[i-1]+f[i];
	}
	//for(ll i=1;i<=m;i++) cout<<h[i]<<" ";
	//cout<<endl;
	bool hascalc=0,ooooo=1;
	while(ooooo){
		ll maxx,i;
		if(!hascalc) maxx=*max_element(h+1,h+1+m);
		hascalc=1;
		for(i=1;i<=m;i++)
			if(h[i]==maxx&&h[i]!=0) break;
		//cout<<"保留第 "<<i<<endl;
		ans2++;
		for(ll j=0;j<t[i].size();j++){
			if(c[t[i][j]].l==-1) continue;
			f[c[t[i][j]].l]--;
			f[c[t[i][j]].r+1]++;
			c[t[i][j]].l=-1,c[t[i][j]].r=-1;
			
		}
		for(ll z=1;z<=m;z++){
			h[z]=h[z-1]+f[z];
		}
		hascalc=0;
		ooooo=0;
		for(ll x=1;x<=m;x++){
			//cout<<h[x]<<" ";
			if(h[x]) ooooo=1;
		}
		//cout<<endl;
	}
	//cout<<endl;
	cout<<m-ans2<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;	
	while(T--){
		input();
		solve1(); 
		solve2(); 
		cnt=0;
	}
	return 0;
}

