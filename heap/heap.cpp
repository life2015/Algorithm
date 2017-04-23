//
// Created by RetroX on 22/04/2017.
//

#ifndef ALGORITHM_HEAP_H__
#define ALGORITHM_HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

/**
 * 放在一个命名空间里面单独管理
 */
namespace algorithm {

    /**
	 * swap 2-element, orignal value
	 */
    template<typename T>
    static inline void swap(T &x, T &y) {
        T _t(x);
        x = y;
        y = _t;
    }

    template<typename T>
    class Heap {
    public:
        /**
         * 就是一个键值对
         */
        struct elem {
        public:
            int key;
            T data;
        };

    private:
        int m_size;        // 当前堆大小
        int m_max;        // 最大的堆打下
        elem *m_heap;    // 键值对们
    public:
        Heap(int max) {
            m_size = 0;
            m_max = max;
            m_heap = new elem[m_max];
        };

        ~Heap() {
            delete[] m_heap;
        };

    private:
        Heap(const Heap &);

        Heap &operator=(const Heap &);

    public:
        // for loop through the kvs
        inline int count() const { return m_size; };

        /**
         * 在堆里面插入一个键值对
         */
        void push(int key, const T &data) {
            // 堆满 返回
            if (m_size == m_max) return;
            // 先放到最后然后往上移动它
            m_heap[m_size].key = key;
            m_heap[m_size].data = data;
            up(m_size);
            m_size++;
        }

        /**
         * 查空
         */
        inline bool is_empty() const { return (m_size == 0) ? true : false; }

        /**
         * clear the heap
         */
        inline void clear() { m_size = 0; }

        bool contains(const T &data) {
            for (int i = 0; i < m_size; i++) {
                if (m_heap[i].data == data) return true;
            }
            return false;
        }

        /**
         * pop the min element
         */
        elem pop() {
            int n = m_size - 1;
            swap(m_heap[0], m_heap[n]);
            down(0, n);
            m_size--;
            return m_heap[m_size];
        }

        /**
         *  remove the given data
         */
        bool remove(const T &data) {
            for (int i = 0; i < m_size; i++) { // loop finding
                if (m_heap[i].data == data) { // found
                    int n = m_size - 1;
                    if (n != i) {
                        swap(m_heap[i], m_heap[n]);
                        down(i, m_size);
                        up(i);
                    }
                    m_size--;
                    return true;
                }
            }
            return false;
        }

        /**
         *  暂时不用
         *
         */
        void decrease_key(const T &data, int newkey) {
            if (remove(data)) {
                push(newkey, data);
            }
        }

        void up(int j) {
            for (;;) {
                int i = (j - 1) / 2; // parent
                if (i == j || !less(j, i)) {    // j not smaller than i
                    break;
                }
                swap(m_heap[i], m_heap[j]);
                j = i;
            }
        }

        void down(int i, int n) {
            for (;;) {
                int j1 = 2 * i + 1;    // left child
                if (j1 >= n || j1 < 0) { // j1 < 0 after int overflow
                    break;
                }

                int j = j1;
                int j2 = j1 + 1; // right child
                if (j2 < n && !less(j1, j2)) {
                    j = j2;    // choose the minium one.
                }

                if (!less(j, i)) {
                    break;
                }
                swap(m_heap[i], m_heap[j]);
                i = j;
            }
        }

        void print_heap() {
            for (int i = 0; i < m_size; i++) {
                printf("key:%d value:%d ", m_heap[i].key, m_heap[i].data);
            }
            printf("\n");
        }

        bool less(int i, int j) {
            return m_heap[i].key < m_heap[j].key;
        }
    };
}

#endif
