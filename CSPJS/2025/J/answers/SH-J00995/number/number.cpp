#include<bits/stdc++.h>
using namespace std;
string s;
multiset<int>st;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			st.insert(int(s[i]-48));
		}
	}multiset<int>::iterator it=st.end();
	it--;
	if(*it==0)cout<<0;
	else{
		for(;it!=st.begin();it--)cout<<(*it);
		cout<<*(st.begin());
	} 
	
}
