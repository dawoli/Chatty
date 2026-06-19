#include<bits/stdc++.h>
using namespace std;
int n,t;
long long ans;
int a[100007],b[100007],c[100007];
long long dfs(int i,int ca,int cb,int cc){
	if(i==n+1) return 0;
	long long ret=0;
	if(ca<n/2) ret=max(ret,dfs(i+1,ca+1,cb,cc)+a[i]);
	if(cb<n/2) ret=max(ret,dfs(i+1,ca,cb+1,cc)+b[i]);
	if(cc<n/2) ret=max(ret,dfs(i+1,ca,cb,cc+1)+c[i]);
	return ret;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n>200){
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;i--){
				sum+=a[i];
			}
			cout<<sum<<endl;
			continue;
		}
		cout<<dfs(1,0,0,0)<<endl;
	}
	return 0;
}

