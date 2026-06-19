#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string sta[n],end[n];
	for(int i=0;i<n;i++) cin>>sta[i]>>end[i];
	for(int qq=0;qq<q;qq++){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			int heads[a.size()-sta[i].size()+1],head=0;
			for(int j=0;j<a.size()-sta[i].size()+1;j++){
				//cout<<strstr(&a[j],&sta[i][0])-&a[j]<<" "<<j<<" ";
				if((strstr(&a[j],&sta[i][0])-&a[j])==0) heads[head]=j,head++;
			}
			//cout<<strstr(&a[0],&sta[i][0])-&a[0]<<" ";
			for(int k=0;k<head;k++){
				string c;
				for(int j=0;j<a.size()-heads[k]-sta[i].size();j++) c+=' ';
				strcpy(&c[0],&a[heads[k]+sta[i].size()]);
				//cout<<c<<" ";
				string d;
				for(int j=0;j<heads[k];j++) d+=a[j];
				for(int j=0;j<end[i].size();j++) d+=' ';
				//cout<<d<<" ";
				strcpy(&d[heads[k]],&end[i][0]);
				//cout<<d<<" ";
				d+=c;
				//cout<<d<<" ";
				if(d==b) ans++;
				//ans++;
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
