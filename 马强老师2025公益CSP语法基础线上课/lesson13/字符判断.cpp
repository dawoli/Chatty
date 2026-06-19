/*
 2个整数数组，想知道里面的元素是否都相等，长度都是n，yes，no 
  5
  1 9 6 3 8
  1 9 6 3 9
5
abcde
abcde
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[101]={},b[101]={};
	int n;
	cin>>n;
	//cin>>a>>b;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	int flag=1;//flag==1,表示相等，==0，表示不相等
//	for(int i=0;i<n;i++){
//		if(a[i]!=b[i]){
//			flag=0;
//			break;
//		}
//	}
	flag=strcmp(a,b);//cmp compare str==string 字符串相等==0字符串比较函数
	if(flag==0) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
