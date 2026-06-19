#include<bits/stdc++.h>
using namespace std;
int N,M;
int R;
int D;
int A[1000000];
bool cmp(int Q,int W){
	return Q>W;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>N>>M;
	for(int i=1;i<=N*M;i++) cin>>A[i];
	R=A[1];
	sort(A+1,A+N*M+1,cmp);
	int r=1,c=1;
	for(int i=1;i<=N*M;i++){
		if(A[i]==R){
			printf("%d %d\n",r,c);
			return 0;
		}
		if(r%2==1&&c==N) r++;
		else if(r%2==0&&c==1) r++;	
		else if(r%2==1) c++;
		else if(r%2==0) c--;	
	}
	return 0;
}
