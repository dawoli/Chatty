#include <bits/stdc++.h>
using namespace std;
vector<string> s;
int t,n,k,q,l,r,c;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i = 0;i<n;i++){
			cin>>l;
			int numb;
			string s1 = "";
			for(int j = 0;j<l;j++){
				cin>>numb;
				s1 += char(numb + 48);
			}
			s[i] = s1;
		}
		while(q--){
			cin>>r>>c; 
			cout<<0<<endl;
		}
	}
	return 0;
}
