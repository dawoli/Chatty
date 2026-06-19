#include<bits/stdc++.h>
using namespace std;
int N,K;
int Ans=0;
int A[10000000];
struct Node{
	int L,R;
}Q[1000000];
int Cnt=0;
bool cmp(Node P,Node O){
	if(P.R==O.R) return P.L>O.L;
    return P.R<O.R;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>N>>K;
	for(int i=1;i<=N;i++) cin>>A[i];
	for(int i=1;i<=N;i++){
		int Now=A[i];
		if(Now==K){
		    Q[++Cnt].L=i;
		    Q[Cnt].R=i;
		    continue;
		}
		for(int j=i+1;j<=N;j++){
			Now^=A[j];
			if(Now==K){
				Q[++Cnt].L=i;
				Q[Cnt].R=j;
				break;
			}
		}
	}
	sort(Q+1,Q+Cnt+1,cmp);
	int Now_R=0;
	for(int i=1;i<=Cnt;i++){
		if(Q[i].L>Now_R){
			Ans++;
			Now_R=Q[i].R;
		}
	}
	printf("%d\n",Ans);
	return 0;
}
