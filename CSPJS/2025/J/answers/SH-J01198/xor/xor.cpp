#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+20;
int n,k;
long long a[N];
long long x_1,x_0;
long long man_0,man_1;
long long ans;
void dfs(long long pos,long long m300,long long xen,bool saperate){
	if(pos>n){
		ans=max(m300,ans);
		return;
	}
	//get
	if(saperate==false){
		xen=a[pos];
	}else{
		xen^=a[pos];
	}
	if(xen==k){
		dfs(pos+1,m300+1,1,false);
	}else{
		dfs(pos+1,m300,xen,true);
	}
	//not get
	dfs(pos+1,m300,1,false);
	return;
}
int main(){
	//取消注释!!!!!!!!!!!!!!!!!!!!
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//取消注释!!!!!!!!!!!!!!!!!!!!
	cin>>n>>k;
	bool f_1=false,f_0=true;
	long long pkm=0,pkp=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			x_1++;
			if(f_1==false){
				f_1=true;
			}
			pkm++;
		}else{
			if(f_1==true){
				f_1=false;
				man_1+=pkm/2;
				pkm=0;
			}
		}
		if(a[i]==0){
			x_0++;
			if(f_0==false){
				f_0=true;
			}
			pkp++;
		}else{
			if(f_0==true){
				f_0=false;
				man_0+=pkp/2;
				pkp=0;
			}
		}
	}
	//A
	if(x_1==n&&k==0){
		cout<<n/2;
		return 0;
	}
	//B
	if(x_0+x_1==n&&k<=1){
		if(k==1){
			cout<<x_1+man_0;
		}else{//k==0
			cout<<x_0+man_1;
		}
		return 0;
	}
	//C
	dfs(1,0,1,false);
	cout<<ans;
	return 0;
}
