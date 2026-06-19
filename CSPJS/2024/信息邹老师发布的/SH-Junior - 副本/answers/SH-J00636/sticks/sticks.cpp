#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
ll n;
string ans;
map<int,ll> mp;
void init(){
	mp[1]=-1;
	mp[2]=1;
	mp[3]=7;
	mp[4]=4;
	mp[5]=2;
	mp[6]=6;
	mp[7]=8;
	mp[8]=10;
	mp[9]=18;
	mp[10]=22;
	mp[11]=20;
	mp[12]=28;
	mp[13]=68;
	mp[14]=88;
	mp[15]=108;
	mp[16]=188;
	mp[17]=200;
	mp[18]=208;
	mp[19]=288;
	mp[20]=688;
	mp[21]=888;
	mp[22]=1088;
	mp[23]=1888;
	mp[24]=2008;
	mp[25]=2088;
	mp[26]=2888;
	mp[27]=6888;
	mp[28]=8888;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("lld",&t);
	init();
	while(t--){
		scanf("%lld",&n);
		if(n<=28)	cout<<mp[n]<<endl;
		else{
			ll cnt=0;
			while(n>28){
				n-=7;
				cnt++;
			}
			cout<<mp[n];
			while(cnt--){
				cout<<8;
			}
			cout<<endl;
		}
	}
	return 0;
}

