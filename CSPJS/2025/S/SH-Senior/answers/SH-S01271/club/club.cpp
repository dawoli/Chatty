#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		int cnt=0;
		for(int j=1;j<=x;j++){
			if(b[j]!=0) cnt=1;
		}
		if(cnt==0){
			for(int j=1;j<=x;j++){
				for(int k=j+1;k<=x;k++){
					if(a[k]>=a[j]) swap(a[k],a[j]);
				}
			}
			int cnt=0;
			for(int j=1;j<=x/2;j++){
				cnt+=a[j];
			}
			cout<<cnt<<endl;
		}
		for(int i=1;i<=x;i++){
			a[i]=0;
			b[i]=0;
			c[i]=0;
		}
	}
	return 0; 
} 
