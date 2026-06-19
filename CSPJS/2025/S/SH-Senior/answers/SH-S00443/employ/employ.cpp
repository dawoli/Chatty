#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

int n,m;


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);

	if(m==n){
		int tmp=1;
		char s[505];
		for(int i=1;i<=n;i++){
			scanf("%c",&s[i]);
			if(s[i]=='0'){
				tmp=0;
			}
		}
		printf("%d",tmp);
	}
	return 0;
}
