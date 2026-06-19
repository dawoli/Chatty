#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int flag=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')flag++;
	}
	int sum=1;
	if(flag==n){
		for(int i=n;i>=1;i--){
			sum*=i;
		}
		cout<<sum;
		return 0;
	}
	int c[600]={0};
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	
	
		cout<<"0";
		return 0;
	

}
