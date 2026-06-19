#include<bits/stdc++.h>
#define ll long long
using namespace std;
int attack,total_amount;
int pile_up[100010],answer;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>total_amount;
	for(int i = 0;i < total_amount;i++){
		cin>>attack;
		pile_up[attack]++;
	}
	for(int i = 1;i < 100010;i++){
		answer = max(answer,pile_up[i]);
	}
	cout<<answer;
	return 0;
}

