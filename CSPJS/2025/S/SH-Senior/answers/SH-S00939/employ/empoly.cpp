#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int jiecheng(int x){
	long long cntt=1;
	for(int i=x;i>0;i--)cntt=cntt*x%998244353;
	return cntt;
}
int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	int qikao=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0')qikao++;
		for(int j=0;j<n;j++){
			if(s[i]=='1'&& qikao>=c[i]){
				qikao++;
				s[i]='0';
//				cout<<qikao<<"()"<<i<<endl;
			}
		}
	} 
	if(m==1){
		int cntttt=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1')cntttt++;
//			cout<<s[i]<<"*";
		}
		cout<<cntttt;
	}
	else if(m==n){
		bool qqq=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0')qqq=1;
			if(c[i]==0)qqq=1;
		}
		if(qqq==0)cout<<1;
		else cout<<0;
	} 
	else{
		long long cnt=0;
		cnt=jiecheng(n)/(jiecheng(m)*jiecheng(n-m))%998244353;
		cout<<cnt;
	}
	
	return 0;
} 
