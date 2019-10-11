LL t[N * 2];
int d;

void build(int *a, int n) {
    d = n;
    for (int i = d; i < d + n; ++i) t[i] = a[i - d];
    for (int i = d + n; i < d + d; ++i) t[i] = 0;
    for (int i = d - 1; i; --i) t[i] = t[i * 2] + t[i * 2 + 1];
}

LL get_sum(int l, int r) {
    LL res = 0;
    for (l += d, r += d; l <= r; ++l >>= 1, --r >>= 1) {
        if (l & 1) res += t[l];
        if (~r & 1) res += t[r];
    }
    return res;
}

void add(int i, int val) {
    for (i += d; i; i >>= 1) t[i] += val;
}

int get_pos(LL sum) {
    if (t[1] < sum) return -1;
    int v = 1;
    while (v < d) {
        v <<= 1;
        if (t[v] < sum) sum -= t[v++];
    }
    return v - d;
}
