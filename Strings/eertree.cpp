struct node{
    int nxt[26];
    int len;
    int link;
    node() {
        memset(nxt, -1, sizeof nxt);
        len = -1;
        link = -1;
    }
};
string s, q;
const int maxN = 1e6 + 10;
node c[maxN + 10];
int lst;
int sz = 0;
void add_letter(int pos, char p) {
    int state = lst;
    while (state != -1 && q[pos - c[state].len - 1] != p) {
        state = c[state].link;
    }
    assert(state != -1);
    assert(q[pos - c[state].len - 1] == p);
    if (c[state].nxt[p - 'a'] == -1) {
// cout << "HI there " << state << endl;
        int new_node = lst = sz++;
        c[state].nxt[p - 'a'] = new_node;
        c[new_node].len = c[state].len + 2;
        c[state].nxt[p - 'a'] = new_node;
        do {
            state = c[state].link;
        } while (state != -1 && q[pos - c[state].len - 1] != p);
        if (state == -1) {
            c[new_node].link = 1;
        }
        else {
            c[new_node].link = c[state].nxt[p - 'a'];
        }
    }
    else {
        lst = c[state].nxt[p - 'a'];
    }
}
void init() {
    q = "#" + s;
    for (int i = 0; i < q.size() + 4; i++) {
        c[i] = node();
    }
    c[0].len = -1;
    lst = 1;
    c[1].len = 0;
    c[1].link = 0;
    sz = 2;
    for (int i = 1; i < q.size(); i++) {
        add_letter(i, q[i]);
    }
}
// все челы от [0, sz - 1]
// sz <= n + 2, т.е. maxN = длина строки + 10
// link[i] < i, можно писать динамику без дфса, а фориками
// link[i] = наибольший суффиксный палиндром исходного палиндрома
// link["abcba"] = "a", link["aacaa"] = "aa"