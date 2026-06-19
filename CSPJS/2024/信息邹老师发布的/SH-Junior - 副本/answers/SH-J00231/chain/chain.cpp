#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,k,q;
		cin>>n>>k>>q;
		int a[100009]={};
		int b[201109]={};
		int r[100009],c[100009];
		long long total=0;
		for(int i=0;i<n;i++){
			int l;
			cin>>l;
			for(int j=0;j<l;j++){
				cin>>b[a[max(0,i-1)]+j];
			}
			a[i]=a[max(0,i-1)]+l+1;
		}
		for(int i=0;i<q;i++){
			cin>>r[i]>>c[i];
		}
		if(k==200000){
			for(int i=0;i<q;i++) cout<<1;
			continue;
		}
		bool flag3=false;
		int dis=0;
		for(int i=0;i<q;i++){
			if(r[i]==1){
				flag3=false;
				dis=0;
				bool flag1=false,flag2=false;
				for(int j=0;j<a[n-1];j++){
					if(b[j]==1){
						flag1=true;
						dis=1;
					}
					if(dis>=k) flag1=false;
					if(b[j]==0) flag1=false,flag2=false;
					if(b[j]==c[i]) flag2=true;
					if(flag1==true&&flag2==true) {
						cout<<1<<endl;
						flag3=true;
						break;
					}
					dis++;
				}
				if(flag3==false) cout<<0<<endl;
			}
			else cout<<0<<endl;
		}
	}
	return 0;
}
