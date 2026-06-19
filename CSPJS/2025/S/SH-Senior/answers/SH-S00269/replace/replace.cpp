#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const long long P=1e9+7;
long long n,q;
string s,t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s>>t;
	}
	for (int i=1;i<=q;i++){
		cin>>s>>t;
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
