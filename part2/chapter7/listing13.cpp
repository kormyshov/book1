LL sqm[SN], sqd[SN];  // SN — константа равная корню из N

int sqn;

void build(int *a, int n) {
    sqn = int(sqrt(n + .0)) + 1;
    memset(sqm, 0, sizeof(sqm));
    for (int i = 0; i < SN; ++i) sqd[i] = NL;  // NL — константа, которой не будут заливаться отрезки
    for (int i = 0; i < n; ++i) sqm[i / sqn] += a[i];
}

void add(int l, int d) {
    int ll = l / sqn;
    if (sqd[ll] != NL) {
        int end = (ll + 1) * sqn;
        for (int i= ll * sqn; i < end; ++i) a[i] = sqd[ll];
        sqm[ll] = sqd[ll] * sqn;
        sqd[ll] = NL;
    }
    a[l] += d;
    sqm[ll] += d;
}

void fill(int l, int r, int d) {
    int ll = l / sqn, rr = r / sqn, i;
    if (sqd[ll] != NL) {
        int end = (ll + 1) * sqn;
        for (i = ll * sqn; i < end; ++i) a[i] = sqd[ll];
        sqm[ll] = sqd[ll] * sqn;
        sqd[ll] = NL;
    }
    if (ll == rr) {
        for (i = l; i <= r; ++i) sqm[ll] += d - a[i], a[i] = d;
        return ;
    }
    if (sqd[rr] != NL) {
        int end = (rr + 1) * sqn;
        for (i = rr * sqn; i < end; ++i) a[i] = sqd[rr];
        sqm[rr] = sqd[rr] * sqn;
        sqd[rr] = NL;
    }
    for (i = l; i < (ll + 1) * sqn; ++i) sqm[ll] += d - a[i], a[i] = d;
    for (i = rr * sqn; i <= r; ++i) sqm[rr] += d - a[i], a[i] = d;
    for (i = ll + 1; i < rr; ++i) sqd[i] = d;
}

LL sum(int l, int r) {
    LL res = 0;
    int ll = l / sqn, rr = r / sqn, i;
    if (ll == rr) {
        if (sqd[ll] != NL) return sqd[ll] * (r - l + 1);
        for (i = l; i <= r; ++i) res += a[i];
        return res;
    }
    for (i = l; i < (ll + 1) * sqn; ++i) res += (sqd[ll] == NL ? a[i] : sqd[ll]);
    for (i = rr * sqn; i <= r; ++i) res += (sqd[rr] == NL ? a[i] : sqd[rr]);
    for (i = ll + 1; i < rr; ++i) res += (sqd[i] == NL ? sqm[i] : sqd[i] * sqn);
    return res;
}
