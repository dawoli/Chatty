#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int num[1000001];
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	char c;
	int cnt=0;
	while(cin>>c){
		if('0'<=c && c<='9'){
			cnt++;
			num[cnt]=c-'0';
		}
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}
