/*
这里会集合所有我写的排序算法函数
便于今后调用
*/
#ifndef SEARCH_TOOLS_H
#define SEARCH_TOOLS_H

#include <vector>
#include <algorithm>

namespace searchtools {

/* 哈希表类型：链地址法，每个桶是一个 vector<int> */
using HashTable = std::vector<std::vector<int>>;

/* ============================================================
 * 1. Binary_search  —— 二分查找
 *    arr      : 待查找数组（内部会拷贝并排序，不修改原数组）
 *    key      : 目标值
 *    outIndex : 找到时返回 key 在升序数组中的下标
 *    outCount : 比较次数
 *    返回     : true 表示找到，false 表示未找到
 * ============================================================ */
inline bool binary_search(const std::vector<int>& arr, int key,
                          int& outIndex, int& outCount)
{
    outIndex = -1;
    outCount = 0;

    std::vector<int> ls = arr;
    std::sort(ls.begin(), ls.end());              // 需要有顺序

    int left  = 0;
    int right = static_cast<int>(ls.size()) - 1;

    // 只有 key 落在当前区间内才继续
    while (left <= right && key >= ls[left] && key <= ls[right]) {
        ++outCount;
        int mid = left + (right - left) / 2;      // 防止 (left+right) 溢出

        if (ls[mid] == key) {
            outIndex = mid;
            return true;
        } else if (ls[mid] < key) {
            left = mid + 1;                       // 原版 left = mid 会死循环
        } else {
            right = mid - 1;                      // 原版 right = mid 会死循环
        }
    }
    return false;
}

/* ============================================================
 * 2. Hash_search  —— 建立哈希表（辅助函数，对应原 haxe）
 *    inlist : 原始数据
 *    返回   : 链地址法哈希表，桶数 = inlist.size()
 * ============================================================ */
inline HashTable build_hash(const std::vector<int>& inlist)
{
    const int length = static_cast<int>(inlist.size());
    HashTable table(length);
    if (length == 0) return table;

    for (int v : inlist) {
        int idx = v % length;
        if (idx < 0) idx += length;               // C++ 负数取模需修正
        table[idx].push_back(v);
    }
    return table;
}

/* ============================================================
 * 3. Hash_search  —— 哈希查找（对应原 haxe_find）
 *    table     : build_hash 建好的哈希表
 *    key       : 目标值
 *    outBucket : 找到时返回桶号
 *    outPos    : 找到时返回桶内位置
 *    返回      : true 表示找到，false 表示未找到
 * ============================================================ */
inline bool hash_search(const HashTable& table, int key,
                        int& outBucket, int& outPos)
{
    outBucket = -1;
    outPos    = -1;

    const int length = static_cast<int>(table.size());
    if (length == 0) return false;

    int idx = key % length;
    if (idx < 0) idx += length;

    for (int i = 0; i < static_cast<int>(table[idx].size()); ++i) {
        if (table[idx][i] == key) {
            outBucket = idx;
            outPos    = i;
            return true;
        }
    }
    return false;
}

/* 便捷重载：一步到位，内部先建表再查找 */
inline bool hash_search(const std::vector<int>& inlist, int key,
                        int& outBucket, int& outPos)
{
    HashTable table = build_hash(inlist);
    return hash_search(table, key, outBucket, outPos);
}

/* 重载，使其能够无需返回索引*/
inline bool hash_search(const HashTable& table, int key)
{
    const int length = static_cast<int>(table.size());
    if (length == 0) return false;

    int idx = key % length;
    if (idx < 0) idx += length;

    for (int i = 0; i < static_cast<int>(table[idx].size()); ++i) {
        if (table[idx][i] == key) {
            return true;
        }
    }
    return false;
}

/* ============================================================
 * 4. Hash_search —— 加入单个元素进哈希表的操作函数
 *    table : build_hash 建好的哈希表（引用，原地修改）
 *    value : 要插入的值
 *    说明  : 桶数固定为 table.size()，不会自动扩容；
 *            若表为空（size == 0）则直接忽略
 * ============================================================ */
inline void hash_add(HashTable& table, int value)
{
    const int length = static_cast<int>(table.size());
    if (length == 0) return;

    int idx = value % length;
    if (idx < 0) idx += length;                   // 修正负数取模
    table[idx].push_back(value);
}


/* ============================================================
 * 4. Interpolation_search —— 插值查找
 *    arr      : 待查找数组（内部会拷贝并排序，不修改原数组）
 *    key      : 目标值
 *    outIndex : 找到时返回 key 在升序数组中的下标
 *    outCount : 比较次数
 *    返回     : true 表示找到，false 表示未找到
 *    说明     : 适合均匀分布的升序数据
 * ============================================================ */
inline bool interpolation_search(const std::vector<int>& arr, int key,
                                 int& outIndex, int& outCount)
{
    outIndex = -1;
    outCount = 0;

    std::vector<int> ls = arr;
    std::sort(ls.begin(), ls.end());              // 需要有顺序

    int left  = 0;
    int right = static_cast<int>(ls.size()) - 1;

    while (left <= right && key >= ls[left] && key <= ls[right]) {
        ++outCount;

        int denom = ls[right] - ls[left];
        if (denom == 0) {                         // 防止除零
            if (ls[left] == key) { outIndex = left; return true; }
            break;
        }

        // 近似均匀分布选取中点
        int mid = left + static_cast<int>(
                      static_cast<double>(right - left) *
                      (static_cast<double>(key - ls[left]) / denom));

        // 防止浮点误差导致越界
        if (mid < left)  mid = left;
        if (mid > right) mid = right;

        if (ls[mid] == key) {
            outIndex = mid;
            return true;
        } else if (ls[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

} // namespace searchtools

#endif // SEARCH_TOOLS_H