#include<bits/stdc++.h>
using namespace std;
string a[60001];
string b[60001];
int main(){
	int n,q,x=0,y=0,ans=0;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int o[q];
	for(int i=0;i<n;i++){
		cin>>a[i]>>a[i+1];
		x+=2;
	}for(int i=0;i<q;i++){
		cin>>b[i]>>b[i+1];
		y++;
	}for(int i=0;i<=y;i+=2){
		for(int j=0;j<=x;j+=2){
			if((b[i]==a[j] || b[i]==a[j+1]) && (b[i+1]==a[j] || b[i+1]==a[j+1])){
				ans++;
				break;
			}
		}o[i] = ans;
		ans = 0;
	}for(int i=0;i<q;i++){
		cout<<o[i]<<endl;
	}
	return 0;
}
