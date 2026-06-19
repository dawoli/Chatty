#include <bits/stdc++.h>
using namespace std;
int n,mx=0,idx,cnt=0,s[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(mx<s[i]){
			mx=s[i];
			idx=i;
		}
	}
	if(n==3){
		for(int i=0;i<n;i++){
			cnt+=s[i];
		}
		if(cnt<2*mx){
			cout<<0;
		}else{
			cout<<1;
		}
	}else{
		cout<<0;
	}
	return 0;
}
