#include <bits/stdc++.h>
using namespace std;

bool isPointInCircle(double cx, double cy, double R, double x, double y) {
    double distance = sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y));
    return distance <= R;
}

bool check(double w, double p, double q, double x1, double y1, double x2, double y2) {
    // Check if the path from O to P can be illuminated with radius w
    if (isPointInCircle(x1, y1, w, 0, 0) && isPointInCircle(x1, y1, w, p, q))
        return true;

    if (isPointInCircle(x2, y2, w, p, q) && isPointInCircle(x2, y2, w, 0, 0))
        return true;

      //if origin lie in one ans destination in other
     if( (isPointInCircle(x1,y1,w,p,q) && isPointInCircle(x2,y2,w,0,0)) || (isPointInCircle(x1,y1,w,0,0) && isPointInCircle(x2,y2,w,p,q)))
     {
        double distance=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        
        if(distance<=2*w) return true;
     }

     return false;
}

void solve() {
    double p, q, x1, y1, x2, y2;
    cin >> p >> q >> x1 >> y1 >> x2 >> y2;

    double l = 0, r = 1e9 + 7;
    double ans = 0;

    while (r - l > 1e-9) {
        double mid = l + (r - l) / 2;

        if (check(mid, p, q, x1, y1, x2, y2)) {
            ans = mid;
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
