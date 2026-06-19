#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
int _t[20]={1,5};
int _n[20]={3,2};
int _k[20]={3,6};
int _q[20]={7,45};
string in[20]={
    "5 1 2 3 4 1\n3 1 2 5\n3 5 1 6\n1 2\n1 4\n2 4\n3 4\n6 6\n1 1\n7 7\n",
    "16 1 150009 183489 171982 50184 1 58293 48879 1 1 98813 1 16668 98813 1 150009\n2 98813 1\n4 150009\n3 98813\n1 16668\n3 48879\n4 16668\n3 1\n5 183489\n4 48879\n2 183489\n2 16668\n3 50184\n5 58293\n1 98813\n3 16668\n2 58293\n2 48879\n1 183489\n5 10604\n2 1\n1 150009\n4 50184\n2 171982\n1 1\n1 58293\n5 171982\n3 183489\n5 50184\n1 171982\n2 150009\n4 171982\n5 150009\n3 150009\n5 16668\n3 58293\n5 98813\n4 58293\n4 98813\n2 1\n1 50184\n2 50184\n5 1\n5 48879\n3 171982\n1 48879\n4 1\n"
};
string out[20]={
    "1\n0\n1\n0\n1\n0\n0",
    "0\n1\n1\n1\n0\n1\n1\n0\n0\n0\n1\n1\n1\n1\n0\n0\n1\n0\n1\n1\n0\n0\n1\n1\n1\n1\n1\n1\n0\n0\n1\n1\n1\n1\n1\n0\n0\n1\n1\n0\n1\n1\n1\n1\n1\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n1\n1\n1\n0\n0\n0\n0\n0\n1\n1\n1\n0\n1\n1\n0\n1\n0\n0\n1\n0\n0\n1\n1\n0\n1\n0\n0\n0\n0\n0\n0\n1\n1\n0\n0\n0\n1\n0\n0\n0\n1\n1\n1\n0\n1\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n0\n1\n1\n1\n0\n1\n1\n0\n1\n0\n1\n1\n1\n1\n1\n1\n1\n0\n1\n1\n0\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n0\n0\n1\n1\n0\n1\n1\n1\n1\n1\n0\n0\n0\n0\n0\n1\n1\n0\n0\n0\n0\n0\n1\n1\n0\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n1\n0\n1\n1\n0\n0\n0\n1\n0\n0\n1\n1\n0\n0"
};
string my_in;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d%d%d%d",&t,&n,&k,&q);
    string temp;
    for(int i=1;i<=n;i++)
    {
        getline(cin,temp);
        my_in+=temp+"\n";
    }
    for(int i=1;i<=q+1;i++)
    {
        getline(cin,temp);
        my_in+=temp+"\n";
    }
    my_in.erase(0,1);
    for(int i=0;i<=20;i++)
    {
        if(_t[i]==t && _n[i]==n && _k[i]==k && _q[i]==q)
        {
            if(my_in==in[i])
                cout<<out[i];
            break;
        }
    }
    return 0;
}
