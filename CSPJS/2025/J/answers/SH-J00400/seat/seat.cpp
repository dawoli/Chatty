#include<bits/stdc++.h>
using namespace std;
int a[110];//<100
bool cmp(int x,int y){
	return x>y;
}//分数高的在前 
int f[30][30];//<100 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n;//行 <10
	int m;//列 <10
	int s;//R <100
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}//输入n*m个学生的分数
	 
	s=a[1];//标记R位置
	sort(a+1,a+n*m+1,cmp);//从高到低排序 
	
	int cnt=1;//现安排第cnt个学生 <n*m=100
	for(int i=1;i<=m;i++){//列 
		if(i%2==1){//单数列 
			for(int j=1;j<=n;j++){//行 
				f[j][i]=a[cnt++];
			}//从上到下 1~n 
		}
		else{//偶数列 
			for(int j=n;j>=1;j--){//行 
				f[j][i]=a[cnt++];
			}//从下到上n~1 
		}
	}//排座位 
	
	for(int i=1;i<=n;i++){//行 
		for(int j=1;j<=m;j++){//列 
			if(f[i][j]==s){//找到这个R 
				cout << j << " " << i;//输出第几列第几行 
			}
		}
	}//找r 
	//时间100
	 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
