#include<bits/stdc++.h>
using namespace std;
bool pokerL[53];
int main(){
	// 草花0+n，黑桃13+n，红桃26+n,方片39+n 
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,need=52,poker;
	cin>>n;
	char poker_id1,poker_id2;
	for(int i=0;i<n;i++){
		cin>>poker_id1>>poker_id2;
		//看扑克的花纹 
		if(poker_id1=='C')
			poker=0;
		else if(poker_id1=='S')
			poker=13;
		else if(poker_id1=='H')
			poker=26;
		else
			poker=39;
		//看扑克的点数 
		if(poker_id2=='T')
			poker+=10;
		else if(poker_id2=='A')
			poker++;
		else if(poker_id2=='J')
			poker+=11;
		else if(poker_id2=='Q')
			poker+=12;
		else if(poker_id2=='K')
			poker+=13;
		else
			poker=poker+(poker_id2-48);
		//存到pokerL列表里 
		pokerL[poker]=true;
	}
	for(int i=1;i<=52;i++){
		if(pokerL[i]) need--;
	}
	cout<<need;
	fclose(stdin);
	fclose(stdout);
} 
