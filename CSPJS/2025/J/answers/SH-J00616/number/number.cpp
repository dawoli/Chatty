#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int tmp=s.size();
	for(int i=0;i<tmp;i++){
		if(s[i]>='0'&&s[i]<='9') a[++n]=(int)(s[i]-'0'); 
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) cout<<a[i];
	return 0;
}
