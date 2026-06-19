#include<bits/stdc++.h>
using namespace std;
struct node{
	string pok;
	int cnt;
}poker[1000100]={{"DA",0},{"D2",0},{"D3",0},{"D4",0},{"D5",0},{"D6",0},{"D7",0},{"D8",0},{"D9",0},{"DT",0},{"DJ",0},{"DQ",0},{"DK",0},{"CA",0},{"C2",0},{"C3",0},{"C4",0},{"C5",0},{"C6",0},{"C7",0},{"C8",0},{"C9",0},{"CT",0},{"CJ",0},{"CQ",0},{"CK",0},{"HA",0},{"H2",0},{"H3",0},{"H4",0},{"H5",0},{"H6",0},{"H7",0},{"H8",0},{"H9",0},{"HT",0},{"HJ",0},{"HQ",0},{"HK",0},{"SA",0},{"S2",0},{"S3",0},{"S4",0},{"S5",0},{"S6",0},{"S7",0},{"S8",0},{"S9",0},{"ST",0},{"SJ",0},{"SQ",0},{"SK",0}};
int main(){
	freopen("poker1.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	string c;
	cin>>n;
	int plus=n;
	for(int i=0;i<n;i++){
		cin>>c;
		for(int j=0;j<52;j++){
			if(poker[j].pok==c){
				poker[j].cnt++;
				if(poker[j].cnt>=2){
					plus--;
				}
			}
		}
	}
	cout<<52-plus;
	return 0;
} 
