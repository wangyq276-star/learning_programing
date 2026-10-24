# C++ 常见 STL 使用手册

> 适用对象：正在学习
> C++、已经掌握基础语法并开始学习数据结构与算法的初学者。\
> 建议标准：C++17。文中的大部分内容也适用于 C++11/14。\
> 说明：STL 是 C++
> 标准库中一组常用组件的统称，通常重点学习容器、迭代器、算法和函数对象。

------------------------------------------------------------------------

## 目录

1.  [基本使用方式](#1-基本使用方式)
2.  [常见容器速查](#2-常见容器速查)
3.  [顺序容器](#3-顺序容器)
4.  [关联容器：有序集合与键值对](#4-关联容器有序集合与键值对)
5.  [无序关联容器](#5-无序关联容器)
6.  [容器适配器](#6-容器适配器)
7.  [迭代器](#7-迭代器)
8.  [常用算法 `<algorithm>`](#8-常用算法-algorithm)
9.  [数值算法 `<numeric>`](#9-数值算法-numeric)
10. [字符串与常用工具](#10-字符串与常用工具)
11. [常见组合用法](#11-常见组合用法)
12. [复杂度与选择建议](#12-复杂度与选择建议)
13. [常见错误与注意事项](#13-常见错误与注意事项)
14. [学习顺序建议](#14-学习顺序建议)

------------------------------------------------------------------------

## 1. 基本使用方式

STL 的许多功能都由标准头文件提供。使用前需要包含相应头文件。

``` cpp
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;

int main() {
    vector<int> nums = {4, 2, 7, 1};
    sort(nums.begin(), nums.end());

    for (int x : nums) {
        cout << x << ' ';
    }
    // 输出：1 2 4 7
}
```

### 常用概念

-   **容器（container）**：存放数据，例如 `vector`、`map`。
-   **迭代器（iterator）**：用于遍历或定位容器中的元素，可把它理解为一种通用的"位置标记"。
-   **算法（algorithm）**：处理数据的通用函数，例如
    `sort`、`find`、`reverse`。
-   **函数对象/比较器**：决定算法如何比较元素，例如 `greater<int>()`。
-   **`begin()` / `end()`**：`begin()` 指向第一个元素；`end()`
    指向最后一个元素的下一个位置，**不能解引用 `end()`**。

很多算法采用左闭右开的区间 `[first, last)`：包含 `first`，不包含
`last`。

------------------------------------------------------------------------

## 2. 常见容器速查

  --------------------------------------------------------------------------------------------------------
  容器                   头文件              主要用途           常见特点
  ---------------------- ------------------- ------------------ ------------------------------------------
  `array`                `<array>`           固定长度数组       长度编译期固定，支持迭代器

  `vector`               `<vector>`          动态数组           随机访问快，尾部添加通常很快

  `deque`                `<deque>`           双端队列           两端添加/删除方便

  `list`                 `<list>`            双向链表           已知位置时插入、删除方便，不支持下标访问

  `forward_list`         `<forward_list>`    单向链表           结构更轻量，接口与其他容器略有差异

  `string`               `<string>`          字符串             可修改的字符序列

  `set`                  `<set>`             有序去重集合       元素自动排序，不允许重复

  `multiset`             `<set>`             有序可重复集合     元素自动排序，允许重复

  `map`                  `<map>`             有序键值对         键唯一，按键排序

  `multimap`             `<map>`             有序键值对         同一个键可以出现多次

  `unordered_set`        `<unordered_set>`   无序去重集合       基于哈希，查找平均很快

  `unordered_map`        `<unordered_map>`   无序键值对         基于哈希，键唯一

  `unordered_multiset`   `<unordered_set>`   无序可重复集合     基于哈希，允许重复元素

  `unordered_multimap`   `<unordered_map>`   无序可重复键值对   基于哈希，允许重复键

  `stack`                `<stack>`           后进先出（LIFO）   只操作栈顶

  `queue`                `<queue>`           先进先出（FIFO）   队尾入队、队头出队

  `priority_queue`       `<queue>`           优先队列/堆        默认最大元素优先
  --------------------------------------------------------------------------------------------------------

------------------------------------------------------------------------

## 3. 顺序容器

### 3.1 `vector`：最常用的动态数组

``` cpp
#include <vector>
using namespace std;

vector<int> a;                 // 空 vector
vector<int> b(5);              // 5 个元素，默认初始化为 0
vector<int> c(5, 10);          // 5 个元素，每个都是 10
vector<int> d = {3, 1, 4};     // 初始化列表
```

#### 常用成员函数

  ------------------------------------------------------------------------------------------------
  函数                      作用                       示例
  ------------------------- -------------------------- -------------------------------------------
  `push_back(x)`            在末尾添加元素             `a.push_back(10);`

  `emplace_back(args...)`   在末尾直接构造元素         `v.emplace_back(1, 2);`（元素类型需匹配）

  `pop_back()`              删除末尾元素               `a.pop_back();`

  `size()`                  元素个数                   `a.size()`

  `empty()`                 是否为空                   `a.empty()`

  `clear()`                 清空元素                   `a.clear();`

  `front()` / `back()`      首元素/末元素              `a.front()`

  `at(i)`                   下标访问并进行越界检查     `a.at(0)`

  `operator[]`              下标访问，不检查越界       `a[0]`

  `insert(pos, x)`          在迭代器位置前插入         `a.insert(a.begin(), 8);`

  `erase(pos)`              删除迭代器指向的元素       `a.erase(a.begin());`

  `resize(n)`               调整元素数量               `a.resize(10);`

  `reserve(n)`              预留容量，不改变元素个数   `a.reserve(100);`
  ------------------------------------------------------------------------------------------------

示例：

``` cpp
vector<int> a = {5, 2, 9};
a.push_back(4);
a[0] = 7;

sort(a.begin(), a.end());

for (int x : a) {
    cout << x << ' ';
}
```

**注意：** - `size()` 是当前元素数量；`capacity()`
是当前已分配空间大致可容纳的元素数量。 - `reserve(n)`
不会直接增加元素数量；`resize(n)` 会改变元素数量。 - 对 `vector`
插入或删除元素，可能使某些迭代器、指针和引用失效，尤其是发生重新分配时。 -
`pop_back()` 前要确保容器非空。

### 3.2 `array`：固定长度数组

``` cpp
#include <array>

array<int, 4> a = {3, 1, 4, 2};
sort(a.begin(), a.end());
```

常用函数：`size()`、`empty()`、`front()`、`back()`、`at(i)`、`fill(x)`。

``` cpp
a.fill(0);  // 所有元素设为 0
```

与原生数组相比，`array` 可以直接使用
`size()`、迭代器和标准算法；但长度不能动态改变。

### 3.3 `deque`：双端队列

``` cpp
#include <deque>

deque<int> d;
d.push_back(2);
d.push_front(1);
d.pop_back();
d.pop_front();
```

常用函数：`push_back`、`push_front`、`pop_back`、`pop_front`、`front`、`back`、`size`、`empty`、`operator[]`。

适合需要在两端频繁添加或删除元素的场景。它支持下标访问，但内部结构不等同于连续内存的
`vector`。

### 3.4 `list`：双向链表

``` cpp
#include <list>

list<int> lst = {1, 2, 3};
lst.push_front(0);
lst.push_back(4);

auto it = lst.begin();
++it;                // 移动到第二个元素
lst.insert(it, 99);  // 在该位置前插入
lst.erase(it);       // 删除 it 指向的元素
```

常用函数：`push_front`、`push_back`、`pop_front`、`pop_back`、`insert`、`erase`、`remove(value)`、`sort()`、`reverse()`、`size()`、`empty()`。

**注意：** - `list` 不支持
`lst[i]`，因为链表不能像数组那样直接随机访问。 - `list` 自己有成员函数
`sort()`；不能直接调用 `std::sort(lst.begin(), lst.end())`，因为
`std::sort` 要求随机访问迭代器。 -
已知位置时，链表插入、删除通常很方便；但先找到位置仍可能需要线性遍历。

------------------------------------------------------------------------

## 4. 关联容器：有序集合与键值对

### 4.1 `set`：自动排序且不重复

``` cpp
#include <set>

set<int> s = {4, 2, 4, 1};
// 实际元素为：1, 2, 4

s.insert(3);
s.erase(2);

if (s.find(3) != s.end()) {
    cout << "找到了 3";
}
```

常用函数：

  函数                               作用
  ---------------------------------- ----------------------------------
  `insert(x)`                        插入元素；重复值不会产生第二份
  `erase(x)`                         按值删除
  `find(x)`                          查找元素，找不到返回 `end()`
  `count(x)`                         是否存在；对于 `set` 返回 0 或 1
  `lower_bound(x)`                   第一个不小于 `x` 的元素的位置
  `upper_bound(x)`                   第一个大于 `x` 的元素的位置
  `size()` / `empty()` / `clear()`   数量、判空、清空

`set` 的元素默认按升序排列。标准 `set` 的插入、删除、查找通常为
`O(log n)`。

### 4.2 `multiset`：允许重复的有序集合

``` cpp
multiset<int> ms = {2, 2, 3, 1};
ms.insert(2);

cout << ms.count(2); // 3
```

重要区别：`multiset.erase(value)`
会删除所有等于该值的元素。若只想删除一个：

``` cpp
auto it = ms.find(2);
if (it != ms.end()) {
    ms.erase(it);  // 只删除迭代器指向的一个元素
}
```

### 4.3 `map`：有序键值对

`map<Key, Value>` 可以理解为由"键 -\>
值"组成的容器。键唯一，并按键排序。

``` cpp
#include <map>
#include <string>

map<int, string> students;
students[1001] = "Alice";
students[1002] = "Bob";

cout << students[1001]; // Alice
```

常用函数：

  函数                                      作用
  ----------------------------------------- --------------------------------------
  `m[key]`                                  访问或创建对应键的元素
  `insert({key, value})`                    插入键值对；已有相同键时不会覆盖原值
  `emplace(key, value)`                     尝试原地构造键值对
  `find(key)`                               查找键
  `count(key)`                              键是否存在，返回 0 或 1
  `at(key)`                                 访问已存在的键；键不存在会抛出异常
  `erase(key)`                              按键删除
  `lower_bound(key)` / `upper_bound(key)`   按键查找边界
  `size()` / `empty()` / `clear()`          数量、判空、清空

#### 遍历 `map`

``` cpp
map<string, int> score = {
    {"Tom", 90},
    {"Amy", 95}
};

for (const auto& item : score) {
    cout << item.first << ": " << item.second << '\n';
}
```

-   `item.first` 是键。
-   `item.second` 是值。
-   `const auto&` 可以避免复制键值对，并防止在循环中意外修改它。

C++17 也可以使用结构化绑定：

``` cpp
for (const auto& [name, points] : score) {
    cout << name << ": " << points << '\n';
}
```

#### `map` 的重要陷阱

``` cpp
map<int, int> m;
cout << m[7];
```

这会**创建键 `7`**，并把对应的 `int` 值初始化为 `0`，然后输出
`0`。所以，只想检查键是否存在时，优先使用 `find()` 或
`count()`，不要随意使用 `m[key]`。

### 4.4 `multimap`：允许相同键出现多次

``` cpp
multimap<string, int> scores;
scores.insert({"Tom", 80});
scores.insert({"Tom", 95});

auto range = scores.equal_range("Tom");
for (auto it = range.first; it != range.second; ++it) {
    cout << it->second << '\n';
}
```

`multimap` 不支持 `operator[]`。当一个键需要关联多个值时，可以考虑
`multimap`，或使用 `map<Key, vector<Value>>`。

------------------------------------------------------------------------

## 5. 无序关联容器

### 5.1 `unordered_set`

``` cpp
#include <unordered_set>

unordered_set<int> s = {3, 1, 3, 2};
s.insert(5);

if (s.count(2)) {
    cout << "存在";
}
```

常用函数与 `set`
相似：`insert`、`erase`、`find`、`count`、`size`、`empty`、`clear`。

特点： - 元素不保证按大小排列。 - 查找、插入、删除平均通常为
`O(1)`，最坏情况可能退化。 - 需要有序遍历或 `lower_bound` /
`upper_bound` 时，使用 `set` 更合适。

### 5.2 `unordered_map`

``` cpp
#include <unordered_map>
#include <string>

unordered_map<string, int> frequency;
frequency["apple"]++;
frequency["banana"] += 2;

cout << frequency["apple"]; // 1
```

常用函数：`operator[]`、`at`、`insert`、`emplace`、`find`、`count`、`erase`、`size`、`empty`、`clear`。

#### 统计元素出现次数

``` cpp
vector<int> nums = {1, 2, 1, 3, 2, 1};
unordered_map<int, int> freq;

for (int x : nums) {
    ++freq[x];
}
```

这是一种非常常见的计数方式。若需要按键排序输出，使用
`map`，或者把结果整理后再排序。

------------------------------------------------------------------------

## 6. 容器适配器

容器适配器提供受限的操作接口，常用于栈、队列和堆。它们不是直接遍历所有元素的通用容器。

### 6.1 `stack`：后进先出

``` cpp
#include <stack>

stack<int> st;
st.push(10);
st.push(20);

cout << st.top(); // 20
st.pop();         // 删除栈顶，不返回被删除的值
```

常用函数：`push(x)`、`emplace(...)`、`top()`、`pop()`、`size()`、`empty()`。

适合括号匹配、深度优先搜索的某些写法、表达式处理等场景。

### 6.2 `queue`：先进先出

``` cpp
#include <queue>

queue<int> q;
q.push(10);
q.push(20);

cout << q.front(); // 10
q.pop();           // 删除队头
```

常用函数：`push(x)`、`emplace(...)`、`front()`、`back()`、`pop()`、`size()`、`empty()`。

常用于广度优先搜索（BFS）和按顺序处理任务。

### 6.3 `priority_queue`：优先队列（堆）

默认是**大顶堆**，即最大的元素位于 `top()`。

``` cpp
#include <queue>

priority_queue<int> pq;
pq.push(3);
pq.push(10);
pq.push(5);

cout << pq.top(); // 10
pq.pop();         // 删除最大元素
```

常用函数：`push`、`emplace`、`top`、`pop`、`size`、`empty`。

#### 建立小顶堆

``` cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(5);
minHeap.push(2);
minHeap.push(8);

cout << minHeap.top(); // 2
```

三个模板参数分别是：元素类型、底层容器、比较器。

#### 自定义结构体的优先级

``` cpp
struct Node {
    int id;
    int priority;
};

// priority 数值较小的元素优先
struct Compare {
    bool operator()(const Node& a, const Node& b) const {
        return a.priority > b.priority;
    }
};

priority_queue<Node, vector<Node>, Compare> pq;
```

比较器的规则初学时容易混淆：上述写法让 `priority` 较小的元素先出现在
`top()`。可用简单数据实际测试，确认顺序符合需求。

------------------------------------------------------------------------

## 7. 迭代器

迭代器可以理解为指向容器中某个位置的对象。它让很多算法不必关心容器的内部结构。

### 7.1 基本操作

``` cpp
vector<int> v = {10, 20, 30};

auto it = v.begin();
cout << *it;  // 10，*it 表示访问当前位置的元素

++it;
cout << *it;  // 20

auto finish = v.end(); // 指向末元素之后，不能直接输出 *finish
```

### 7.2 删除元素时更新迭代器

对 `vector`
来说，删除元素后，删除位置及其后面的迭代器可能失效。常见安全写法：

``` cpp
vector<int> v = {1, 2, 3, 2, 4};

for (auto it = v.begin(); it != v.end(); ) {
    if (*it == 2) {
        it = v.erase(it); // erase 返回下一个有效位置
    } else {
        ++it;
    }
}
```

### 7.3 反向迭代器

``` cpp
vector<int> v = {1, 2, 3};

for (auto it = v.rbegin(); it != v.rend(); ++it) {
    cout << *it << ' '; // 3 2 1
}
```

并非所有容器都支持所有种类的迭代器。比如 `vector` 支持随机访问迭代器，而
`list` 不支持随机访问。

------------------------------------------------------------------------

## 8. 常用算法 `<algorithm>`

使用这些算法时，通常需要：

``` cpp
#include <algorithm>
```

### 8.1 排序 `sort`

``` cpp
vector<int> v = {4, 1, 3, 2};
sort(v.begin(), v.end()); // 升序：1 2 3 4
sort(v.begin(), v.end(), greater<int>()); // 降序：4 3 2 1
```

自定义排序：

``` cpp
struct Student {
    string name;
    int score;
};

vector<Student> students = {{"Tom", 80}, {"Amy", 95}};

sort(students.begin(), students.end(),
     [](const Student& a, const Student& b) {
         return a.score > b.score; // 分数从高到低
     });
```

比较器应当建立严格弱序关系。一般不要写成
`a.score >= b.score`，因为相等时比较器不应同时把两者判为"排在前面"。

`std::sort` 通常为 `O(n log n)`，要求随机访问迭代器，适用于
`vector`、`array` 等，不适用于 `list`。

### 8.2 查找 `find`

``` cpp
vector<int> v = {4, 7, 2};
auto it = find(v.begin(), v.end(), 7);

if (it != v.end()) {
    cout << "找到了";
}
```

普通 `find` 对区间逐个检查，时间复杂度通常为 `O(n)`。

### 8.3 二分查找

二分查找相关算法要求区间按相应规则排好序，或至少满足算法要求的分区条件。

``` cpp
vector<int> v = {1, 3, 5, 7, 9};

bool exists = binary_search(v.begin(), v.end(), 5);

auto lo = lower_bound(v.begin(), v.end(), 5); // 第一个 >= 5 的位置
auto hi = upper_bound(v.begin(), v.end(), 5); // 第一个 > 5 的位置
```

常见用途： - `binary_search`：判断元素是否存在。 -
`lower_bound`：找第一个不小于目标值的位置。 -
`upper_bound`：找第一个大于目标值的位置。

对于排序数组中重复值的数量：

``` cpp
auto lo = lower_bound(v.begin(), v.end(), target);
auto hi = upper_bound(v.begin(), v.end(), target);
auto count = hi - lo; // vector 的随机访问迭代器可相减
```

### 8.4 反转与旋转

``` cpp
reverse(v.begin(), v.end());              // 整体反转
rotate(v.begin(), v.begin() + 2, v.end()); // 把前两个元素移到末尾
```

`rotate(first, middle, last)` 会把 `[first, middle)` 移到区间末尾。

### 8.5 最值

``` cpp
auto itMax = max_element(v.begin(), v.end());
auto itMin = min_element(v.begin(), v.end());

if (itMax != v.end()) {
    cout << *itMax;
}
```

`max_element` 和 `min_element`
返回迭代器，而不是直接返回数值。空区间会返回
`end()`，因此使用前要考虑容器是否为空。

### 8.6 计数与判断

``` cpp
int n = count(v.begin(), v.end(), 3);

bool allPositive = all_of(v.begin(), v.end(),
                          [](int x) { return x > 0; });

bool hasEven = any_of(v.begin(), v.end(),
                      [](int x) { return x % 2 == 0; });

bool noneNegative = none_of(v.begin(), v.end(),
                            [](int x) { return x < 0; });
```

### 8.7 去重 `unique`

`unique`
会把相邻重复元素压缩到前面，并返回新的逻辑末尾位置；它本身不会改变容器的实际大小。通常先排序，再使用
erase-remove 惯用法：

``` cpp
vector<int> v = {3, 1, 2, 1, 3, 2};

sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
// v 为 {1, 2, 3}
```

若不先排序，`unique` 只能消除连续重复元素。

### 8.8 删除指定值：erase-remove 惯用法

``` cpp
vector<int> v = {1, 2, 3, 2, 4};
v.erase(remove(v.begin(), v.end(), 2), v.end());
// 删除所有值为 2 的元素
```

这里的 `remove` 不直接缩小容器，而是调整元素并返回新的逻辑末尾；再由
`erase` 真正删除尾部元素。C++20 还提供
`std::erase(v, value)`，但学习传统写法仍然有用。

### 8.9 合并有序区间 `merge`

``` cpp
vector<int> a = {1, 3, 5};
vector<int> b = {2, 4, 6};
vector<int> result;
result.resize(a.size() + b.size());

merge(a.begin(), a.end(),
      b.begin(), b.end(),
      result.begin());
// result 为 1 2 3 4 5 6
```

输入区间必须各自有序，输出区间需要提前准备足够空间。`merge` 不会自动向空
`vector` 中扩展空间；也可以用 `back_inserter(result)` 作为输出迭代器。

### 8.10 其他值得认识的算法

  ------------------------------------------------------------------------------------------
  算法                                作用
  ----------------------------------- ------------------------------------------------------
  `copy(first, last, out)`            复制区间到目标位置

  `fill(first, last, value)`          把区间填成指定值

  `swap(a, b)`                        交换两个对象

  `partition(first, last, pred)`      按条件把元素分成两组

  `stable_sort(...)`                  稳定排序，相等元素保持原有相对顺序

  `nth_element(first, nth, last)`     让第 `nth`
                                      个位置处于排序后应在的位置，左右两侧分别满足分区条件

  `next_permutation(...)`             生成下一个字典序排列

  `clamp(x, low, high)`               将值限制在范围内（C++17）
  ------------------------------------------------------------------------------------------

------------------------------------------------------------------------

## 9. 数值算法 `<numeric>`

### 9.1 求和 `accumulate`

``` cpp
#include <numeric>

vector<int> v = {1, 2, 3, 4};
int sum = accumulate(v.begin(), v.end(), 0); // 10
```

第三个参数是初始值，并且会影响累加结果的类型。求 `int`
数组的更大范围总和时，可使用 `0LL`：

``` cpp
long long sum = accumulate(v.begin(), v.end(), 0LL);
```

### 9.2 其他常用函数

``` cpp
iota(v.begin(), v.end(), 1); // 填入 1, 2, 3, ...
```

  函数              作用
  ----------------- -----------------------------------------
  `accumulate`      累加或按自定义操作累积
  `iota`            按递增规则填充区间
  `inner_product`   计算内积或自定义对应项累积
  `partial_sum`     生成前缀累积结果
  `reduce`          数值归约，C++17；可能以不同顺序组合操作

前缀和示例：

``` cpp
vector<int> a = {1, 2, 3, 4};
vector<int> prefix(a.size());

partial_sum(a.begin(), a.end(), prefix.begin());
// prefix 为 1, 3, 6, 10
```

------------------------------------------------------------------------

## 10. 字符串与常用工具

### 10.1 `string`

``` cpp
#include <string>

string s = "hello";
s += " world";
s.push_back('!');

cout << s.size();
cout << s.substr(0, 5);  // 从下标 0 开始，取 5 个字符
```

常用函数：

  函数                     作用
  ------------------------ -------------------------------------
  `size()` / `length()`    字符串长度
  `empty()`                是否为空
  `operator[]` / `at(i)`   访问字符
  `append()` / `+=`        拼接
  `push_back(ch)`          末尾添加字符
  `pop_back()`             删除末尾字符
  `substr(pos, len)`       截取子串
  `find(sub)`              查找子串，找不到返回 `string::npos`
  `erase(pos, len)`        删除一段字符
  `insert(pos, sub)`       在位置插入内容
  `clear()`                清空

``` cpp
string s = "algorithm";
size_t pos = s.find("go");

if (pos != string::npos) {
    cout << pos;
}
```

### 10.2 `pair`

`pair` 用来把两个值组合在一起：

``` cpp
#include <utility>

pair<int, string> p = {1001, "Alice"};
cout << p.first << ' ' << p.second;
```

也常用于存放坐标、键值、算法结果等。C++17 可以使用：

``` cpp
auto [id, name] = p;
```

### 10.3 `tuple`

当需要组合三个或更多值时，可以使用 `tuple`：

``` cpp
#include <tuple>

tuple<int, string, double> t = {1, "Tom", 88.5};
cout << get<0>(t); // 1
```

### 10.4 `auto` 与范围 `for`

``` cpp
vector<int> v = {1, 2, 3};

for (auto x : v) {
    // x 是元素的副本；修改 x 不会改动容器
}

for (auto& x : v) {
    // x 是元素的引用；可以修改容器中的元素
}

for (const auto& x : v) {
    // 不复制元素，也不允许通过 x 修改元素；适合只读遍历
}
```

初学时遍历大型对象或键值对，常用 `const auto&` 以减少不必要的复制。

------------------------------------------------------------------------

## 11. 常见组合用法

### 11.1 统计频率并按键排序

``` cpp
vector<int> nums = {4, 2, 4, 3, 2, 4};
map<int, int> freq;

for (int x : nums) {
    ++freq[x];
}

for (const auto& [value, count] : freq) {
    cout << value << " 出现 " << count << " 次\n";
}
```

### 11.2 排序后删除重复元素

``` cpp
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

### 11.3 用 `unordered_map` 统计单词

``` cpp
vector<string> words = {"cat", "dog", "cat"};
unordered_map<string, int> freq;

for (const string& word : words) {
    ++freq[word];
}
```

### 11.4 用 `priority_queue` 每次取最大值

``` cpp
priority_queue<int> pq;
for (int x : vector<int>{4, 1, 8, 2}) {
    pq.push(x);
}

while (!pq.empty()) {
    cout << pq.top() << ' ';
    pq.pop();
}
// 输出：8 4 2 1
```

### 11.5 组合 `vector` 和二分查找

``` cpp
vector<int> v = {1, 3, 3, 3, 7, 9};
auto first = lower_bound(v.begin(), v.end(), 3);
auto last = upper_bound(v.begin(), v.end(), 3);

cout << (last - first); // 3 个元素等于 3
```

------------------------------------------------------------------------

## 12. 复杂度与选择建议

以下为常见典型复杂度；具体情况与操作、迭代器类型、元素类型及实现有关。

  ---------------------------------------------------------------------------------
  容器/操作                               典型复杂度 说明
  --------------------- ---------------------------- ------------------------------
  `vector[i]`                                 `O(1)` 随机访问

  `vector` 尾部                          均摊 `O(1)` 扩容时可能需要搬移元素
  `push_back`                                        

  `vector`                                    `O(n)` 后续元素需要移动
  中间插入/删除                                      

  `deque` 两端插入/删除                       `O(1)` 不保证连续内存

  `list`                                      `O(1)` 查找位置的时间另算
  已知位置插入/删除                                  

  `set` / `map`                           `O(log n)` 有序树结构
  查找、插入、删除                                   

  `unordered_set` /                      平均 `O(1)` 最坏可能为 `O(n)`
  `unordered_map` 查找                               

  `priority_queue`                            `O(1)` `top()`
  取堆顶                                             

  `priority_queue`                        `O(log n)` `push()` / `pop()`
  插入/删除堆顶                                      

  `sort`                           通常 `O(n log n)` 需要随机访问迭代器

  `find`                                      `O(n)` 一般线性查找

  有序 `vector`                           `O(log n)` 比较次数；随机访问下效率最好
  上的二分查找                                       
  ---------------------------------------------------------------------------------

### 选择容器的简单规则

-   **需要动态数组、经常按下标访问**：优先考虑 `vector`。
-   **需要键值对，且希望按键排序**：使用 `map`。
-   **需要键值对，且主要关注快速查找，不需要排序**：使用
    `unordered_map`。
-   **需要自动排序且去重**：使用 `set`。
-   **需要频繁获取当前最大/最小优先级元素**：使用 `priority_queue`。
-   **需要先进先出处理**：使用 `queue`。
-   **需要后进先出处理**：使用 `stack`。
-   **需要两端频繁添加/删除**：考虑 `deque`。
-   **需要链表特性，并且会利用已知迭代器位置频繁插入/删除**：考虑
    `list`。

一般情况下，先掌握
`vector`、`string`、`map`、`unordered_map`、`set`、`queue`、`stack`、`priority_queue`
和常见算法，就足以应对大量入门题目。

------------------------------------------------------------------------

## 13. 常见错误与注意事项

1.  **忘记包含头文件**：使用 `vector` 要包含 `<vector>`，使用 `sort`
    要包含 `<algorithm>`。
2.  **把 `end()` 当作最后一个元素**：`end()`
    指向最后一个元素之后，不能解引用。
3.  **对空容器调用 `front()`、`back()`、`top()` 或
    `pop()`**：使用前先检查 `empty()`。
4.  **认为 `map[key]` 只是查询**：键不存在时，它会插入一个新元素。
5.  **认为 `unique` 会自动缩小 `vector`**：还要配合 `erase`。
6.  **对 `list` 使用下标或 `std::sort`**：`list` 没有下标访问，应使用
    `list` 的成员 `sort()`。
7.  **在修改容器后继续使用失效迭代器**：插入、删除或扩容可能使迭代器、指针、引用失效；要查看具体容器规则。
8.  **对未排序数据直接使用二分查找**：先确保区间满足算法要求。
9.  **使用 `priority_queue` 时以为 `pop()` 会返回元素**：先读取
    `top()`，再调用 `pop()`。
10. **整数溢出**：累加较大的整数时，考虑使用 `long long` 和 `0LL`。
11. **误以为 `unordered_map` 会按键排序**：它不保证元素遍历顺序。
12. **自定义排序比较器使用 `>=` 或 `<=`**：应建立严格弱序关系，通常用
    `<` 或 `>`。

------------------------------------------------------------------------

## 14. 学习顺序建议

### 第一阶段：基础容器

1.  `vector`：动态数组、下标、遍历、插入与删除。
2.  `string`：拼接、截取、查找。
3.  `pair`、`auto`、范围 `for`。

### 第二阶段：键值与集合

4.  `map` 和 `unordered_map`：键值对、频率统计。
5.  `set` 和 `unordered_set`：去重、查找。
6.  理解有序容器与无序容器的区别。

### 第三阶段：算法

7.  `sort`、`reverse`、`find`、`count`。
8.  `lower_bound`、`upper_bound`、`binary_search`。
9.  `unique`、`erase-remove`、`accumulate`。

### 第四阶段：数据结构与算法应用

10. `stack`、`queue`：括号匹配、BFS 等。
11. `priority_queue`：堆、Top K、调度问题。
12. 迭代器失效、复杂度和自定义比较器。

------------------------------------------------------------------------

## 附录：常见头文件速查

``` cpp
#include <iostream>       // 输入输出
#include <vector>         // vector
#include <array>          // array
#include <deque>          // deque
#include <list>           // list
#include <string>         // string
#include <set>            // set, multiset
#include <map>            // map, multimap
#include <unordered_set>  // unordered_set, unordered_multiset
#include <unordered_map>  // unordered_map, unordered_multimap
#include <stack>          // stack
#include <queue>          // queue, priority_queue
#include <algorithm>      // sort, find, reverse, lower_bound 等
#include <numeric>        // accumulate, iota, partial_sum 等
#include <utility>        // pair, make_pair, swap
#include <tuple>          // tuple
#include <functional>     // greater, less 等函数对象
```

> 学习建议：不要只背函数名。每学一个容器，至少自己写一遍"创建、插入、查找、遍历、删除"五类操作，并用小程序验证行为。
