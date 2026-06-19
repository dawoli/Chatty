#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string rps[300000][2];


int main(){
    int n, q, t1, t2, ans=0;
    string q1, a1, cpyq, cpya, cpyb;
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i=0;i<n;i++){
        cin >> rps[i][0] >> rps[i][1];
    }
    while (q--){
    	ans =0;
        cin >> q1 >> a1;
        for (int i=0;i<n;i++){
        	t1=t2=0;
        	cpyq = q1;
        	do {
        		t1 = q1.find(rps[i][0], t1);
        		t2 = a1.find(rps[i][1], t2);
//        		cout << t1 << '\t' << t2 << endl;
        		if (t1 == -1 || t2 == -1) break;
        		if (t1 < t2){
        			t1 = t2;
        			t1 = q1.find(rps[i][0], t1);
        			t2 = a1.find(rps[i][1], t2);
				}
				else if (t1 > t2){
					t2 = t1;
        			t1 = q1.find(rps[i][0], t1);
        			t2 = a1.find(rps[i][1], t2);
				}
        		if (t1 == t2) break;
        		t1++, t2++;
			} while (t1 != t2);
        	if (t1 == -1 || t2 == -1) continue;
        	cpyq = cpyq.replace(t1, rps[i][1].size(), rps[i][1]);
        	if (cpyq == a1) ans ++;
//        	cout << cpyq << endl;
		}
		cout << ans << endl;
    }
    
    return 0;
}
