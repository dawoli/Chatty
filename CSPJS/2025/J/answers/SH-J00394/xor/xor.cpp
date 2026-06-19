#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100001];
	bool f1=false,f2=false;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)
			f1=true;
		if(a[i]!=0&&a[i]!=1)
			f2=true;
	}
	if(f1==true&&f2==false){
		if(k==0){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					sum++;
				}else if(a[i]==1&&a[i+1]==1){
					sum++;
					i++;
				}
			}
			cout<<sum;
			return 0;	
		}
		if(k==1){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)
					sum++;
			}
			cout<<sum;
			return 0;
		}
	}
	if(f1==false&&f2==false){
		if(k==0){
			cout<<n/2;
			return 0;
		}	
	}
	fclose(stdin);
	fclose(stdout);
}
