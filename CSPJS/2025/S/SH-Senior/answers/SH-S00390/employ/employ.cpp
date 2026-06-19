#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=2e5+5;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=1;
	for(int i=0;i<m;i++){
		ans*=(n-i);
		ans%=998244353;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

