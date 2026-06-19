#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string chg[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>chg[i][0]>>chg[i][1],chg[i][0]=" "+chg[i][0],chg[i][1]=" "+chg[i][1];
	while(q--){
		string s,t; cin>>s>>t;
		cout<<n<<endl;
	}
	return 0;
}
