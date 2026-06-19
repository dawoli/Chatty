#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		int start=-1;
		for(int j=0;j<x.size();j++){
			if(x[j]==y[j])start=j;
			else break;
		}
		int end=x.size();
		for(int j=x.size()-1;j>=0;j--){
			if(x[j]==y[j])end=j;
			else break;
		}
		for(int j=start+1;j<end;j++){
			a[i]=a[i]+x[j];
			b[i]=b[i]+y[j];
		}
	}
	int ans=0;
	for(int i=1;i<=q;i++){
		ans=0;
		string x,y;
		cin>>x>>y;
		string nowa="";
		string nowb="";
		int start=-1;
		for(int j=0;j<x.size();j++){
			if(x[j]==y[j])start=j;
			else break;
		}
		int end=x.size();
		for(int j=x.size()-1;j>=0;j--){
			if(x[j]==y[j])end=j;
			else break;
		}
		for(int j=start+1;j<end;j++){
			nowa=nowa+x[j];
			nowb=nowb+y[j];
		}
		for(int j=1;j<=n;j++){
			if(a[j]==nowa&&b[j]==nowb)ans++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
