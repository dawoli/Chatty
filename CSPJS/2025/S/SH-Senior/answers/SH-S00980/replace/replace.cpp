#include<bits/stdc++.h>
using namespace std;
string a[500001],b[500001]; char ta[5000001],tb[5000001];
void compare(string s,string t,int le){
	//ta=""tb="";
	int st=0;
    while(s[st]==t[st]){
			st++;
	}
	int ed=le-1;
	while(s[ed]==t[ed]){
		ed--;
	}
	for(int i=st;i<=ed;i++){
		ta[i-st]=s[i];
		tb[i-st]=t[i];
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		char t1[5000001],t2[5000001];
		cin>>t1>>t2;
		//t1[strlen(t1)]=' ';
		//t2[strlen(t2)]=' ';
		a[i]=t1;
		b[i]=t2;
		compare(a[i],b[i],strlen(t2));
		a[i]=ta;b[i]=tb;
	}
	for(int i=1;i<=q;i++){
		char t1[5000001],t2[5000001];
		cin>>t1>>t2;
		t1[strlen(t1)]=' ';
		t2[strlen(t2)]=' ';
		compare(t1,t2,strlen(t2));
		long long ans=0;
		for(int j=1;j<=n;j++){
			if((a[j]==ta)&&(b[j]==tb))ans++;
			//cout<<ta<<"as"<<endl;
			//cout<<tb<<"as"<<endl;
		}
		cout<<ans<<endl;
	}
}
