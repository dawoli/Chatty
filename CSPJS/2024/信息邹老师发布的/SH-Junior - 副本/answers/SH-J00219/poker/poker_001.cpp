#include<bits/stdc++.h>
using namespace std;
string card[60];
int n,m;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		string s;
		cin>>s;
		bool fl = 1;
		for(int j = 1;j <= m;j++)
			if(s == card[j]) fl = 0;
		if(fl) card[++m] = s;
	}
	cout<<52 - m<<endl;
	return 0;
}

