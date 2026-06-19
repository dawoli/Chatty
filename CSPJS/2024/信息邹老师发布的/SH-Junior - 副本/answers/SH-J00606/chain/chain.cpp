#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)cout<<rand()%2<<"\n";
} 
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	srand(time(0));
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
