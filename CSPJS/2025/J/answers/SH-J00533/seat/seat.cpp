#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,R_number;//n行(竖) m列(横) 小R的编号 
int score[105],seat[11][11];
bool cmp(int a,int b){
	if(a>=b)
		return 1;
	return 0;
} 
int lower_round(int a,int b){
	return (a-a%b)/b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	memset(score,0,sizeof(score));	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=(n*m);i++)
		scanf("%d",&score[i]);
	//16-18 读入	
	int R_score=score[1];
	sort(score+1,score+(n*m)+1,cmp);
	for(int i=1;i<=(n*m);i++){
		if(score[i]==R_score)
			R_number=i;
	}
	//24-29 数据预处理
	int c,r,temp;//c列 r行 
	if(R_number%n==0){ //特判R在第一行或最后一行 
		c=R_number/n;
		if(c%2==0)
			r=1;
		else
			r=n;
		printf("%d %d",c,r);
		return 0;
	}
	temp=lower_round(R_number,n)+1;
	c=temp;
	if(c%2==0){
		r=n-R_number%n+1;
	}
	if(c%2==1){
		r=R_number%n;
		if(r==0)
			r+=n;
	}
	printf("%d %d",c,r);
	return 0; 
}
