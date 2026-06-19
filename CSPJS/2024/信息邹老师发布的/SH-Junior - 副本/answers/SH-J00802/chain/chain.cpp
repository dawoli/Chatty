/*
node{step,purson,number}
queue node will-be-down
{1,p_(1~n),p_(1~n).(1-(1~k-1))}->will-be-down
f[1][1]=true
while(!empty(w-b-d)){
	node top = q.front();q.pop
	{top.step+1,p_(1~n!top.purson),p_(1~n!top.purson).(top.number_adress+(1~k-1))}->w-b-d
	f[top.step+1][p_(1~n!top.purson).(top.number_address+(1~k-1))]=1;
}
return f[r_j][c_j]
*/
#include<bits/stdc++.h>
#include<queue>
using namespace std;
int T,n,k,r[105],c[100005],q,l[100005];
bool f[51][105][100005];
struct node{
	int step,p,num;
}top;
struct{
	int a[100005];
}S[100005];
int main(){
	queue<node>m;
	cin>>T>>n>>k>>q;
	for(int i = 1;i<=n;++i){
		cin>>l[i];
		for(int j = 1;j<=l[i];++j)
			cin>>S[i].a[j];
	}
	for(int i = 1;i<=q;++i)
		cin>>r[i]>>c[i];
	
	return 0;
}

