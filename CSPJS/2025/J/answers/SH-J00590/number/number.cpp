#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int ls;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ls=strlen(s);
	for(int i=0;i<ls;++i){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;--i){
		for(int j=1;j<=a[i];++j){
			cout<<i;
		}
	}
	return 0;
}
