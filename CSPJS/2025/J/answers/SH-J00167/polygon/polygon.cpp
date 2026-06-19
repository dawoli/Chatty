#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polgon.in","r",stdin);
	freopen("polgon.out","w",stdout);
	int n,a[1000000],max=0,rec=0,ans;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	rec=a[1];
	if(a[1]<=a[2]){
		max=a[2];
	}
	else{
		max=a[1];
	}
	if(n<3)cout<<0;
	else{
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]>=max)max=a[j];
			rec+=a[j];	
			}
			if(rec>max*2)ans++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	cout<<ans;
}
