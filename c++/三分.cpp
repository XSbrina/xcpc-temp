const double EPS=1e-6;
while (r-l>EPS) {
    double mid=l+(r-l)/2;
    if (f(mid-ESP)<f(mid+ESP)) l=mid;
    else r=mid;
}

while (r-l>EPS) {
    double l_mid=l+(r-l)/3;
    double r_mid=r-(r-l)/3;
    if (f(l_mid)<f(r_mid)) l=l_mid;
    else r=r_mid;
}
//整数三分
while (l < r) {
    int mid=l+((r-l)>>1);
    if (f(mid) < f(mid + 1))//找极小值变成>
        l=mid+1;
    else
        r=mid;
}
return l; // 极值点下标