LL sqm[SN];  // SN — константа равная корню из N
int sqn;
void build(int *a, int n) {
    sqn = int(sqrt(n + .0)) + 1;
    memset(sqm, 127, sizeof(sqm));
    for (int i = 0; i < n; ++i)
        if (sqm[i / sqn] > a[i]) sqm[i / sqn] = a[i];
}

void relax(int i, int d) {
    if (sqm[i / sqn] > d) sqm[i / sqn] = d;
}

int min(int l, int r) {
    int res = INF;
    int ll = l / sqn, rr = r / sqn, i;
    if (ll == rr) {
        for (i = l; i <= r; ++i) if (res > a[i]) res = a[i];
        return res;
    }
    for (i = l; i < (ll + 1) * sqn; ++i) if (res > a[i]) res = a[i];
    for (i = rr * sqn; i <= r; ++i) if (res > a[i]) res = a[i];
    for (i = ll + 1; i < rr; ++i) if (res > sqm[i]) res = sqm[i];
    return res;
}
