LL sqm[SN]; // SN — константа равная корню из N
int sqn;

void build(int *a, int n) {
    sqn = int(sqrt(n + .0)) + 1;
    memset(sqm, 0, sizeof(sqm));
    for (int i = 0; i < n; ++i) sqm[i / sqn] += a[i];
}

void add(int i, int d) {
    sqm[i / sqn] += d;
}

LL sum(int l, int r) {
    LL res = 0;
    int ll = l / sqn, rr = r / sqn, i;
    if (ll == rr) {
        for (i = l; i <= r; ++i) res += a[i];
        return res;
    }
    int end = (ll + 1) * sqn;
    for (i = l; i < end; ++i) res += a[i];
    for (i = rr * sqn; i <= r; ++i) res += a[i];
    for (i = ll + 1; i < rr; ++i) res += sqm[i];
    return res;
}
