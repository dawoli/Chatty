#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long nums[15]={0};
	char c='0';
	while(c!='\n'){
		scanf("%c",&c);
		if(c>='0'&&c<='9'){
			nums[c-'0'] ++;
		}
	}
	for(int i=9;i>=0;i--){
		for(long long j=0;j<nums[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
