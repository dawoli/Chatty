#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

int a[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<'0'||s[i]>'9')continue;
		a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)printf("%d",i);
	}
	
	return 0;
}
