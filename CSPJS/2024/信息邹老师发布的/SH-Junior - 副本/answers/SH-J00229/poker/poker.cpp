#include<bits/stdc++.h>
using namespace std;
int n;
string s[10009];
int cnt=0;
int ans=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n);
	while(1){
		if(s[cnt]!=s[cnt+1]){
			cnt++;
			ans++;
		}
		if(s[cnt]==s[cnt+1]){
			cnt++;
		}
		if(cnt>n){
			break;
		}
	}
	cout<<52-ans;
	return 0;
}
