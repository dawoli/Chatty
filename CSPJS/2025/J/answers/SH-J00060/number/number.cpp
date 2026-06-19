#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010];
int l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int len=strlen(s);
	for(int i=0;i<len;++i){
		if('0'<=s[i]&&s[i]<='9'){
			a[++l]=s[i]-'0';
		}
	}
	sort(a+1,a+l+1);
	for(int i=l;i>=1;--i){
		cout<<a[i];
	}
	return 0;
} 
