#include<bits/stdc++.h>
using namespace std;
int D[14],C[14],H[14],S[14],n,cnt=52;
string aa[53];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	cnt-=n;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
		for(int j=1;j<i;j++){
			if(aa[i]==aa[j]){
				cnt++;
			}
		}
	}
//		int wz1;
//		cout<<aa[1]<<" ";
//		if(aa[1]='A') wz1=1;
//		else if(aa[1]='J') wz1=11;
//		else if(aa[1]='Q') wz1=12;
//		else if(aa[1]='K') wz1=13;
//		else if(aa[1]='T') wz1=10;
//		else wz1=aa[1]-48;
//		if(aa[0]='D') D[wz1]++;
//		if(aa[0]='C') C[wz1]++;
//		if(aa[0]='H') H[wz1]++;
//		if(aa[0]='S') S[wz1]++;
//		cout<<wz1<<endl;
//	}
//	for(int i=1;i<=13;i++){
//		if(C[i]) cnt--;
//		if(D[i]) cnt--;
//		if(S[i]) cnt--;
//		if(H[i]) cnt--;
//		cout<<H[i]<<" "<<S[i]<<" "<<C[i]<<" "<<D[i]<<endl;
//	}
	cout<<cnt;
	return 0;
}
//4
//DQ
//H3
//DQ
//DT
