#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n,calc;
int num[10];
char s[maxn];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	scanf("%s",s);
	n = strlen(s);
	for(int i = 0;i < n;i ++){
		if('0' <= s[i] && s[i] <= '9'){
			num[s[i] - '0'] ++;
		}
	}
	for(int i = 9;i >= 0;i --){
		for(int j = 1;j <= num[i];j ++){
			printf("%d",i);
		}
	}
	return 0;
} 
