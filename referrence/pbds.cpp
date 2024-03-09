#include <bits/extc++.h>
using namespace __gnu_pbds;
template<typename T>
class ordered_set : public tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {};

ordered_set se;
se.insert(x);
se.erase(y);
se.order_of_key(p); // p보다 작은 원소 개수
se.find_by_order(q); // q+1번째 원소가 있는 iterator

// 주의사항 priority_queue랑 같이 쓰면 터짐 주의 이때는 std::priority_queue<int> 이런식으로 해줘야 안터진다고 함
