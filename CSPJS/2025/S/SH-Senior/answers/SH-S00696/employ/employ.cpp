#include<bits/stdc++.h>
using namespace std;
long long maxn=-1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long ans=0,cnt=1,n,m,c[510],z=1,j;
	string s;
	cin>>n>>m>>s;
	j=n;
	long long len=s.length();
	for(long long i=0;i<len;i++){
		if(s[i]==0){
			ans++;
		}
	}
	for(long long i=0;i<n;i++){
		cin>>c[i];
		if(c[i]>maxn){
			maxn=c[i];
		}
	}
	if(m==1){
		if(maxn==-1){
			cout<<"0"<<endl;
			return 0;
		}
		for(int i=1;i<=n-1;i++){
			maxn=maxn*i;
			maxn=maxn%998244353;
		}
		cout<<maxn;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cnt=cnt*i;
		cnt=cnt%998244353;
	}
	cout<<cnt;
	return 0;
}
