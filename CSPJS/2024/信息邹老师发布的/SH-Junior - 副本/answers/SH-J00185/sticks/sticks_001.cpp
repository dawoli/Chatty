#include<bits/stdc++.h>
using namespace std;
string d[100009];
int n,T;
string minn(string a,string b){
	if(a=="-1") return b;
	if(b=="-1") return a; 
	if(a[1]=='6') a[1]='0';
	if(b[1]=='6') b[1]='0';
	if(a.size()>b.size()) return b;
	if(a.size()<b.size()) return a;
	else{
		for(int i=0;i<a.size();i++){
			if(a[i]<b[i]) return a;
			if(a[i]>b[i]) return b;
		}
	}
	return a;
} 
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	d[1]="-1";
	d[2]="1";
	d[3]="7";
	d[4]="4";
	d[5]="2";
	d[6]="6";
	d[7]="8";
	for(int i=8;i<=100001;i++){
		d[i]="-1";
		d[i]=minn("1"+d[i-2],d[i]);
		d[i]=minn("7"+d[i-3],d[i]);
		d[i]=minn("4"+d[i-4],d[i]);
		d[i]=minn("2"+d[i-5],d[i]);
		d[i]=minn("6"+d[i-6],d[i]);
		d[i]=minn("8"+d[i-7],d[i]);
		//cout<<i;
	}
	cin>>T;
	while(T--){
		cin>>n;
		cout<<d[n]<<'\n';
	}
	return 0;
}
