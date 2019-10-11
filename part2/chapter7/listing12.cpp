LL sqm[SN], sqd[SN]; // SN — константа равная корню из N

int sqn;

void build(int *a, int n) {
    sqn = int(sqrt(n + .0)) + 1;
    memset(sqm, 0, sizeof(sqm));
    memset(sqd, 0, sizeof(sqd));
    for (int i = 0; i < n; ++i) sqm[i / sqn] += a[i];
}

void add(int l, int r, int d) {
    int ll = l / sqn, rr = r / sqn, i;
    if (ll == rr) {
        for (i = l; i <= r; ++i) a[i] += d, sqm[ll] += d;
        return ;
    }
    for (i = l; i < (ll + 1) * sqn; ++i) a[i] += d, sqm[ll] += d;
    for (i = rr * sqn; i <= r; ++i) a[i] += d, sqm[rr] += d;
    for (i = ll + 1; i < rr; ++i) sqd[i] += d;
}

LL sum(int l, int r) {
    LL res = 0;
    int ll = l / sqn, rr = r / sqn, i;
    if (ll == rr) {
        for (i = l; i <= r; ++i) res += a[i] + sqd[ll];
        return res;
    }
    for (i = l; i < (ll + 1) * sqn; ++i) res += a[i] + sqd[ll];
    for (i = rr * sqn; i <= r; ++i) res += a[i] + sqd[rr];
    for (i = ll + 1; i < rr; ++i) res += sqm[i] + sqd[i] * sqn;
    return res;
}
