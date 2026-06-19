#include<bits/stdc++.h>
using namespace std;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;string in;
	vector<int> cnt(10,0);
	cin>>in;
	//cout<<in;
	for(int i=0;i<in.size();++i){
		
		if(in[i]>='0'&&in[i]<='9'){
			cnt[in[i]-'0']++;//cout<<"F";
		}
	}
	for(int i=9;i>=0;--i){
		while(cnt[i]>0){
			cout<<i;
			cnt[i]--;
		}
	}
	return 0;
}
