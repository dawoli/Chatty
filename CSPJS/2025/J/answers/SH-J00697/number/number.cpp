#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int n[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int ls = strlen(s+1);
	for(int i = 0;i <= 9;i++)
	     n[i]=0;
    for(int i = 1;i <= ls;i++){
    	if(s[i]>='0'&&s[i]<='9')
    	   n[s[i]-48]++;
	}
	for(int i = 9;i>=0;i--){
		for(int j = 1;j <= n[i];j++)
		    printf("%d",i);
	}
	
	return 0;
} 
