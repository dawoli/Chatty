#include<bits/stdc++.h>
using namespace std;

int n;
long long ans,cnt;
long long ad[100005][3],mon[1000005];
int shu[1000005],shu2[1000005];


int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>mon[i];
	}
	sort(mon+1,mon+1+n);
	shu[1]=1;
	int op=1;
	for(int i=2;i<=n;i++){
	
//		cout<<op<<","<<i<<"  ";
		if(mon[i]==mon[i-1]){
			shu[op]+=1;
		}else{
			op++;
			shu[op]+=1;
		}
		
	}
	for(int i=1;i<op;i++){
		if(shu[i]<=shu[i+1]){
			shu[i]=0;
		}else{
			shu[i+1]=shu[i];
			shu[i]=0;
		}	
	}
	cout<<shu[op];
//	for(int i=1;i<=n;i++){
//		cout<<mon[i]<<endl;		
//	}
//	for(int i=1;i<=op;i++){
//		cout<<endl<<shu[i]<<" ";		
//	}
	return 0;
}
