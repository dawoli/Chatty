#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
char s[N];
int a[N],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	for(int i=1;s[i];i++)
		if('0'<=s[i]&&s[i]<='9')
			a[++n]=s[i]-'0';
	sort(a+1,a+1+n);
	for(int i=n;i;i--)
		printf("%d",a[i]);
	return 0;
}
