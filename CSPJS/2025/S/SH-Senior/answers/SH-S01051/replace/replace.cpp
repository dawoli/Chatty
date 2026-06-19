#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,q,min1,max1,ans;
string qu1[N],qu2[N],ti1[N],ti2[N],k,m;
string find1(string a,string b){
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]&&i<=min1) min1=i;
		if(a[i]!=b[i]) max1=i;
	}
	string c="";
	for(int i=min1;i<=max1;i++) c+=a[i];
	return c;
}
string find3(string a,string b){
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]&&i<=min1) min1=i;                                                   
		if(a[i]!=b[i]) max1=i;
	}
	string d="";
	for(int i=min1;i<=max1;i++) d+=b[i];
	return d;
}
string find2(string a,string b,string c,string d,string e,string f){
	if(a.find(c)==b.find(d)&&a.find(c)<=a.size()&&e.find(a)==f.find(b)&&e.find(a)<=e.size()) return "i";
	return "p";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ti1[i]>>ti2[i];
	}
	for(int i=1;i<=q;i++) cin>>qu1[i]>>qu2[i];
	for(int i=1;i<=q;i++){
		min1=1e9;
		max1=-1;
		ans=0;
		k=find1(qu1[i],qu2[i]);
		m=find3(qu1[i],qu2[i]);
		for(int j=1;j<=n;j++){
			if(find2(ti1[j],ti2[j],k,m,qu1[i],qu2[i])=="i") ans++;
		}
		cout<<ans<<endl;
	}
}
