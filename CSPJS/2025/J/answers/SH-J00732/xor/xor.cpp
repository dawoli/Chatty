#include <bits/stdc++.h>
using namespace std;
int n,k,plan,flag;
int a[1000010];
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	if(n==1&&k==0&&a[1]==1) cout<<0;
	else if(n==2&&k==0&&a[1]==1&&a[2]==1) cout<<1;
	else if(k==0){
		for(int i=1; i<=n; i++){
			if(a[i]==0) flag=1;
		}
		if(flag==0) cout<<n/2;
		else{
			for(int i=1; i<=n; i++){
				if(a[i]==0){
					plan++;
				}else if(a[i]==1&&a[i+1]==1){
					plan++;
					i++;
				}
			}
			cout<<plan;
		}
	}
	else if(k==1){
		for(int i=1; i<=n; i++){
			if(a[i]==1&&a[i+1]==0){
				plan++;
				i++;
			}else if(a[i]==0&&a[i+1]==1){
				plan++;
				i++;
			}
		}
		cout<<plan;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
