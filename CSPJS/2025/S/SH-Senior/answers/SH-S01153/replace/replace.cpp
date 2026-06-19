#include<bits/stdc++.h>
using namespace std;
int n,p,q;
string r[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>p;
	for(int i=0;i<n;i++){
		string ax,bx,ay="",by="";
		cin>>ax>>bx;
		for(int j=0;j<ax.size();j++){
			if(ax[j]!=bx[j]){
				ay+=ax[j];
				by+=bx[j];
			}
		}
		r[i][0]=ay;
		r[i][1]=by;
	}
	cin>>q;
	while(q--){
		string zr,ze,rz="",re="";
		cin>>zr>>ze;
		if(zr.size()!=ze.size()) cout<<0;
		else{
			for(int i=0;i<zr.size();i++){
				if(zr[i]!=ze[i]){
					rz+=zr[i];
					re+=ze[i];
				}
			}
			int cnt=0;
			for(int i=0;i<n;i++)
				if(r[i][0]==rz && r[i][1]==re) cnt++;
			cout<<cnt;
		}
	} 
	return 0;
}
