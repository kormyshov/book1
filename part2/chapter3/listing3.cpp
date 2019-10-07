void sift_up(int *h, int i) {
    int a = h[i];
    while (i > 1)
        if (h[i >> 1] > x) h[i] = h[i >> 1], i >>= 1;
        else break;
    h[i] = a;
}

void sift_down(int *h, int i) {
    int mn, a = h[i];
    while ((i << 1) <= h[0]) {
        mn = i << 1;
        if (mn + 1 <= h[0] && h[mn + 1] < h[mn]) mn++;
        if (h[mn] < a) h[i] = h[mn], i = mn;
        else break;
    }
    h[i] = a;
}

void heap_insert(int *h, int a) {
    h[++h[0]] = a;
    sift_up(h, h[0]);
}

int heap_min(int *h) {
    return h[1];
}

void heap_erase(int *h) {
    h[1] = h[h[0]--];
    sift_down(h, 1);
}

void heap_build(int *h, int *m, int n) {
    memcpy(h + 1, m, sizeof(m) * n);
    h[0] = n;
    for (int i = n >> 1; i; --i) sift_down(h, i);
}
