#include<bits/stdc++.h>
using namespace std;
int a[1000005];
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=strlen(s),i,j;
	for(i=0,j=0;i<=l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	for(i=j-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
