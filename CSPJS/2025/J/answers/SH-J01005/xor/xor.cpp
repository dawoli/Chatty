#include<bits/stdc++.h>
using namespace std;
string turned2(long long int x){
	string s="";
	while(x>0){
		int w=x%2;
		char c=w+48;
		s=c+s;
		x/=2;
	}
	return s;
}
long long int turned10(string x){
	long long int cnt1=0;
	string s1=x;
	int w1=s1.size();
	for(int i=0;i<w1;i++){
		cnt1*=2;
		cnt1+=s1[i]-48;
	}
	return cnt1;
}
string fix(string s2,int x){
	for(int i=0;i<x;i++){
		s2="0"+s2;
	}
	return s2;
}
long long int yh(long long int x,long long int y){
	string s_x=turned2(x);
	string s_y=turned2(y);
	if(s_x.size()>s_y.size()){
		s_y=fix(s_y,s_x.size()-s_y.size());
	}
	if(s_x.size()<s_y.size()){
		s_x=fix(s_x,s_y.size()-s_x.size());
	}
	string ans="";
	int a=s_x.size();
	int b=s_y.size();
	for(int i=0;i<max(a,b);i++){
		if(s_x[i]==s_y[i]){
			ans+="0";
		}else{
			ans+="1";
		}
	}
	return turned10(ans);
}
int a[100010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){ 
		cin>>a[i];
	}
	int cnt=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		cnt=a[i];
		if(a[i]==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			cnt=yh(cnt,a[j]);
			if(cnt==k){
				i=j+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
