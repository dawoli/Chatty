#include<bits/stdc++.h>
using namespace std;
long long t,n,c1,c2,c3,a[100010],b[100010],c[100010],mx,num,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1,a1,a2,a3;i<=n;i++){
			cin>>a1>>a2>>a3;
			mx=max(a1,max(a2,a3));
			ans+=mx;
			if(mx==a1)a[++c1]=min(a1-a2,a1-a3);
			else if(mx==a2)b[++c2]=min(a2-a1,a2-a3);
			else c[++c3]=min(a3-a1,a3-a2);
		}
		if(c1>n/2){
			sort(a+1,a+1+c1);
			num=c1-n/2;
			for(int i=1;i<=num;i++)ans-=a[i];
		}else if(c2>n/2){
			sort(b+1,b+1+c2);
			num=c2-n/2;
			for(int i=1;i<=num;i++)ans-=b[i];
		}else if(c3>n/2){
			sort(c+1,c+1+c3);
			num=c3-n/2;
			for(int i=1;i<=num;i++)ans-=c[i];
		}
		cout<<ans<<"\n";
		ans=c1=c2=c3=0;
	}
	return 0;
}
