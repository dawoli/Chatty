#include<bits/stdc++.h>
using namespace std;
long long maxn=-1,m,id=-1,a[1000010];
char s[1000010];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[m]=s[i]-'0';
			m++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++){
		cout<<a[i];
	}
	return 0;
}
