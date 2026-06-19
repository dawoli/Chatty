#include<bits/stdc++.h>
#define N 200009 
using namespace std;
string a,b;
int n,ans=0,q;
string rep(string x,string y,string z){
	string t1;
	int start=x.find(y);
	int end=x.find(y)+y.length(); 
	for(int i=0;i<start;i++){
		t1=t1+char(x[i]);
	}
	for(int i=start;i<=end;i++){
		t1=t1+char(z[i]);
	}
	for(int i=end+1;i<x.length();i++){
		t1=t1+char(x[i]);
	}
	return t1;
}
bool eq(string a1,string b1){
	for(int i=0;i<a1.length();i++){
		if(a1[i]!=b1[i]) return false;
	}
	return true;
}
string r1[N],r2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>r1[i]>>r2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		ans=0;
		if(a.length()==b.length()){
			for(int j=1;j<=n;j++){
				if(eq(rep(a,r1[j],r2[j]),b)) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}



