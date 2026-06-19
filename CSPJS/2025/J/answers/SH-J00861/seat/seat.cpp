#include<bits/stdc++.h>
using namespace std;
int N,M,X=1,Y=1;
int A[110];
bool Cmp(int S,int T){
	return S>T;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N*M;i++)
		scanf("%d",&A[i]);
	int Nw=A[1];
	int Pos=0;
	sort(A+1,A+N*M+1,Cmp);
	for(int i=1;i<=N*M;i++)
		if(A[i]==Nw){
			Pos=i;
			break;
		}
	X=Pos/N;
	X=(Pos==N*X?X=X:X+=1);
	int New=Pos-(X-1)*N;
	if(X%2==0){
		Y=N;
		while(New>1)
			New--,Y--;
	}
	else{
		Y=1;
		while(New>1)
			New--,Y++;
	}
	cout<<X<<' '<<Y;
return 0;
}

