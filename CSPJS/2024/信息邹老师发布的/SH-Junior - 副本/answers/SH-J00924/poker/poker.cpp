#include<bits/stdc++.h>
using namespace std;

int n;
int pp;
string s[55];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string t;
		cin>>t;
		bool f=0;
		for(int j=1;j<=pp;j++){
			if(s[j]==t){
				f=1;
				break;
			}
		}
		if(f==0){
			pp++;
			s[pp]=t;
		}
	}
	cout<<52-pp<<"\n";
	return 0;
}
