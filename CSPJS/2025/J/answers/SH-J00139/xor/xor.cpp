#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500001],ans=0,l[500001],r[500001],li=1,ans2=0;
	cin>>n>>k;
//	l[li]=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
//			r[li]=i-1;
//			l[li]=i+1;
//			li++;
		}
	}
//	r[li]=n;
//	for(int i=1;i<=li;i++){
//		for(int j=l[i];j<r[i];j++){
//			if(a[j]|a[j+1]==k){
//				ans2++;
//			}
//		}
//	}
	cout<<ans;
}
