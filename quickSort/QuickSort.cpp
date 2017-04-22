//
// Created by RetroX on 16/04/2017.
//

/**
 * 功能：对数组升序快排，递归实现
 * 参数：lst：带排序数组，head：数组首元素下标，tail：数组末元素下标
 * 返回值：无
 */
template<typename T>
void qsort(T lst[], int head, int tail) {


    if (head >= tail) return;

    int i = head, j = tail;

    T pivot = lst[head];  // 通常取第一个数为基准

    while (i < j) { // i,j 相遇即退出循环
        while (i < j and lst[j] >= pivot) j--;
        lst[i] = lst[j];    // 从右向左扫描，将比基准小的数填到左边
        while (i < j and lst[i] <= pivot) i++;
        lst[j] = lst[i];    //  从左向右扫描，将比基准大的数填到右边
    }

    lst[i] = pivot; // 将 基准数 填回

    qsort(lst, head, i - 1);    // 以基准数为界左右分治
    qsort(lst, j + 1, tail);
}