#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<=l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			printf("%d",i);
		}
	}
} 
