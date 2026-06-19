#include<bits/stdc++.h>
using namespace std;

int sa[100000][3]; 
int ptn1=0,ptn2=0,ptn3=0;
long long sum=0;//满意度
int cnt=0;
int n; 
int flo=0;
/*
int check(int flo,int bu){//检查人数是否符合要求(有空间加入 
	if(pstnum[bu]>=flo)
		return 0;
	return 1;
}*/

int find(int cnt,int ptn1,int ptn2,int ptn3)
{
	int x=0,bu,y;//本次要加的数与部 
	if(cnt==n){//最后一个人 
		if(ptn1<flo)
			x=max(x,sa[cnt][0]);
		if(ptn2<flo)
			x=max(x,sa[cnt][1]);
		if(ptn3<flo)
			x=max(x,sa[cnt][2]);
	//	cout<<x<<endl; 
		return x;
	} 
	//当中的人 
	if(ptn1<flo)
		x=sa[cnt][0]+find(cnt+1,ptn1+1,ptn2,ptn3);
		//x=max(x,find(cnt+1,flo))
	if(ptn2<flo)
		x=max(x,sa[cnt][1]+find(cnt+1,ptn1,ptn2+1,ptn3));
	if(ptn3<flo)
		x=max(x,sa[cnt][2]+find(cnt+1,ptn1,ptn2,ptn3+1));
//	cout<<x<<endl;
	return x;
}

void solve()
{
	//int n;//新成员 
	cin>>n;

	flo=n/2;//不能超过的人数 
	//int pstnum[3]={0} ;
	//输入数组 
    //输入
    for(int i=0;i<n;i++){
    	cin>>sa[i][0]>>sa[i][1]>>sa[i][2];
	}
	sum=find(0,0,0,0);
	cout<<sum<<endl;
	//重置 
	ptn1=0;
	ptn2=0;
	ptn3=0;
	sum=0;
	cnt=0;
}

int main(){
	
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
} 
