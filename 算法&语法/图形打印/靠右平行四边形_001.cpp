#include<iostream>
using namespace std;
int main()
{ 
    int n;
    cin>>n;
	for(int j=n;j>=1;j--)//j控制行数
    {
        //每一行由空格和星星组成，空格的个数k与行数j有关系
        for(int k=1;k<=j;k++)//k控制每一行的空格数
            cout<<" ";  
        for(int i=1;i<=n;i++)//I控制每一行的星星*数
            cout<<"*";  
        cout<<endl;
    }
    return 0;
}
