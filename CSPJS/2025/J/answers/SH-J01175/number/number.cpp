#include<bits/stdc++.h>
using namespace std;

long long cnt[13];

int n;
string st;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin>>st;
	for(int i=0;i<st.size();i++){
		if('0'<=st[i] && st[i]<='9'){
			int k=(st[i]-'0');
			cnt[k]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<cnt[i];j++) cout<<i;
	}
}
