#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int M=1e3+10;
typedef long long ll;
char s[N],a[N];
ll k=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if('0'<=s[i] && s[i]<='9')  a[k++]=s[i];
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=2;i--) cout<<a[i];
	return 0;
} 
