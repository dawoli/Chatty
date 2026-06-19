#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[1000010];
int num[100],idx=1,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&a);
	n=strlen(a);
	for(int i=0;i<n;i++){
		if('0'<=a[i]&&a[i]<='9')num[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(num[i]--){
			putchar(i+'0');
		}
	}
	return 0;
}
