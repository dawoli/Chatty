#include<iostream>
using namespace std;
int a[505]; //存储每艘船的卸货时间
int main(){
	int n;
	cin>>n; // n 艘货船
	for(int i=1;i<=n;i++)	cin>>a[i];
	//sort 冒泡 选择
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j])	swap(a[i],a[j]);
		}
	}
	int sum=0; //货船等候时间之和
	for(int i=1;i<n;i++){
		sum+=a[i];
	}
	cout<<sum;
	return 0;
}
