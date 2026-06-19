#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n;
int sticks[]={6,2,5,5,4,5,6,3,7,6};
int canBeUse[]={0,1,2,4,6,7,8};
void input(){
    cin>>n;
}
int maxH;
int ans[100000];
bool flag=0;
void dfs(int x,int h){
	if(flag) return;
	if(x<0||x==1||h>maxH) return;
	if(x==0){
		for(int i=0;i<h;i++) cout<<ans[i];
//		printf("h==%d\n",h);
		cout<<endl;
		flag=1;
		return;
	} 
	for(int i=0;i<7;i++){
		if(h==0&&i==0) continue;
		int tmp=x-sticks[canBeUse[i]];
		if(maxH-h-1<tmp/7+(tmp%7!=0)+(tmp%7==1)) continue;
		ans[h]=canBeUse[i];
		dfs(tmp,h+1);
	}
}
void solve(){
	if(n<=1){
		cout<<-1<<endl;
		return;
	}
//	cout<<"SOLVE"<<endl;
	maxH=n/7+(n%7!=0)+(n%7==1);
    dfs(n,0);
    flag=0;
}
bool match1(){
	return n<=20;
//    return 0;
}

void solve1(){
	int tmp[29];
	tmp[1]=-1;
	tmp[2]=1;
	tmp[3]=7;
	tmp[4]=4;
	tmp[5]=2;
	tmp[6]=6;
	tmp[7]=8;
	tmp[8]=10;
	tmp[9]=18;
	tmp[10]=22;
	tmp[11]=20;
	tmp[12]=28;
	tmp[13]=68;
	tmp[14]=88;
	tmp[15]=108;
	tmp[16]=188;
	tmp[17]=228;
	tmp[18]=208;
	tmp[19]=288;
	tmp[20]=688;
	cout<<tmp[n]<<endl;
}
bool match2(){
	return n%7==0;
}
void solve2(){
	for(int i=0;i<n/7;i++) cout<<8;
	cout<<endl;
}
bool match3(){
	return (n-1)%7==0;
}
void solve3(){
//	cout<<"SOLVE3"<<endl;
	cout<<10;
	n-=8;
	for(int i=0;i<n/7;i++) cout<<8;
	cout<<endl;
}
void clear(){
	return;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;cin>>T;
	for(int t=0;t<T;t++){
		input();
	    if(match1()) solve1();
	    else if(match2()) solve2();
	    else if(match3()) solve3();
	    else solve();
	    clear();
	}
	
}

