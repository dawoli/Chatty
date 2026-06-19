#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(m[s]!=1){
			num++;
		}
		m[s]=1;
	}
	cout<<52-num<<endl;
	return 0;
}
