#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define el <<"\n"
#define log(x) cout<<#x<<": "<<x el
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	map<int,int> M;
	for(char c:s){
		if('0'<=c&&c<='9'){
			M[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		rep(j,1,M[i]){
			cout<<i;
		}
	}
	return 0;
}
