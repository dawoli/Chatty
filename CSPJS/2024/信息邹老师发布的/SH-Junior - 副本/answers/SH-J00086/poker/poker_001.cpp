#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N=52; 

bool poker[N]={};
void remove(i64 id){
	poker[id]=false;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	for(int i=0;i<N;i++){
		poker[i]=true;
	}
	i64 n;
	cin>>n;
	for(i64 i=1;i<=n;i++){
		char c1,c2;
		cin>>c1>>c2;
		i64 id=0;
		if(c1=='C')id++;
		else if(c1=='H')id+=2;
		else if(c1=='S')id+=3;
		id*=13;
		if(c2>'1'&&c2<='9')id+=((int)c2-'1');
		else if(c2=='T')id+=9;
		else if(c2=='J')id+=10;
		else if(c2=='Q')id+=11;
		else if(c2=='K')id+=12;
		remove(id);		
	}
	i64 cnt=0;
	for(int i=0;i<N;i++){
		if(poker[i])cnt++;
	}
	cout<<cnt;
	return 0;
}

