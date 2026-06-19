#include<bits/stdc++.h>
#define N 100009
using namespace std;
typedef long long ll;
ll T,n;
string f[N];
string s[8]={"0","0","1","7","4","2","6","8"};
string isSmaller(string a,string b){
	if(a.size()<b.size()) return a;
	else if(a.size()>b.size()) return b;
	else{
		if(a<b) return a;
		else return b;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(ll p=1;p<=T;p++){
		cin>>n;
		if(n%7==0) //льеп 
			for(ll i=1;i<=n/7;i++) cout<<8;
		else if(n==1) cout<<-1; //льеп 
		else if(n>1 and n<7) cout<<s[n]; //льеп 
		else if(((n-1)%7)==0 and n>14){
			cout<<10;
			for(ll i=1;i<(n-1)/7;i++) cout<<8;
		}
		else{
			fill(f,f+N,"");
			f[2]="1",f[3]="7",f[4]="4",f[5]="2",f[6]="6",f[7]="8",f[8]="10";
			for(ll i=9;i<=n;i++){
				f[i]=isSmaller(isSmaller(isSmaller(f[i-4]+'4',f[i-7]+'8'),isSmaller(f[i-2]+'1',f[i-6]+'0')),isSmaller(f[i-3]+'7',f[i-5]+'2'));
				//cout<<f[i]<<endl;
			}
			cout<<f[n];
			//for(ll i=1;i<=n;i++) cout<<"f["<<i<<"]="<<f[i]<<endl;
		}
		cout<<endl;
	}
	return 0;
}
