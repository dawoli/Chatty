#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],cnt;
bool specialA=1,specialB=1,use[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(k==1&&a[i]==1){
			cnt++;
		}
		if(k==0){
			if(a[i]==0){
				cnt++;
			}else if(a[i]==a[i-1]&&(!use[i-1])){
				cnt++;
				use[i]=1;
				use[i-1]=1;
			}
		}
		if(a[i]!=1){
			specialA=0;
		}
		if(a[i]!=1&&a[i]!=0){
			specialB=0;
		}
	}
	if(specialA){
		cout<<n/2;
		return 0;
	}else if(specialB){
		cout<<cnt;
		return 0;
	}else if(k==0){
		cout<<cnt;
		return 0;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
