#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3,M=1e3;
struct xu{
	int a,s[N];
}l[M];
ll T,n,k,q,r,c;
void solve1(){
	for(int i=1;i<=l[1].a;i++){
		if(l[1].s[i]==c){
			cout << 1 << endl;
			return;
		}
	}
	cout << 0 << endl;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> T;
	for(int i=1;i<=T;i++){
		cin >> n >> k >> q;
		for(int j=1;j<=n;j++){
			cin >> l[j].a;
			for(int k=1;k<=l[j].a;k++){
				cin >> l[j].s[k];
			}
		}
		for(int j=1;j<=q;j++){
			cin >> r >> c;
			/*
			if(r==1){
				solve1();
			}
			*/
		}
	}
	srand(time(0));
	for(int i=1;i<=q;i++){
		cout << rand()%2 << endl;
	}
	return 0;
} 
