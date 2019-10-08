int mm[logN][N], lgm[N + 1];  // logN — константа, равна логарифму двоичному из N
void build(int *a, int n) {
    for (int i = 0; i < n; ++i) mm[0][i] = a[i];
    for (int j = 1, t = 1; t < n; ++j, t <<= 1)
        for (int i = 0; i + t < n; ++i)
            mm[j][i] = min(mm[j - 1][i], mm[j - 1][i + t]);
    lgm[0] = lgm[1] = 0;
    for (int i = 2; i <= N; ++i) lgm[i] = lgm[i >> 1] + 1;
}

int min(int l, int r) {
    int j = lgm[r - l + 1];
    return (mm[j][l] < mm[j][r + 1 - (1 << j)] ? mm[j][l] : mm[j][r + 1 - (1 << j)]);
}

int min_ind(int l, int r) {
    int i = lgm[r - l + 1];
    if (mm[i][l] > mm[i][r + 1 - (1 << i)]) l = r + 1 - (1 << i);
    for (; i; --i)
        if (mm[i - 1][l] > mm[i - 1][l + (1 << i - 1)]) l += 1 << i - 1;
    return l;
}
