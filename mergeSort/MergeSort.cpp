#include <iostream>

//
// Created by RetroX on 16/04/2017.
//
void mergeArray(int *a, int first, int mid, int last, int *temp);

void mergeSort(int *a, int first, int last, int *temp);

int main() {
    int a[] = {3, 5, 4, 1, 7};
    int *temp = new int[5];
    mergeSort(a, 0, 4, temp);
    for (int i = 0; i < 5; ++i) {
        std::cout << a[i];
    }
}


void mergeSort(int *a, int first, int last, int *temp) {

    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(a, first, mid, temp);
        mergeSort(a, mid + 1, last, temp);
        mergeArray(a, first, mid, last, temp);
    }

}

void mergeArray(int *a, int first, int mid, int last, int *temp) {

    int i = first;
    int j = mid + 1;
    int m = mid;
    int n = last;

    int cursor = 0;

    //因为传入的边界都是可以访问的，所以加上等于号，否则会排序错误
    while (i <= m && j <= n) {
        if (a[i] <= a[j]) {
            temp[cursor] = a[i];
            i++;
        } else {
            temp[cursor] = a[j];
            j++;
        }
        cursor++;
    }

    while (i <= m) {
        temp[cursor] = a[i];
        cursor++;
        i++;
    }

    while (j <= n) {
        temp[cursor] = a[j];
        cursor++;
        j++;
    }

    for (int k = 0; k < cursor; ++k) {
        a[first + k] = temp[k];
    }


}