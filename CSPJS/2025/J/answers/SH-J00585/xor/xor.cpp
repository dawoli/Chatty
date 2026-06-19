#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[200050];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		int num=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) num++;
		}
		cout<<num;
	}
	if(k==0){
		int num=0,tmp=1;
		while(tmp<=n){
			if(a[tmp]==0){
				num++;
				tmp++;
			}
			else if(a[tmp]==a[tmp+1]&&tmp<n){
				num++;
				tmp+=2;
			}
			else tmp++;
		}
		cout<<num;
	}
	return 0;
}
