#include<bits/stdc++.h>
using namespace std;
set<string> m; 
string k;
int w;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>w;
	for(int i=0;i<w;i++){
		cin>>k;
		m.insert(k);
	}
	cout<<52-m.size();
	return 0;
}
/*GL@17SXYZ*/
