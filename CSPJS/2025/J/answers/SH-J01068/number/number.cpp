#include<bits/stdc++.h>
using namespace std;
bool used;
int num[10];
char s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(1){
		s=getchar();
		if(s==10) break;
		if(s>='0'&&s<='9') num[s-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(num[i]&&i>=1) used=1;
		if(num[i]&&i==0&&!used){
			printf("0");
			return 0;
		}
		while(num[i]>0) --num[i],putchar(i+'0');
	}
	printf("\n");
	return 0;
} 
