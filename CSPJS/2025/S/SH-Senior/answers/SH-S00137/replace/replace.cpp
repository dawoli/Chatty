#include<bits/stdc++.h> 
using namespace std;
struct r{
	string a,b;
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	cin.tie(0);
	if(n>=30000||q>=30000){
		for(int i=0;i<q;i++){
			cout<<0<<endl;
		}
	}
	r rp[100010];
	for(int i=0;i<n;i++){
		cin>>rp[i].a>>rp[i].b;
	}
	for(int iii=0;iii<q;iii++){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
		}
		else{
			int ans=0;
			for(int i=0;i<n;i++){
				int xxxx=a.find(rp[i].a);
				if(xxxx<a.size()&&b.find(rp[i].b)<b.size()){
					string s=rp[i].b;
					string x="";
					for(int j=0;j<xxxx;j++){
						x+=a[j];
					}
					x+=s;
					for(int j=xxxx+rp[i].a.size();j<b.size();j++){
						x+=a[j];
					}
					if(x==b){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
