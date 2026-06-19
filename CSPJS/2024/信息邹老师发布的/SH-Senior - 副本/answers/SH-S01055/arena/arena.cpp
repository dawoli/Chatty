#include<bits/stdc++.h>
#define int long long
using namespace std;
int nearest_2k(int x){
	int cnt=0;
	while(x){
		x>>=1;
		cnt+=1;
	}
	if(x==(1<<(cnt-1))) return x;
	return 1<<cnt;
}
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	return 0;
}
