const int maxN = (int)1e5 + 100;
map <char, int> to[maxN];
int link[maxN];
int len[maxN];
int last = 0;
int sz = 1;

void add_letter(char c) {
    int p = last;
    last = sz++;
    len[last] = len[p] + 1;
    for(; to[p][c] == 0; p = link[p]) {
        to[p][c] = last;
    }
    if (to[p][c] == last) {
        link[last] = 0;
        return;
    }
    int q = to[p][c];
    if (len[q] == len[p] + 1) {
        link[last] = q;
        return;
    }
    int cl = sz++;
    to[cl] = to[q];
    link[cl] = link[q];
    len[cl] = len[p] + 1;
    link[last] = link[q] = cl;
    for (; to[p][c] == q; p = link[p]) {
        to[p][c] = cl;
    }
}
// все состояния [0; sz - 1]
// состояний не больше 2 * n, ребер не больше 3 * n => maxN = 2 * длина строки
// Любой путь из корня( = 0) это подстрока
// в одном состоянии находятся все строки, множество окончаний которых одинаковое
// link[p] - ссылка на минимальную вершину, которая имеет множество окончаний не
// меньше(но неверно, что link[p] < p -> нельзя считать динамики циклом, надо писать дфс)
// есть построить граф link[p] -> p, то получится дерево
// если насчитать f[v] = len[link[v]] + 1, то получим, что в одном состоянии лежат
// строки длины [f[v]; len[v]](и каждая из них входит в строку одинаковое число раз)
