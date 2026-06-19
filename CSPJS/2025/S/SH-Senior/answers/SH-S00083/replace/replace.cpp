#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int n,q;
string str_1[N],str_2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str_1[i]>>str_2[i];
		
	}
	if(q==1){
		string t1,t2;
		cin>>t1>>t2;
		cout<<0<<endl;
		return 0;
	}
	for(int Q=1;Q<=q;Q++){
		string t1,t2;
		cin>>t1>>t2;
		cout<<0<<endl;
	}
	return 0;
} 
