#include<iostream>
using namespace std;
int t,n,k,q;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		int a[200100]={},f=0;
		for(int i=0;i<n;i++){
			int l;
			bool tmp[200100]={};
			cin>>l;
			for(int j=0;j<l;j++){
				int x;
				cin>>x;
				tmp[x]=1;
			}
			for(int j=0;j<200100;j++) {
				a[i]+=tmp[i];
				if(a[i]>=2) f++;
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			if(a[r]>=1&&f>=2&&a[1]&&) cout<<1;
			else cout<<0;
			cout<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
