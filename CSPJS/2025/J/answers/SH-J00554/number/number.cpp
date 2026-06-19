#include <bits/stdc++.h>
using namespace std;
int a[15],k;
char s[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ls=strlen(s);
	for(int i=0;i<ls;++i){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=1;--i){
		if(a[i]==0){
			k++;
			continue;
		}
		for(int j=1;j<=a[i];++j){
			cout<<i;
		}
	}
	if(k==9){
		cout<<"0";
		return 0;
	}
	for(int j=1;j<=a[0];++j){
		cout<<0;
	}
	return 0;
} 
