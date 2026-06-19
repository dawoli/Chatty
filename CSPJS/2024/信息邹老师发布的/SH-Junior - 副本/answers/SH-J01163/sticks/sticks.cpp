#include<bits/stdc++.h>
using namespace std;
int dx[]={6,2,5,5,4,5,6,3,7,6};
int n;
string s,ans="-1";
void dfs(int x){
	if(x==n){
		if(ans=="-1"&&s[0]!='0'){
			ans=s;
		}
		if(s[0]!='0'){
			if(ans.length()==s.length()){
				if(ans>s) ans=s;
			}else{
				if(ans.length()>s.length()) ans=s;
			}
		}
		return;
	}
	for(int i=0;i<=9;i++){
		if(x+dx[i]<=n){
			s+=char(i+'0');
			dfs(x+dx[i]);
			s.erase(s.length()-1,1);
		}
	}
	return;
}
int main(){ 
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%7==0){
			while(n!=0){
				cout<<8;
				n-=7;
	    	}
		}else if(n%7==1){
			n-=8;
			cout<<10;
			while(n!=0){
				cout<<8;
				n-=7;
			}
		}else{
		    dfs(0);
		    cout<<ans<<endl;
		    ans="-1";
		}
	}
	return 0;
} 
