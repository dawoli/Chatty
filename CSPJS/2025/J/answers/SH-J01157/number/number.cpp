#include<bits/stdc++.h>
using namespace std;
int a[2000000],b,n,m;
char s[2000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=s[i]-'0';
			b++;
		}
	}
	sort(a,a+b);
	for(int i=b-1;i>=0;i--){
		cout<<a[i];
	}
}
