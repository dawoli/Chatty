#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int a[N],n;
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++) printf("%d",a[i]);
	return 0;
}
