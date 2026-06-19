#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int n,ans=0;
bool flag=true;
string truepoke[52]={"DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK","CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK","HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK","SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
string inpoke[52]={""};
struct pokers{
	string number;
}poke[54];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>poke[i].number;
		inpoke[i]=poke[i].number;
		for(int k=0;k<i;k++){
			if(poke[i].number==inpoke[k]){
				poke[i].number="";
				break;
			}
		}
		for(int j=0;j<52;j++){
			if(poke[i].number==truepoke[j]&&flag){
				ans++;	
			}
		}
	}
	cout<<52-ans;
	return 0;
}
