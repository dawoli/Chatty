#include<bits/stdc++.h>
using namespace std;
int n,m,k[510],cnt=0,ans=1;
string tmp;
bool a[510],flag=false;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>tmp;
	for(int i=0;i<n;i++){
		cin>>k[i];
		if(k[i]==0) cnt++;
	}
	
	for(int i=0;i<n;i++){
		if(tmp[i]=='1') a[i]=1; 
		else{
			a[i]=0;
			flag=true;
		}
	}
	if(n==m){
		if(cnt>0 || flag) cout<<0;
		for(int i=0;i<n-cnt;i++){
			ans=ans*(n-cnt)%998244353;
		}
	}
	cout<<ans;
	return 0;
}
