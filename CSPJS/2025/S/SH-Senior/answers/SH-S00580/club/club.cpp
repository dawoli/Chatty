#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9; 
bool flag=1; 
ll T;
ll n,a[N][4],mx;
ll c[N],cnt[4];
//ll mc[N];
struct node{
	ll id,v;
	ll r1,r2,r3;//rank
}b[N];
bool cmp(node x,node y){
	return x.v>y.v;
}
ll cal(){
	ll ans=0;
	for(ll i=1;i<=n;i++)
		ans+=a[i][c[i]];
	return ans;
}
void dfs(ll x){
	//cout<<"+";
	if(x==n+1){
		if(mx<cal()) {
		//	for(int i=1;i<=n;i++) mc[i]=c[i];
			mx=cal();
		}
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<n/2){
			c[x]=i;
			cnt[i]++;
			dfs(x+1);
			cnt[i]--;
		}
	}
}
void solve2(){
	for(int i=1;i<=n;i++){
		b[i].id=i;
		b[i].v=abs(a[i][1]-a[i][2]);
	}
	sort(b+1,b+1+n,cmp);
	ll i=1;
	while(cnt[1]<n/2&&cnt[2]<n/2){
		if(a[b[i].id][1]>a[b[i].id][2]){
			c[b[i].id]=1;	
			cnt[1]++;
		}
		else{
			c[b[i].id]=2;
			cnt[2]++;
		}
		i++;
	}
	if(cnt[1]==n/2){
		for(int i=1;i<=n;i++) 
			if(!c[i]) {
				c[i]=2;
				cnt[2]++;
			}
	}else{
		for(int i=1;i<=n;i++) 
			if(!c[i]) {
				c[i]=1;
				cnt[1]++;
			}
	}
	//cout<<cnt[1]<<" "<<cnt[2]<<endl; 
	mx=cal();
	return;
}
void solve(){
	for(int i=1;i<=n;i++){
		b[i].id=i;
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
			b[i].r1=1;
			if(a[i][2]>=a[i][3])
				b[i].r2=2,b[i].r3=3;
			else
				b[i].r2=3,b[i].r3=2;
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) {
			b[i].r1=2;
			if(a[i][1]>=a[i][3])
				b[i].r2=1,b[i].r3=3;
			else
				b[i].r2=3,b[i].r3=1;
		}
		else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) {
			b[i].r1=3;
			if(a[i][1]>=a[i][2])
				b[i].r2=1,b[i].r3=2;
			else
				b[i].r2=2,b[i].r3=1;
		} 
		b[i].v=a[i][b[i].r1]-a[i][b[i].r2]; 
	}
	sort(b+1,b+1+n,cmp);
	ll i=1;
	//cout<<"*";
	while(cnt[1]<n/2&&cnt[2]<n/2&&cnt[3]<n/2&&i<=n){
		c[b[i].id]=b[i].r1;
		cnt[b[i].r1]++;
		i++;
	}
	ll num;
	//cout<<"*";
	for(ll i=1;i<=3;i++)
		if(cnt[i]==n/2) num=i;
	//cout<<"*";
	for(ll i=1;i<=n;i++) 
		if(!c[b[i].id]) {
			if(b[i].r1!=num) c[b[i].id]=b[i].r1;
			else c[b[i].id]=b[i].r2;
		}
	//cout<<"*";
	//cout<<cnt[1]<<" "<<cnt[2]<<endl; 
	mx=cal();
	return;
}
void mem(){
	fill(cnt,cnt+4,0);
	fill(c,c+n+1,0);
	for(ll i=1;i<=n;i++){
		b[i].v=0;
	}
	mx=0;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		mem();
		cin>>n;
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=3;j++)
					cin>>a[i][j];
		for(ll i=1;i<=n;i++)
			if(a[i][3]!=0) flag=0;
		if(n<=10){
			dfs(1);
			cout<<mx<<endl;
			/*for(ll i=1;i<=n;i++){
				cout<<mc[i]<<" ";
			}
			cout<<endl;*/
		}
		else if(flag){
			solve2();
			cout<<mx<<endl;
		}
		else{
			solve();
			cout<<mx<<endl;
			/*for(ll i=1;i<=n;i++){
				cout<<c[i]<<" ";
			}
			for(ll i=1;i<=n;i++){
				cout<<i<<" "<<b[i].id<<" "<<b[i].v<<" "<<b[i].r1<<" "<<b[i].r2<<endl;
			}
			cout<<endl;*/
		}
	}
	return 0;
}


