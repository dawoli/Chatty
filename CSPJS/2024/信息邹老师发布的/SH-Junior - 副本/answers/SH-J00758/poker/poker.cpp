#include<bits/stdc++.h>
using namespace std;
string a[105];
int n;
bool cmp(string a,string b){
	return a<b;
}
int ans=1;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			ans++;
		}
	}
	cout<<52-ans<<endl;
	return 0;
}

