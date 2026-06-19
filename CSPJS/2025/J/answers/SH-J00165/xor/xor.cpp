#include<bits/stdc++.h>
using namespace std;
int n,a[100010],ans,k;
string nor(int x,int y,string ans){
	
	if(x==0&&y==0){
		return ans;
	}
	if((x%2==1&&y%2==1)){
		ans=ans+'0';
	}else{
		ans=ans+'1';
	}
	return nor(x/2,y/2,ans);
}
int zhuan(string x){
	int ans=0;
	for(int i=x.size()-1;i>=0;i--){
		int t=1,u=1,y;
		if(t!=1){
			while(--t){
				u=u*2;
			}
		}
		ans=ans+(int(x[i])-'0')*u;
		
		y++;
		t=y;
	}
	return ans;
}
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int ans1=a[i];
		for(int j=i;j<n;j++){
			ans1=zhuan(nor(ans1,a[j],""));
			if(ans1==k){
				ans++;
				continue;
			}
		}
	}
	cout<<ans<<" ";

	return 0;
};
