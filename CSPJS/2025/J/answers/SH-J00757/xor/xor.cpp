#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int x,s=0,c=0;;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(k==x){
			s=0;
			c++;
			continue;
		}
		else s^=x;
		if(s==k){
			s=0,c++;
		}
	} 
	cout<<c;
	return 0;
}
