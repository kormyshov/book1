LL t[N * 4], ta[N * 4];
int d;

void build(int *a, int n) {
    for (d = 1; d < n; d <<= 1);
    for (int i = 1; i < d + d; ++i) ta[i] = 0;
    for (int i = d; i < d + n; ++i) t[i] = a[i - d];
    for (int i = d + n; i<d+d; ++i) t[i] = 0;
    for (int i = d - 1; i; --i) t[i] = t[i * 2] + t[i * 2 + 1];
}

void add_range(int i, int j, int add, int l = 0, int r = d - 1, int v = 1) {
    if(i == l && j == r) {
        t[v] += add * (r - l + 1LL);
        ta[v] += add;
        return;
    }
    int m = (l + r) >> 1;
    if (i <= m) add_range(i, min(j, m), add, l, m, v * 2);
    if (j > m) add_range(max(i, m + 1), j, add, m + 1, r, v * 2 + 1);
    t[v] = t[v * 2] + t[v * 2 + 1] + ta[v] * (r - l + 1);
}

LL get_sum(int i, int j, int l = 0, int r = d - 1, int v = 1) {
    if(i == l && j == r) return t[v];
    int m = (l + r) >> 1;
    LL res = 0;
    if (i <= m) res += get_sum(i, min(j, m), l, m, v * 2);
    if (j > m) res += get_sum(max(i, m + 1), j, m + 1, r, v * 2 + 1);
    return res + ta[v] * (j - i + 1);
}
