#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int a[N];
int L[N],R[N];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	int sum,cnt=0,pos=1;
	
	for(int l=pos;l<=n;l++){
		for(int r=l;r<=n;r++){
			sum=a[l];
			for(int i=l+1;i<=r;i++){
				
				sum=(sum^a[i]);
			}		
			
			if(sum==k){
				cnt++;//cout<<"["<<l<<","<<r<<"]: "<<sum<<endl;
                pos=r;
                l=pos;
			} 
			sum=0;
		}
		
	}
	int ans=0;

	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
