#include<iostream>
using namespace std;
int a[20005];
int main(){
	int n,b; //n头牛 书架的高度为b
	cin>>n>>b;
	for(int i=1;i<=n;i++)	
		scanf("%d",&a[i]);//cin>>a[i]; //每头牛的身高
	//降序 sort()  选择  冒泡
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j])	swap(a[i],a[j]);
		}
	}
	int sum=0,i=1; //当前叠成“奶牛塔”的高度
	while(sum<b){
		sum+=a[i];
		i++;
	}
	cout<<i-1;
	return 0;
}
