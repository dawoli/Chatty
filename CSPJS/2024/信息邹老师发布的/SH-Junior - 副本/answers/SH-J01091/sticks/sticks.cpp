#include<bits/stdc++.h>
using namespace std;
int m[10],T,n;
string f[100505];
string cmp(string a,string b){
	if(a.size()>b.size())
		return b;
	if(a.size()<b.size())
		return a;
	if(a>b)
		return b;
	return a;	
}
void dp(int n){
	f[0]="",f[1]="",f[2]="1",f[3]="7",f[4]="11",f[5]="2",f[6]="6",f[7]="8",f[8]="10";
	for(int i=9;i<=n;i++)
		f[i]=f[i-6]+'0',f[i]=cmp(f[i],f[i-2]+'1'),f[i]=cmp(f[i],f[i-5]+'2'),f[i]=cmp(f[i],f[i-3]+'7'),f[i]=cmp(f[i],f[i-7]+'8');
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	m[0]=6,m[1]=2,m[2]=5,m[7]=3,m[8]=7;
	dp(100500);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		if(f[n]=="")
			cout<<-1<<endl;
		else
			cout<<f[n]<<endl;
	}
	return 0;
} 
