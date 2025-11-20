// odd[i] means palindrome starts at i - odd[i] and ends at i + odd[i]
// even[i] means palindrome starts at i - even[i] - 1, and ends at i + even[i] iff even[i] != 0
void manacher(const string &s, vector<int> &odd, vector<int> &even)
{
    int n = s.size();
    odd.clear();
    even.clear();
    odd.resize(n);
    even.resize(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(odd[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        odd[i] = --k;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(even[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        even[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
}