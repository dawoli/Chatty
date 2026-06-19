#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1000009;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=0;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') a[++n]=s[i]-'0';
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		cout<<a[i];
	cout<<endl;
	return 0;
}
