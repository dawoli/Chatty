#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b) {
	return b<a;
}

/*
5
1 2 3 1 2
---8

10
1 1 1 2 1 1 2 1 1 1
---8
*/

int main () {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    int n,flag=1;
    cin >> n;
    
    int arr[n];int buc[100005];
    for (int i=0;i<n;i++) {
    	cin >> arr[i];
    	if (arr[i]>=3) flag=0;
    	buc[arr[i]] ++;
	}
	if (flag) {
		cout << buc[2]+(buc[1]-buc[2]>0?buc[1]-buc[2]:0);
		return 0;
	}
    sort(arr,arr+n,cmp);
    
    int cnt=0;
    
//    for (int i=0;i<n;i++) cout << arr[i] <<" ";
//    cout << "\n";
    
    for (int i=n-1;i>=0;--i) {
//    	for (int i=0;i<n;i++) cout << arr[i] <<" ";
//        cout << "\n";
    	for (int j=i;j<n;j++) {
    		if (arr[i] >arr[j] && arr[j]!=-1) {
			    arr[j]=-1;
			    cnt++;
			    break;
			}
		}
		if (arr[i]==-1) continue;
	}
		
	
//	for (int i=0;i<n;i++) cout << arr[i] <<" ";
//    cout << "\n";
    
	cout << n-cnt;
    fclose(stdin);
    fclose(stdout);
	return 0;
}

