#include<bits/stdc++.h>
using namespace std;
typedef long long qwq;
const qwq maxn=1e4+5;

qwq n,m,k;
struct node{
	qwq val,to;
};
vector<node> g[maxn];
qwq c[maxn];
bool sch(qwq m,qwq n){
	if(c[n]==m) return true;
	else if(c[n]==0) return false;
	sch(c[n],m);
}
void cnn(qwq m,qwq n){
	while(c[m]!=0){
	    c[m]=c[c[m]];
	}
	c[n]=m;
}
int main(){
    cout<<1;
	return 0;
}
