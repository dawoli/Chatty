#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll T=29,N=100109,M=100109;
ll t,n,m,V,L;
ll cnt_h=0;

struct node{
	ll l,r;//区间[l,r]中有车辆超速 
};
ll d[N],v[N],a[N];
ll p[M];//测速仪位置
node h[N];//区间 
bool ok[N];

bool cmp(const node &a,const node &b){
	return a.l<b.l||(a.l==b.l&&a.r<a.r);
}

void print(){
	for(ll i=1;i<=cnt_h;i++)if(ok[i])cout<<h[i].l<<" "<<h[i].r<<endl;
	cout<<endl;
}

ll nxt(ll x){
	for(ll i=x+1;i<=cnt_h;i++){
		if(ok[i])return i;
	}
	return -1;
}

void solve(){
	cnt_h=0;
	cin>>n>>m>>L>>V;
	for(ll i=1;i<=n;i++)ok[i]=1;
	for(ll i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
	for(ll i=1;i<=m;i++)cin>>p[i];
	for(ll i=1;i<=n;i++){
		if(a[i]==0){
			if(v[i]<=V)continue;
			cnt_h++;
			h[cnt_h].l=d[i];
			h[cnt_h].r=L;
		}
		else if(a[i]>0){
			ll tmp=V*V-v[i]*v[i];
			ll k=0;
			if(tmp%(2*a[i])==0)k=tmp/(2*a[i])+1;//开始超速的点 [k,L]
//			else k=(tmp-tmp%(2*a[i]))/(2*a[i])+1;
			else k=(tmp)/(2*a[i])+1;
			k+=d[i];
			k=max(k,d[i]);
			if(k>L)continue;
			cnt_h++;
			h[cnt_h].l=k;
			h[cnt_h].r=L;
		}
		else if(a[i]<0){
			ll tmp=V*V-v[i]*v[i];
			ll k=0;
			if(tmp%(2*a[i])==0)k=tmp/(2*a[i])-1;//[d[i],k]
//			else k=(tmp-tmp%(2*a[i])+2*a[i])/(2*a[i])-1;
//			else k=(tmp-tmp%(2*a[i]))/(2*a[i]);
			else k=(tmp)/(2*a[i]);
//			if(i==5)cout<<k<<endl;
			k+=d[i];
			k=min(k,L);
//			if(i==5)cout<<k<<endl;
			if(d[i]>k)continue;//?
			cnt_h++;
			h[cnt_h].l=d[i];
			h[cnt_h].r=k;
		}
	}
	sort(h+1,h+cnt_h+1,cmp);
	sort(p+1,p+m+1);
//	print();
	ll now_p=1,cnt=0;
//	cout<<p[now_p]<<endl;
	for(ll i=1;i<=cnt_h;i++){
		while(p[now_p]<h[i].l&&now_p<m)now_p++;
		if(h[i].l<=p[now_p] && p[now_p]<=h[i].r)cnt++;
		else ok[i]=0;
	}
	cout<<cnt<<" ";
	
	for(ll i=(ok[1]?1:nxt(1));i!=-1;i=nxt(i)){
		for(ll j=nxt(i);j!=-1;j=nxt(j)){
			if(h[j].r<=h[i].r){ok[i]=0;break;}
		}
	}
//	cout<<endl;
//	for(ll i=1;i<=cnt_h;i++)cout<<ok[i]<<endl;
//	cout<<endl;
	
//	if(t==11)print();
	
	now_p=1;
	ll ans=0;
	ll i;
	if(ok[1])i=1;
	else i=nxt(1);
	for(;i!=-1;i=nxt(i)){
//		cout<<i<<endl;
//		if(t==11)cout<<i<<endl;
		if(i==-1)break;
		while(p[now_p]<h[i].l&&now_p<m)now_p++;
		if(nxt(i)==-1){ans++;break;} 
//		if(h[nxt(i)].r<=h[i].r)continue;
		if(h[nxt(i)].l>h[i].r)ans++;
		if(h[nxt(i)].l<=h[i].r){
			while(p[now_p]<=h[i].r&&now_p<m)now_p++;
			now_p--;//now_p是最右边的能检测到这段超速的检测器 
			ans++;
//			while(h[nxt(nxt(i))].l<=p[now_p]&&nxt(nxt(i))!=-1)i=nxt(i);
			while(h[nxt(i)].l<=p[now_p]&&nxt(i)!=-1)i=nxt(i);
		}
	}
	if(cnt==0)ans=0;
	cout<<m-ans<<endl;
	
	for(ll i=1;i<=n;i++)a[i]=0,d[i]=0,v[i]=0;
	for(ll i=1;i<=m;i++)p[i]=0;
	return;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	cin>>t;
	while(t--)solve();
	
	return 0;
}
