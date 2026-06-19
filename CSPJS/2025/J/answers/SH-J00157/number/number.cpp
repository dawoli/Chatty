#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
int k,a[N];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l = s.size();
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++k] = s[i]-48;
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		cout<<a[i];
	}
	return 0;
}
