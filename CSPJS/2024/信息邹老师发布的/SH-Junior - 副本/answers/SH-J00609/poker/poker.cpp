#include<bits/stdc++.h>
using namespace std;
map<string,bool> vst;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)cout<<"51";
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			if(!vst[s]){
				cnt++;
				vst[s]=1;
			}
		}
		cout<<52-cnt;
	}
	return 0;
}
