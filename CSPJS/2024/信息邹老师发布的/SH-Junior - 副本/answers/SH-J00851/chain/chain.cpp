#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,k,q;
void input(){
    cin>>n>>k>>q;
}
void solve(){
    for(int i=0;i<n;i++) cout<<rand()%2<<endl;
}
bool match1(){
	return 0;
}
void solve1(){
	solve();
}
bool match2(){
	return 0;
}
void solve2(){
	solve();
}
bool match3(){
	return 0;
}
void solve3(){
	solve();
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;cin>>T;srand(time(NULL));
	for(int t=0;t<T;t++){
		input();
	    if(match1()) solve1();
	    else if(match2()) solve2();
	    else if(match3()) solve3();
	    else solve();
	}
	
}

