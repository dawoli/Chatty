#include<bits/stdc++.h>
using namespace std;

long long n,m,a[10];
string s;

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
			m=10;
		}
	}
	if(m!=10) cout<<0;
	return 0;
}

