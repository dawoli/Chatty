#include <iostream>
#include <cstdio>
using namespace std;

int n;
int p[20][10]={0};

int main(){
	
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	/*
	对于输入的数据 存储
	每一种派对应的花色
	统计完每种拍的数量之后
	遍历 获取每一种拍所缺少的
	p[20][10] 
	D 1 C 2 H 3 S 4
	*/
	
	cin>>n;
	for (int i=1;i<=n;i++){
		char hua,num;
		int x,y;
		cin>>hua>>num;
		
		if (hua == 'D')x=1;
		else if (hua == 'C')x=2;
		else if (hua == 'H')x=3;
		else if (hua == 'S')x=4;
		
		if (num>='1' && num<='9')y=num-'0';
		else{
			if (num == 'A')y=1;
			else if (num == 'T')y=10;
			else if (num == 'J')y=11;
			else if (num == 'Q')y=12;
			else if (num == 'K')y=13;
		}
		
		p[y][x]=1;
	}
	
	int cnt=0;
	for (int i=1;i<=13;i++){
		for (int j=1;j<=4;j++){
			if (p[i][j]==0)cnt++;
		}
	}
	
	cout<<cnt<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
