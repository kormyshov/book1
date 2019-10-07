void sift_up(int *h, int i) {
    int a = h[i];
    while (i > 1)
        if (h[i >> 1] > x) h[i] = h[i >> 1], i >>= 1;
        else break;
    h[i] = a;
}
