int fend[N], fenu[N];

void build(int *a, int n) {
    memset(fend, 127, sizeof(fend));
    memset(fenu, 127, sizeof(fenu));
    for (int i = n - 1, t = i & (i - 1); i > 0; --i, t = i & (i - 1)) {
        if (fend[i] > a[i]) fend[i] = a[i];
        if (t > 0 && fend[t] > fend[i]) fend[t] = fend[i];
    }
    for (int i = 0, t = i | (i + 1); i < n; ++i, t = i | (i + 1)) {
        if (fenu[i] > a[i]) fenu[i] = a[i];
        if (t < n && fenu[t] > fenu[i]) fenu[t] = fenu[i];
    }
}

void relax(int ii, int d) {
    for (int i = ii; i > 0; i &= i - 1) if (fend[i] > d) fend[i] = d;
    for (int i = ii; i < N; i |= i + 1) if (fenu[i] > d) fenu[i] = d;
}

int min(int l, int r) {
    int res = INF;
    if (!l) {
        for ( ; r >= 0; r = (r + 1 & r) - 1)
            if (res > fenu[r]) res = fenu[r];
        return res;
    }
    for ( ; (r + 1 & r) >= l; r = (r + 1 & r) - 1)
        if (res > fenu[r]) res = fenu[r];
    for ( ; (l - 1 | l) <= r; l = (l - 1 | l) + 1)
        if (res > fend[l]) res = fend[l];
    return res;
}
