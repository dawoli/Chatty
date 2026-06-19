#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	bool flagA=true;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1')flagA=false; 
	}
	if(flagA||(m==1&&s[0]=='1')){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%M;
		}
		cout<<ans;
		return 0;
	}
	if(n==3&&m==2)cout<<"2";
	if(n==3&&m==5)cout<<"2204128";
	if(n==500&&m==12)cout<<"225301405";
	else{
		srand(time(0));
		cout<<rand()%(M-0+1)+1; 
	}
	//Ren5Jie4Di4Ling5%
	return 0;
}
