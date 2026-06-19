#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],sec[100005],ans,k[100005],top,s[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tmp;
	cin>>tmp;
	while(tmp--){
		int n;
		ans=0;
		cin>>n;
		int numa=0,numb=0,numc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				numa++;
				ans+=a[i];
				sec[i]=a[i]-max(b[i],c[i]);
				k[i]=1;
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				numb++;
				ans+=b[i];
				sec[i]=b[i]-max(a[i],c[i]);
				k[i]=2;
			}else{
				numc++;
				ans+=c[i];
				sec[i]=c[i]-max(a[i],b[i]);
				k[i]=3;
			}
		}
		int num=max(numa,max(numb,numc));
		if(num<=(n/2)){
			cout<<ans<<"\n";
			continue;
		} 
		num-=(n/2);
		int cnt;
		if(numa>(n/2)){
			cnt=1;
		}
		if(numb>(n/2)){
			cnt=2;
		}
		if(numc>(n/2)){
			cnt=3;
		}
		top=0;
		for(int i=1;i<=n;i++){
			if(k[i]==cnt){
				top++;
				s[top]=sec[i];
			}
		}
		sort(s+1,s+top+1);
		for(int i=1;i<=num;i++){
			ans-=s[i];
		}
		cout<<ans<<"\n";
	}	
	return 0;
} 
