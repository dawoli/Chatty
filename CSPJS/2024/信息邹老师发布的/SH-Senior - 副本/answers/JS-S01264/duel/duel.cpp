#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define down(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF=1e15;
void file(){
	 freopen("duel.in","r",stdin);
	 freopen("duel.out","w",stdout);
}
const ll N=200009;
ll n,a[N],cnt[N];
ll died[N],attack[N];
void input(){
	cin>>n;
	rep(i,1,n)cin>>a[i],cnt[a[i]]++;
}
void solve(){
	ll sum=0,mx=-INF;
	rep(i,1,n)mx=max(mx,a[i]);
	rep(i,1,mx+5)sum=max(sum,cnt[i]); 
	cout<<sum<<endl;
}
void solveBF(){
	rep(i,1,n)died[i]=0,attack[i]=1;
	sort(a+1,a+1+n);
	rep(i,1,n){
		rep(j,i+1,n){
			if(!attack[j])continue;
			if(a[j]<=a[i])continue;
			attack[j]=0,died[i]=1;
			break;
		}
	}
	ll sum=0;
	rep(i,1,n)if(died[i])sum++;
	cout<<n-sum<<endl;
}
int main(){
	file();
	input();
	if(n<=10)
		solveBF();
	else
		solve();
	return 0;
}

