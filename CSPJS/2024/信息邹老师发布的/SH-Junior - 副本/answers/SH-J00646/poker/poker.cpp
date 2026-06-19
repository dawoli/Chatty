#include <bits/stdc++.h>
using namespace std; 
int n,num;
char c[60],s[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>c[i]>>s[i];
		for(int k=1;k<=i;++k){
			if(c[i]==c[i-k]&&s[i]==s[i-k]){
				num++;
			}
		}
		
	}
	if(n==1){
		cout<<"51";
		return 0;
	}
	cout<<52+num-n;
	return 0;
}
