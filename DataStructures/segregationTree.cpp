struct Segtree {
    int lb, rb; // левые и правые границы отрезков
    int s = 0; // сумма на текущем отрезке
    Segtree *l = 0, *r = 0; // указатели на детей (0 означает, что ребенка нет)

    Segtree(int lb, int rb) : lb(lb), rb(rb) {
        if (lb + 1 == rb)
            s = a[lb];
        if (lb + 1 < rb) {  // если не лист, создаем детей
            int t = (lb + rb) / 2;
            l = new Segtree(lb, t);
            r = new Segtree(t, rb);
            s = l->s + r->s;
        } }

    void add(int k, int x) {
        s += x;
        if (l) {  // проверим, есть ли у нас дети:
            if (k < l->rb)  // если k в левой половине
                l->add(k, x);
            else
                r->add(k, x);
        } }

    int sum(int lq, int rq) {
        if (lb >= lq && rb <= rq) // если мы лежим полностью в отрезке запроса
            return s;
        if (max(lb, lq) >= min(rb, rq)) // если мы не пересекаемся с отрезком запроса
            return 0;
        return l->sum(lq, rq) + r->sum(lq, rq);
    }
};
// Main
while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t)
        s.add(x, y);
    else
        cout << s.sum(x, y) << endl;
}