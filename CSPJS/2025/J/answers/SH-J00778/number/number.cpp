#include<bits/stdc++.h>
using namespace std;

const int Maxn=1e6;
string s;
int a[Maxn+5],p;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++p]=s[i]-'0';
	}
	sort(a+1,a+p+1,cmp);
	for(int i=1;i<=p;i++) cout<<a[i];
	return 0;
}
