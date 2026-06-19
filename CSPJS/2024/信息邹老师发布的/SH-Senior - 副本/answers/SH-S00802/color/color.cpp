#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[100009]; 
int check(string s){
	int ans=0;
	for(int i=2;i<=n;i++){
		bool flag=0;
		for(int j=i-1;j>=1;j--){
			if(flag==0&&s[i-1]==s[j-1]){
				flag=1;
				if(a[i]==a[j]) ans+=a[i];
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int x=pow(2,n),ans=0;
		for(long long i=0;i<x;i++){
			string s="";
			for(int j=i;j;j/=2) {
				if(j%2==1) s+='1';
				else s+='0';
		}
			while(s.size()<n) s='0'+s;
			//if(check(s)>ans) cout<<s<<' '<<check(s)<<endl;
			ans=max(ans,check(s));
		}
		cout<<ans<<endl;
	}
	return 0;
}
