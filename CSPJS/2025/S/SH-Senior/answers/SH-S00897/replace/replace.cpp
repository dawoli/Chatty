#include<bits/stdc++.h>
using namespace std;
int N,Q,Ans;string a,b,p,q,ni,nj,li;map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>N>>Q;
	while(N--){
		cin>>a>>b;mp[a]=b;
	}
	while(Q--){Ans=0;
		cin>>p>>q;a=" "+p;b=" "+q;ni=nj="";
		for(int i=0;i<p.length();i++){ni=nj=p[i];
			for(int j=i+1;j<p.length();j++){
				nj+=p[j];
				string nw=li+mp[nj];bool is=1;
				for(int k=j+1;k<p.length();k++){
					nw+=p[k];
				}
//				cout<<i<<" "<<j<<"  "<<nj<<"|"<<mp[nj]<<" :"<<nw<<endl<<"_______"<<endl;;
				if(nw==q)Ans++;
			}li+=p[i];
		}cout<<Ans<<endl;
	}
	return 0;
}
