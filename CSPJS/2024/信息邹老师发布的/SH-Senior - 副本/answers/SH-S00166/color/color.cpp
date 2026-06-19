#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
int a[maxn];
bool red[maxn];
int n;
int anss=-1;
int sum(){
	int rpre=-1,bpre=-1,ans=0;
	for(int i=1;i<=n;i++){
		if(red[i]){
			if(a[i]==a[rpre]){
				ans+=a[i];
			}
			rpre=i;
		}
		if(!red[i]){
			if(a[i]==a[bpre]){
				ans+=a[i];
			}
			bpre=i;
		}
	}
	return ans;
}
void digui(int i){
	if(i==n){
		anss=max(sum(),anss);
		return;
	}
	for(int j=0;j<=1;j++){
		if(j==0) red[i]=false;
		else red[i]=true;
		digui(i+1);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;cin>>T;
	while(T--){
		anss=-1;
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) cin>>a[i];
		digui(1);
		cout<<anss<<endl;
	}
	return 0;
}

