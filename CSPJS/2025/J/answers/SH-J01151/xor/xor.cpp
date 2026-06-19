#include<bits/stdc++.h>
using namespace std;
int n,k,a[200010],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i]; 

	if(k==0){
		bool flag=false;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				if(flag){
					cnt++;
					flag=false;
				}
				else{
					flag=true;
				}
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==1)	cnt++;
		} 
	}
	cout<<cnt;
	return 0;
}
