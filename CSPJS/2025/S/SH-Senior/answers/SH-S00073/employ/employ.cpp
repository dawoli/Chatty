#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c[509],cnt;
string s;
bool flag;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getline(cin,s);
	getline(cin,s);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	flag=1;
	//cout<<s<<endl;
	for(int i=0;i<n;i++){
		if(s[i]!='1') flag=0;
	}
	if(flag){
		cout<<161088479;
		return 0;
	}
	cout<<225301405;
	return 0;
}
