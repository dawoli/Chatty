#include<bits/stdc++.h>
using namespace std;
char shuru[1000010];
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>shuru;
	for(int i=0;i<strlen(shuru);i++){
		if(shuru[i]>='0' && shuru[i]<='9')
			cnt[shuru[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	return 0;
}
