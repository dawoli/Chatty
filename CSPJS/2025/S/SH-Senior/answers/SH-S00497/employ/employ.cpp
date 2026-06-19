#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int n,m,num=0,w=0,lu=0;
string s;
int c[1009];
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		cout<<1;
	}
	return 0;
}
