#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n;
int solve(int x,int y,int z){
	int r=x,b=y,ans=z,cur1=false,cur2=false,cnt1,cnt2,cnt3;
	for(int i = x+1;i<= n;i++){
		if(a[i]==a[r]){
			ans+=a[r];
			r=0;
		}
		else if(a[i]==a[b]){
			ans+=a[b];
			r=0;
		}
		else if(a[x]==0){
			r=i;
		}
		else if(a[b]==0){
			b=i;
		}
		else{
			cnt1=solve(i,b,ans);
			cnt2=solve(r,i,ans);
			cnt3=solve(r,b,ans);
			if(cnt3<cnt1){
				cur1=true;
			}
			if(cnt3<cnt2){
				cur2=true;
			}
			if(cur1==true&&cur2==true){
				if(cnt1>cnt2){
					ans+=cnt1;
				}
				else{
					ans+=cnt2;
				}
			}
			else if(cur1==true){
				ans+=cnt1;
			}
			else if(cur2==true){
				ans+=cnt2;
			}
			else{
				ans+=cnt3;
			}
			break;
		}
	}
	return ans;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	a[0]=0;
	for(int k = 1;k<= t;k++){
		cin>>n;
		for(int j = 1;j<= n;j++){
			cin>>a[j];
		}
		cout<<solve(1,0,0)<<endl;
	}
	return 0;
}
