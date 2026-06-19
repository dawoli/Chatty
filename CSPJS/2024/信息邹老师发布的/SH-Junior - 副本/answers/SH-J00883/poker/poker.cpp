#include<iostream>
#include<map>
using namespace std;
bool u[52];
int n;
string p;
map<char,int> mp1,mp2;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	mp1['A']=0;mp1['T']=9;mp1['J']=10;mp1['Q']=11;mp1['K']=12;
	mp2['D']=0;mp2['C']=1;mp2['H']=2;mp2['S']=3;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p;
		int k=mp2[p[0]]*13;
		if(p[1]<='9'&&p[1]>='2')k+=p[1]-'1'; 
		else k+=mp1[p[1]]; 
		u[k]=1;
	}
	int sum=0;
	for(int i=0;i<52;i++){
		sum+=u[i];
	}
	cout<<52-sum;
	return 0;
} 
