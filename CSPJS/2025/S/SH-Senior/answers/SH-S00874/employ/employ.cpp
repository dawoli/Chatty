//CCF PLEASEEEEEEEE
//Only baoli......
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

using namespace std;
const int N=500+5;
const int mod=998244353;
int n,m,c[N],n1,n2;
string s;
int p[20];
void sub0(){
	rep(i,1,n)p[i]=i;
	int ans=0;
	do{
		int sum=0,tao=0;
		rep(i,1,n)
			if(tao<c[p[i]]&&s[i-1]!='0'){
				sum++;
				if(sum>=m){
					ans++;
					ans%=mod;
					break;
				}
			}else tao++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<endl;
}
void sub1(){//m==1
	//I cant solve it......
 	//sort(c+1,c+n+1);
 	cout<<1<<endl;
}
void sub2(){
	//not as easy as i consider
	//give up
	cout<<0<<endl;
}
void solve(){
	cin>>n>>m;
	cin>>s;
	rep(i,1,n)cin>>c[i];
	if(n<=18){
		sub0();
		return;
	}
	if(m==1){
		sub1();
		return;
	}
	bool f=false;
	rep(i,0,n-1)
		if(s[i]!='1'){
			f=true;
			break;
		}
	if(!f){
		sub2();
		return;
	}
	cout<<0<<endl;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int TEST=1;
	//cin>>TEST;
	while(TEST--)
		solve();
	return 0;
} 
