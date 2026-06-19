#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],ans;
bool flagA=1,flagB=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flagA=0;
		if(a[i]!=1&&a[i])flagB=0;
	}
	if(flagA){
		for(int i=2;i<=n;i+=2)ans+=n/i;
		cout<<ans;
		return 0;
	}
	if(n<=10&&flagB){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++){
				int f=j;
				for(int k=j+1;k<=i;k++)
					if(f==a[k])f=0;
					else f=1;
				if(f==k)ans++;
			}
		cout<<ans;
		return 0;
	}
	if(flagB&&n<=100){
		for(int i=1;i<=n;i++){
			int f;
			for(int j=1;j<=i;j++){
				f=j;
				for(int k=j+1;k<=i;k++)
					if(f==a[k])f=0;
					else f=1;
				if(f==k)ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int sum=0,cnt=0;
		for(int j=1;j<=n;j++){
			if(sum==0)sum=a[j];
			else sum=sum^a[j];
			if(sum==k)cnt++,sum=0;
		}
		if(cnt>ans)ans=cnt;
	}
	cout<<ans;
	return 0;
}
