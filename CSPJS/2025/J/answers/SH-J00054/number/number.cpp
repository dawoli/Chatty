#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[MAXN];
	int b[15]={0};
	scanf("%s",&a);
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
		}
		else continue;
	}
	for(int i=9;i>=0;i--){
		if(b[i]!=0){
			for(int j=1;j<=b[i];j++)printf("%d",i);
		}
	}
	return 0;
} 
