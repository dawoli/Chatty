#include<bits/stdc++.h>
using namespace std;
string s;
int a,b,i,j,z[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a=s.size();
	for(i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			z[s[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--){
		for(j=1,b=z[i];j<=b;j++){
			cout<<i;
		}
	}
	return 0;
}
