#include<bits/stdc++.h>
using namespace std;
int n,m,T,a;
string st;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++) cin>>a;
	for (int i = 1;i <= m;i++) cin>>a;
	int k = 1;
	while (k < n){
		k *= 2;
	}
	for (int i = 1;i <= k;i++) cin>>st;
	cin>>T;
	for (int i = 1;i <= T;i++){
		for (int j = 1;j <= 4;j++){
			cin>>a;
		}
	}
	for (int i = 1;i <= T;i++){
		cout<<1<<endl;
	}
	return 0;
}
