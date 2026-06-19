#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main(){
	/*思路：
	1.读入数据
	2.设置vector可变长度数组k
	3.依次输入每一张牌
	4.去重
	5.输出结果
	*/
	freopen("poker.in","r",stdin); 
	freopen("poker.out","w",stdout); 
	int a;
	cin>>a;
	vector<string> k;
	string f;
	int flag;
	for(int i=0;i<a;i++){
		cin>>f;
		flag=1;
		for(int j=0;j<k.size();j++){
			if(f==k[j]){
				flag=0;
				break;
			}
		}
		if(flag==1){
			k.push_back(f);
		}
	}
	cout<<52-k.size();
	return 0;
}
