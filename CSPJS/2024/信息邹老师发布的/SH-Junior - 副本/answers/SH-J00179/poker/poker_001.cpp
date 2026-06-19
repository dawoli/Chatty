#include<bits/stdc++.h>
using namespace std;
void fr(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
}
map<pair<char,char>,int> ma;
int main(){
	fr();
	int n;
	cin>>n;
	int ans=52;
	for(int i=0;i<n;i++){
		char h,c;
		cin>>h>>c;
		if(ma[make_pair(h,c)]==0)ma[make_pair(h,c)]++,ans--;
		else ma[make_pair(h,c)]++;
	}
	cout<<ans;
	return 0;
}
