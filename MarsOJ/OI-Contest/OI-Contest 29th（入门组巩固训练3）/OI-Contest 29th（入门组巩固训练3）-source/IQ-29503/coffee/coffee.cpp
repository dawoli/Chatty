#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
    int T;
    cin >> T;
    while (T--) {
        int math = 0;
        for (int day = 0; day < 5; ++day) {
            for (int i = 0; i < 8; ++i) {
                string course;
                cin >> course;
                if (course == "math") {
                    ++math;
                }
            }
        }
        long long n, m;
        cin >> n >> m;
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            int weekday = (i + m - 1) % 7 + 1;
            if (weekday >= 1 && weekday <= 5) {
                count += math;
            }
        }

        cout << count << endl;
    }
    return 0;
}

