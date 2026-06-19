#include<bits/stdc++.h>
using namespace std;
#define N 101
typedef long long LL;
int n,ans;
vector<string> card;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	ans=52-n;	//假设全部不重复，需要借52张牌 
	string s;	//花色与点数 
	while(n--){
		cin>>s;
		bool flag=false;
		for(string x:card){
			if(s==x){
				flag=true;	//重复 
				break;
			}
		}
		if(flag){	//如果重复 
			ans++;
		}else{
			card.push_back(s);
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4
DQ
H3
DQ
DT

7
D2
D2
D2
D3
D3
D3
H4

52
DA
CA
HA
SA
D2
C2
H2
S2
D3
C3
H3
S3
D4
C4
H4
S4
D5
C5
H5
S5
D6
C6
H6
S6
D7
C7
H7
S7
D8
C8
H8
S8
D9
C9
H9
S9
DT
CT
HT
ST
DJ
CJ
HJ
SJ
DQ
CQ
HQ
SQ
DK
CK
HK
SK
*/
