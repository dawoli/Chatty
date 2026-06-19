#include<bits/stdc++.h>
using namespace std;
int a[15];
char s[1000005];
bool flag=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0' && s[i]<='9'){
			int c=s[i]-'0';
			a[c]++;
		}
	}
	for(int i=9;i>0;i--){
		if(a[i]!=0){
			flag=0;
			break;
		}
	}
	if(flag==1)printf("0\n");
	else{
		for(int i=9;i>=0;i--){
			for(int j=0;j<a[i];j++){
				printf("%c",char(i+'0'));
			}
		}
		printf("\n"); 
	}
	return 0;
}
