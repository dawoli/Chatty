#include<bits/stdc++.h>
using namespace std;
int attack(int m[],int len){
    int a=len;
    for(int i=1;i<len;i++){
        for(int j=0;j<i;j++){
            if(m[i]>m[j] && m[j]!=0){
                a--;
                m[j]=0;
                j=i+1;
            }
            if(m[i]<=m[j] && m[j]!=0){
                j=i+1;
            }
        }
    }
    return a;
}
int bubbleSort(int a[],int len){
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int  m[n],m2[n];
    for(int i=0;i<n;i++){
        cin>>m[i];
        m2[i]=m[i];
    }
    bubbleSort(&m[0],n);
    bubbleSort(&m2[0],n);
    cout<<attack(&m[0],n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
