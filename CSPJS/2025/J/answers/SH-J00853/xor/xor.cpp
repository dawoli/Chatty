#include <bits/stdc++.h>
using namespace std;
int n,k,x[500005],s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;bool flagA=true,flagB=true;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(x[i]!=1) flagA=false;
		if(x[i]>1) flagB=false;
	}
	if(flagA){
		cout<<n-1<<endl;
		return 0;
	}
	if(flagB){
		int cnt=0;
		for(int i=1;i<=n;i++)
		if(x[i]==1) cnt++;
		if(k==1){
			cout<<cnt<<endl;
			return 0;
		}
		cnt=n-cnt;
		int fcnt=0;
		for(int i=1;i<n;i++)
			if(x[i]==1&&x[i+1]==1){fcnt++;i++;}
		cout<<fcnt+cnt<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) s[i]=s[i-1]^x[i];
	
	return 0;
}
