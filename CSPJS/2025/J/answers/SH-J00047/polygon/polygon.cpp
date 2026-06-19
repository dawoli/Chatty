#include<iostream>
using namespace std;
int n,ans;
int a[5010],f[5010];
void find(int step,int sum,int maxn){
	if(step==0){
		if(sum>2*maxn) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		bool flag=true;
		for(int j=1;j<=n;j++){
			if(a[i]==f[j]) flag=false;
		}
		if(flag==true) {
			f[i]=a[i];
			find(step-1,sum+a[i],max(maxn,a[i]));
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=5000;i++){
			k[i]=0;
		}
		find(k,0,0);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
}
