#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    unordered_set<string> cards;
    for(int i=0;i<n;++i){
    	string card;
    	cin>>card;
    	cards.insert(card);
	}
	int need=52-cards.size();
	cout<<need<<"\n";
	fclose(stdin);
	fclose(stdout);
    return 0;
}
