#include<iostream>
using namespace std;
int n,k,t,ans,a[500000],ii[500000],jj[500000];bool e[5000000];
bool emp(int i,int j){
	for(int k=i;k<=j;k++)if(e[k]==1)return 0;
	return 1;
}
int fff(int l,int r){
	int ff=a[l];
	for(int i=l+1;i<=r;i++)ff^=a[i];
	return ff;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	    for(int j=i;j<=n;j++)
	    if(fff(i,j)==k){
	    	t++;ii[t]=i;jj[t]=j;
		}
	for(int i=1;i<=t;i++){
		if(emp(ii[i],jj[i])){
			ans++;for(int j=ii[i];j<=jj[i];j++)e[j]=1;
		}
	}
	cout<<ans;
	return 0;
}
