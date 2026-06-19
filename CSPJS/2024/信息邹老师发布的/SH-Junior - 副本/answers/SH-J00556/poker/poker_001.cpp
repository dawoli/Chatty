#include<bits/stdc++.h>
using namespace std;
int n;
string dian="A23456789TJQK",hua="DCHS";
int shu;
string t;
int cnt=0;
bool vis[100][100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>t;
		char l=t[0],l1=t[1];
		int dis1=-1,dis2=-1;
		for(int i=0;i<dian.size();i++){
			if(dian[i]==l1){
				dis2=i;
				break; 
			}
		}
		for(int i=0;i<hua.size();i++){
			if(hua[i]==l){
				dis1=i;
				break; 
			}
		}
		if(vis[dis1][dis2]==0){
			cnt++;
			vis[dis1][dis2]=1; 
		}
	}
	cout<<52-cnt<<endl;
	return 0;
} 
