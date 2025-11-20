int minimum = q.front().first; // Find min
while (!q.empty() && q.back().first > new_element)
    q.pop_back();
q.push_back({new_element, cnt_added});
cnt_added++; // Add new
if (!q.empty() && q.front().second == cnt_removed)
    q.pop_front();
cnt_removed++; // Remove