#include<iostream>
#include<map>
using namespace std;
string pks[]={"DA",  "D2",  "D3",  "D4",  "D5",  "D6",  "D7",  "D8",  "D9",  "DT",  "DJ",  "DQ",  "DK",  "CA",  "C2",  "C3",  "C4",  "C5",  "C6",  "C7",  "C8",  "C9",  "CT",  "CJ",  "CQ",  "CK",  "HA",  "H2",  "H3",  "H4",  "H5",  "H6",  "H7",  "H8",  "H9",  "HT",  "HJ",  "HQ",  "HK",  "SA",  "S2",  "S3",  "S4",  "S5",  "S6",  "S7",  "S8",  "S9",  "ST",  "SJ",  "SQ",  "SK"};
//bool vis[52]={};
map<string, bool> vis;

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	int n=0;
	cin>>n;
	
	int ans=52;
	for(int i=0;i<n;i++){
		string s="";
		cin>>s;
		for(int j=0;j<52;j++){
			if(pks[j]==s){
				if(vis[s]==false){
					ans--;
				}
				vis[s]=true;
				break;
			}
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
