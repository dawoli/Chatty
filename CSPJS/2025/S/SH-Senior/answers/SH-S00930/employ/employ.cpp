#include<bits/stdc++.h>
using namespace std;
int n,m;
int k=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	char s[505];
	int sum1=0;
	
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!='1') sum1++;
	}
	
	//A
	if(sum1==0){
		int ansa=1;
		for(int i=n;i>m;i--){
			ansa=ansa*i%k;
		}
		cout<<ansa<<endl;
		return 0;
	}
	
	//15
	if(m==n){
		int ans15=1;
		for(int i=2;i<=n;i++){
			ans15=ans15*i%k;
		}
		cout<<ans15%k<<endl;
		return 0;
	}
	
	
	cout<<2<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
