#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 1e5 + 9
vector< pair<int, int> > pnts, cnv_hull(N);
pair<int, int> lftpnt = {INT_MAX, INT_MAX};
int ind = 2;

long long det(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return (long long)x1*y2 + (long long)x2*y3 + (long long)x3*y1 - (long long)x3*y2 - (long long)x2*y1 - (long long)x1*y3;
}

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if(p1 == lftpnt)
        return true;
    if(p2 == lftpnt)
        return false;
    long long det_val = det(lftpnt.first, lftpnt.second, p1.first, p1.second, p2.first, p2.second);
    if(det_val == 0)
        return p1.first < p2.first;
    return det_val > 0;
}

void cnt_cnvhull()
{
    cnv_hull[0] = pnts[0];
    cnv_hull[1] = pnts[1];
    for(int i = 2; i < pnts.size(); i++)
    {
        while(ind > 1 && det(cnv_hull[ind - 2].first, cnv_hull[ind - 2].second, cnv_hull[ind - 1].first, cnv_hull[ind - 1].second, pnts[i].first, pnts[i].second) < 0)
            ind--;
        cnv_hull[ind] = pnts[i];
        ind++;
    }
}

int main()
{
    cin >> n; // number of points on plain (n >= 3)
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y; // coordinates of a point
        pnts.push_back({x, y});
        if(y < lftpnt.second || (y == lftpnt.second && x < lftpnt.first))
            lftpnt = {x, y};
    }
    sort(pnts.begin(), pnts.end(), cmp);
    cnt_cnvhull();
    for(int i = 0; i < ind; i++)
        cout << cnv_hull[i].first << ' ' << cnv_hull[i].second << "\n"; // all points on the convex hull


    return 0;
}
