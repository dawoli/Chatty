#include<bits/stdc++.h>
using namespace std;
const int N=300000;
int n,ans=52;
bool exist[N];
int stoint(string s){
	return s[1]*1000+s[0];
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		exist[stoint(s)]=1;
	}
	for(int i=1;i<=N;i++)ans-=exist[i];
	cout<<ans<<endl;
	return 0;
}
