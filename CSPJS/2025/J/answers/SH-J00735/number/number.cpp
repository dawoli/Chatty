#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int n;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9')a[n++]=s[i]-'0';
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)printf("%d",a[i]);
	printf("\n");
	return 0;
}
