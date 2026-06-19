#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n,ans=52;
	string a[100],t;
	bool f;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>t;
		f=1;
		for(int j=0;j<=52;++j){
			if(a[j]==t){
				f=0;
				break;
			}
		}
		if(f==1){
			a[i]=t;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
