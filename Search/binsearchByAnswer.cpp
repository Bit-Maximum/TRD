int binsearch() {
    sort(coords.begin(), coords.end());
    int l = 0;
    int r = coords.back() - coords[0] + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m)) // Функция для проверки текущего положения
            l = m;
        else
            r = m;
    }
    return l;
}