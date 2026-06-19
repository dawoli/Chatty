#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
string s;
ll n;
ll d[19];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		ll p=s[i]-'0';
		if(0<=p&&p<=9)d[p]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=d[i];j++)cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
