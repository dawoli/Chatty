#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define fr(aaa,bbb,i) for(int i=aaa,i##end=bbb;i<=i##end;++i)
#define rf(bbb,aaa,i) for(int i=bbb,i##end=aaa;i>=i##end;--i)
#define maxn 100007
int n,a[maxn];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n;
	fr(1,n,i){
		cin>>a[i];
	}sort(a+1,a+n+1);
	int num=0,ct=1,ans=0;
	fr(2,n,i){
		if(a[i]!=a[i-1]){
			num+=ct;
			if(num>0) num--,ans++;
			ct=1;
		}else{
			if(num>0) num--,ans++;
			ct++;
		}
	}cout<<n-ans;
	return 0;
} 
