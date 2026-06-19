/*
 n  1
n-1 4  x-(x/2+1)=1 x-x/2-1=1 x/2=2
                  x/2=1+1
n-2 10   x-(x/2+1)=4 x-x/2-1=4 x/2=5
                     x/2=4+1
n-3                  x/2=10+1  22 10  
 ..
  1

  第a-1天，(a的桃+1）*2
  4 1   
3   (1+1)*2=4 x-x/2-1=1  x/2=1+1  x=(后一天的桃子+1)*2
  2   (4+1)*2=10  x-x/2-1=4  x/2=4+1 x=(后一天的桃子+1)*2
1   (10+1)*2=22
 */
#include<iostream>
using namespace std;
int main(){
	int n,x=1;cin>>n;
	while(n>=2){
		//cout<<n<<' '<<x<<endl;
		x=(x+1)*2;
		n--;
	}
	cout<<x<<endl;
	return 0;
}
