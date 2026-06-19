#include <bits/stdc++.h>
using namespace std;

int n,ans=52;
set<string> poker;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		string card;
		cin>>card;
		poker.insert(card);
	}
	ans=52-poker.size();
	cout<<ans;
	return 0;
} 
