#include<bits/stdc++.h>
using namespace std;
int n;
string s[60]; 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	} 
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++)
			if(s[i]==s[j])  s[i]="a";
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=="a")  cnt++;
	}
	cout<<52-n+cnt;
	return 0;
}
