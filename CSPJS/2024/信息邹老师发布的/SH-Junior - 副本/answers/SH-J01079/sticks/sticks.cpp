#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[10],stick[10]={0,6,2,5,4,6,3,7},c,nu[10]={0,0,1,2,4,6,7,8},ans=0xffff;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ans=0xffff;
		memset(cnt,0,sizeof(cnt));
		cin>>m;
		if(m%7==0) {
			for(int i=1;i<=m/7;i++) cout<<8;
			cout<<endl;
			continue;
		}
		if(m%7==1){
			if(m==1) cout<<-1<<endl;
			else {
				cout<<10;
				m-=8;
				for(int i=1;i<=m/7;i++) cout<<8;
				cout<<endl;
			}
			continue;
		}
		for(int i=1;i<=pow(7,m/7+1);i++){
			int num=0;
			cnt[1]++;
		//cout<<'A'<<" ";
			c=0;
			for(int j=1;j<=7;j++){
				
				if(cnt[j]>7) cnt[j]-=7,cnt[j+1]++;
				c+=stick[cnt[j]];
			}
		//	cout<<c<<" ";
			num=0;
			
			if(c==m){
				bool flag=1;
				for(int j=7;j>=1;j--){
					if(nu[cnt[j]]==0 && j==m/7+1) flag=0;
					num*=10;
					num+=nu[cnt[j]];
				}
		//	cout<<num<<" "<<c<<endl;
			 	if(flag) ans=min(ans,num);
			}
		}
		if(ans!=0xffff)	cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	
}
