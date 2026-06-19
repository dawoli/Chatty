#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[1000009];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cur=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[++cur]=s[i]-'0';
		}
	}
	sort(a+1,a+cur+1,cmp);
	for(int i=1;i<=cur;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
} 
