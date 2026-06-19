#include<bits/stdc++.h>
using namespace std;
set<string>S;
int T;
int main(){
	freopen("poker.in","r",stdin),freopen("poker.out","w",stdout);
    cin>>T;
    while(T--){
    	string x;
    	cin>>x,S.insert(x);
	}
	cout<<52-S.size();
}
