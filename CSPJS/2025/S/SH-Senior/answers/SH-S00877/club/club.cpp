#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,chosen[150005],minlost[150005],ppl[4],chg[150005],top;
long long ans,lost;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		cin>>n;
		ppl[1]=0;ppl[2]=0;ppl[3]=0;
		for(int i=0;i<=n+1;i++){
			chosen[i]=0;
			minlost[i]=0;
			chg[i]=0;
		}
		lost=0;
		ans=0;
		top=0;
		for(int i=1;i<=n;i++){
			int A,B,C;
			scanf("%d%d%d",&A,&B,&C);
			if(A>=B&&A>=C){
				chosen[i]=1;ppl[1]++;ans+=A;
				if(B>=C){
					minlost[i]=A-B;
				}
				else{
					minlost[i]=A-C;					
				}
			}
			else if(B>=A&&B>=C){
				chosen[i]=2;ppl[2]++;ans+=B;
				if(A>=C){
					minlost[i]=B-A;
				}
				else{
					minlost[i]=B-C;					
				}
			}
			else if(C>=A&&C>=B){
				chosen[i]=3;ppl[3]++;ans+=C;
				if(A>=B){
					minlost[i]=C-A;
				}
				else{
					minlost[i]=C-B;					
				}
			}
		}
		if(ppl[1]>n/2){
			for(int i=1;i<=n;i++){
				if(chosen[i]==1){
					chg[top++]=minlost[i];
				}
			}
			sort(chg,chg+top);
			int ouut=ppl[1]-n/2;
			for(int i=0;i<ouut;i++){
				lost+=chg[i];
			}
		}
		else if(ppl[2]>n/2){
			for(int i=1;i<=n;i++){
				if(chosen[i]==2){
					chg[top++]=minlost[i];
				}
			}
			sort(chg,chg+top);
			int ouut=ppl[2]-n/2;
			for(int i=0;i<ouut;i++){
				lost+=chg[i];
			}		
		}
		else if(ppl[3]>n/2){
			for(int i=1;i<=n;i++){
				if(chosen[i]==3){
					chg[top++]=minlost[i];
				}
			}
			sort(chg,chg+top);
			int ouut=ppl[3]-n/2;
			for(int i=0;i<ouut;i++){
				lost+=chg[i];
			}			
		}
		cout<<ans-lost<<endl;
	}
	return 0;
}
