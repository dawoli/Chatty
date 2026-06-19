#include<bits/stdc++.h>
using namespace std;
int a[200009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	if(k==1){
		int cnt=0;
		for(int i=0;i<n;i++)if(a[i]==1)cnt++;
		cout<<cnt;
		return 0;
	}
	else if(k==0){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(a[i]==0)cnt++;
			else if(i!=n-1&&a[i]==1&&a[i+1]==1){
				cnt++;i++;
			}
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
