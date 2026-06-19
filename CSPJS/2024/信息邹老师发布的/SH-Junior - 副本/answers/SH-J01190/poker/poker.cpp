#include<bits/stdc++.h>
using namespace std;

int n,ans=52;
string a[60];

int count(string x,string *a){
	int nma=0;
	for(int i=0;i<57;i++){
		if(a[i]==x){
			nma++;
		}
	}
	return nma;
}

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(count(a[i],a)==1){
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
