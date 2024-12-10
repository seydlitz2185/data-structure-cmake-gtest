#include <gtest/gtest.h>
#include "../sort/sort.h"
#include <algorithm>
#include <random>
#include <vector>
#include <functional>
// 使用chatGPT改进了测试函数

// 共享随机数序列
std::vector<int> shared_random_numbers;

// 初始化共享随机数序列
void initialize_random_numbers(int size, int min, int max, int seed = 42)
{
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(min, max);

    shared_random_numbers.resize(size);
    for (int i = 0; i < size; ++i)
    {
        shared_random_numbers[i] = dist(rng);
    }
}

// 定义通用测试函数
using SortFunction = std::function<void(int *, int)>;

void test_sort(SortFunction sort_function, const std::string &algorithm_name)
{
    const int size = shared_random_numbers.size();
    int a[size], b[size];

    for (int i = 0; i < size; ++i)
    {
        a[i] = shared_random_numbers[i];
        b[i] = shared_random_numbers[i];
    }
    // c风格数组遍历方式
    std::sort(a, a + size); // 使用标准库排序
    // 若遍历vector容器，使用a.begin(), a.end()
    sort_function(b, size); // 调用传入的排序算法

    EXPECT_TRUE(std::equal(a, a + size, b))
        << "Failed: " << algorithm_name;
}

// 测试用例

TEST(sort_test, InsertionSort)
{
    test_sort(InsertionSort, "InsertionSort");
}

TEST(sort_test, BinarySearchInsertionSort)
{
    test_sort(BinarySearchInsertionSort, "BinarySearchInsertionSort");
}
TEST(sort_test, ShellSort)
{
    test_sort(ShellSort, "ShellSort");
}
/**
TEST(sort_test, ShellSortBad) {
    test_sort(ShellSortBad, "ShellSortBad");
}
*/

TEST(sort_test, BubbleSort)
{
    test_sort(BubbleSort, "BubbleSort");
}

TEST(sort_test, SelectSort)
{
    test_sort(SelectSort, "SelcetSort");
}
TEST(sort_test, QuickSort)
{
    test_sort(QuickSort, "QuickSort");
}
TEST(sort_test, MergeSort)
{
    test_sort(MergeSort, "MergeSort");
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    // 初始化共享随机数序列
    initialize_random_numbers(10, -100, 100);

    return RUN_ALL_TESTS();
}