#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000001],top=0;
int main(){
	freopen("number.in","R",stdin);
	freopen("number.out","W",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++top]=s[i]-'0';
		}
	}
	sort(a+1,a+top+1);
	for(int i=top;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
