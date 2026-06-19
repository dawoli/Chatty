#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans,ans2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xot.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int st=a[0],flag=0;;
	if(st==k){
		ans++;
		flag=1;
	}
	for(int i=1;i<n;i++){
		if(flag==1){
			st=a[i];
			i++;
			flag=0;
			if(st==k){
				flag=1;
				ans++;
			}
		}
		if((st^a[i])==k){
			ans++;
			st=a[i+1];
			i++;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			ans2++;
		}
	}
	cout<<max(ans,ans2);
	return 0;
}
