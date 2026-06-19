#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int ton[10]={};
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]-'0'<10&&a[i]-'0'>=0){
			ton[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(ton[i]--){
			cout<<i;
		}
	}
	return 0;
} 
