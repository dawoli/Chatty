#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[210005],b[210005];
int KMP(string x,string y,int tmp){
	int flag,flagg;
	while(1){
		flag=0;flagg=1;
		for(int i=0;i<x.size();i++){
			if(y[i+tmp]!=y[i+tmp+1]){
				flag=1;
			}
			if(i+tmp>=y.size())return 500000000+rand();
			if(x[i]!=y[i+tmp]){
				if(flag==0){
					tmp++;flagg=0;
				}
				else{
					tmp+=i+1;flagg=0;
				}
			}
		}
		if(flagg){
			return tmp;
		}
	}
}
int main(){
	srand((unsigned)time(0));
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<q;i++){
		int ans=0;
		string x,y;cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<endl;continue;
		}
		int l=-1,r=-1;
		for(int j=0;j<x.size();j++){
			if(l==-1&&x[j]!=y[j]){
				l=j;
			}
			if(l!=-1&&x[j]!=y[j]){
				r=j;
			}
		}
		for(int j=0;j<n;j++){
			if(r-l+1>a[j].size()){
				continue;
			}
			if(KMP(a[j],x,l+1-(a[j].size()-(r-l+1)))==KMP(b[j],y,l+1-(b[j].size()-(r-l+1)))){
				ans++;
			}			
		}
		if(ans!=0)cout<<ans+1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
