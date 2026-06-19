#include<iostream> //1441
using namespace std;
int main(){
	int n;
	cin>>n; //猴子的数量
	bool a[105]={};//0:候选 1:出局
	int i=0,j=0;//i:报数的猴子编号 j:报数的计数器
	int t=n; // t:剩余猴子的数量  (n的值不要发生改变)
	while(t>0){
		i++;
		if(i>n) i=1;
		if(a[i]==0){ //可以报数
			j++;
			if(j==3){
				a[i]=1; //出局
				t--;
				j=0;
			}
		}
	}
	cout<<i;
	return 0;
}
