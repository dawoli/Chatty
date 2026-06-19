#include<bits/stdc++.h>
using namespace std;
struct p{
	long long num,id;
	bool vis;
}A[5010];
long long N,Cnt=0,Ans=0,Maxx=-1,Zid=0,YY=0;
bool ok;
string S[5010];
inline void cha(long long &MAXX){
	for(int i=1;i<=N;i++)
		if(A[i].vis==true){
			MAXX=A[i].num;
			return ;
		}
}
void sol(long long MAXX,int X,long long Cnnt,long long ZID){
	if(X<4) return;
	for(int i=1;i<=N;i++){
		if(A[i].vis==true)
			Cnnt-=A[i].num;
		else
			continue;
		A[i].vis=false;
		cha(MAXX);
		if(Cnnt>MAXX*2)
			Ans++,sol(MAXX,X-1,Cnnt,ZID);
		Cnnt+=A[i].num;
		A[i].vis=true;
	}
}
bool Cmp(p X,p Y){
	return X.num>Y.num;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>A[i].num,Cnt+=A[i].num,A[i].vis=true,A[i].id=i,Zid+=A[i].id;
	sort(A+1,A+N+1,Cmp);
	Maxx=A[1].num;
	if(Cnt>Maxx*2)
		Ans++;
	sol(Maxx,N,Cnt,Zid);
	cout<<Ans;
return 0;
}
