#include<bits/stdc++.h>
using namespace std;
int n;
string t;
set<string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t;
		s.insert(t);
	}
    cout<<52-s.size()<<endl;
return 0;	    
} 
