#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000009;
ll n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    set<string> st;
	for(ll i=1;i<=n;i++){
		string str; cin>>str;
		st.insert(str);
	} 
	cout<<52-st.size()<<endl;
    return 0;
}
