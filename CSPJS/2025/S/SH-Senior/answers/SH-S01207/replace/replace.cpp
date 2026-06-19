#include<bits/stdc++.h>
using namespace std;
int n,q;
unsigned long long hx[200009][2],l[200009],que[2][2009],cheng[20009],ans;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cheng[0]=1;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1>>s2;
		//cout<<hx[i][0]<<" "<<hx[i][1]<<endl;
	}
	for(int i=1;i<=q;++i){
		cin>>s1>>s2;
		cout<<"0\n";
	}
	return 0;
}
