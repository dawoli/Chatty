#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if (s[i]>='0' && s[i]<='9'){
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+1+n);
	for (int i=n;i>=1;i--){
		cout<<a[i];	
	}
	return 0;
}
