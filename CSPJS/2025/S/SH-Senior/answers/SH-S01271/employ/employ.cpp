#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int na[505]={0},cnt0=0;
	for(int i=1;i<=n;i++){
		cin>>na[i];
		if(na[i]==0){
			cnt0++;
		}
	}
	if(cnt0==0){
		long long cnt=1;
		for(int i=n;i>=n-m+1;i--){
			cnt=(cnt%998244353)*i; 
		}
		cout<<cnt%998244353;
		return 0;
	}
 	else {
 		if(n-cnt0<m){
 			cout<<0;
 			return 0;
		}
		else{
			n=n-cnt0;
			long long cnt=1;
			for(int i=n;i>=n-m+1;i--){
				cnt=(cnt%998244353)*i; 
			}
			cout<<cnt%998244353;
			return 0;	
		}
	}
	return 0;
}
