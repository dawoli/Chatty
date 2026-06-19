#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=2e5+3;
int rp;
int n,q,ans;
string s[N][2];
int nex[N];
void get(string now){
	int j=0,k=0;
	for(int i=1;i<now.size();i++){
		if(now[i]==now[k]){
			j++;k++;
			nex[i]=k;
		}
		else k=nex[k];
	}
}
int find(string a,string b,int i){
	int j=0;
	while(i<a.size()){
	    if(j>=b.size())return i-b.size();
		if(a[i]==b[j])i++,j++;
		else{
			j=nex[j];
			if(a[i]!=b[j])i++;
		}
	}
	if(j>=b.size())return i-b.size();
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	rp++;
	for(int i=1;i<=n;i++){
		cin>>s[i][0];
		cin>>s[i][1];
	}
	string s1,s2;
	for(int i=1;i<=q;i++){
		cin>>s1;
		cin>>s2;
		for(int j=1;j<=n;j++){
			string now=s[j][0],rep=s[j][1],tmpp=s1;
			get(now);
			int check=find(s1,now,0),len=0;
			while(check>-1){
				for(int k=check;k<check+now.size();k++)tmpp[k]=rep[len++];
				if(tmpp==s2)ans++;
				if(check+now.size()>=s1.size())break;
				check=find(s1,now,check+1);
				tmpp=s1;len=0;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
