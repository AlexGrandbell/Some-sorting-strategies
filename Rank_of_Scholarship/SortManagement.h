//
// Created by 沈嘉瑞 on 2023.12.19.
//

#ifndef RANK_OF_SCHOLARSHIP_SORTMANAGEMENT_H
#define RANK_OF_SCHOLARSHIP_SORTMANAGEMENT_H

#include "Tool.h"

//从小到大排序
template<class T>
class SortManagement {
private:
    vector<T> ts;
public:
    SortManagement(): ts(){};
    vector<T> insertSort();//直接插入排序
    vector<T> shellSort();//希尔排序
    vector<T> bubbleSort();//冒泡排序

    vector<T> quickSort();//快速排序
    void quickSortRecursive(vector<T>&, int , int );//快速排序递归
    int partition(vector<T>& , int , int );//快速排序切割

    vector<T> selectSort();//选择排序

    vector<T> heapSort();//堆排序
    void heapSortAdjust(vector<T>&, int , int );//堆排序建堆

    vector<T> mergeSort();//归并排序
    void mergeSortRecursive(vector<T>&, int, int);//归并排序递归
    void merge(vector<T>& , int , int , int);//归并动作

    vector<T> radixSort();//基数排序

    void input();
};

template<class T>
vector<T> SortManagement<T>::insertSort() {
    cout<<"--------直接插入排序--------"<<endl;
    vector<T> ts2 = ts;
    cout<<"直接插入排序开始"<<endl;
    clock_t start_time = clock();
    int n = ts2.size()-1;
    for (int i = 1; i <= n; ++i) {
        T temp = ts2[i];
        int j = i - 1;
        while (j >= 0 && temp < ts2[j]) {
            ts2[j + 1] = ts2[j];
            j--;
        }
        ts2[j + 1] = temp;
    }
    clock_t end_time = clock();
    double time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("直接插入排序结束，用时%f秒\n\n",time_used);
    return ts2;
}

template<class T>
vector<T> SortManagement<T>::shellSort() {
    cout<<"--------希尔排序--------"<<endl;
    vector<T> ts2 = ts;
    cout<<"希尔排序开始"<<endl;
    clock_t start_time = clock();
    int n = ts2.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            T temp = ts2[i];
            int j;
            for (j = i; j >= gap && ts2[j - gap] > temp; j -= gap) {
                ts2[j] = ts2[j - gap];
            }
            ts2[j] = temp;
        }
    }
    clock_t end_time = clock();
    double time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("希尔排序结束，用时%f秒\n\n",time_used);
    return ts2;
}

template<class T>
vector<T> SortManagement<T>::bubbleSort() {
    cout<<"--------冒泡排序--------"<<endl;
    vector<T> ts2 = ts;
    cout<<"冒泡排序开始"<<endl;
    clock_t start_time = clock();
    int n = ts2.size();
    for (int i = 0; i < n-1; ++i) {
        if (i % 100 == 0) {
            cout << i << endl;
        }
        for (int j = 0; j < n - i - 1; ++j) {
            if (ts2[j] > ts2[j + 1]) {
                swap(ts2[j], ts2[j + 1]);
            }
        }
    }
    clock_t end_time = clock();
    double time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("冒泡排序结束，用时%f秒\n\n",time_used);
    return ts2;
}

template<class T>
vector<T> SortManagement<T>::quickSort() {
    cout<<"--------快速排序--------"<<endl;
    vector<T> ts2 = ts;
    cout<<"快速排序开始"<<endl;
    clock_t start_time = clock();
    quickSortRecursive(ts2,0,ts2.size()-1);
    clock_t end_time = clock();
    double time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("快速排序结束，用时%f秒\n\n",time_used);
    return ts2;
}

template<class T>
void SortManagement<T>::quickSortRecursive(vector<T>& arr, int low, int high) {
    if (low < high) {
        int middle = partition(arr, low, high);
        quickSortRecursive(arr, low, middle - 1);
        quickSortRecursive(arr, middle + 1, high);
    }
}

template<class T>
int SortManagement<T>::partition(vector<T>& arr, int low, int high) {
//    T pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; ++j) {
        if (arr[j] < arr[low]) {
            swap(arr[i], arr[j]);
            ++i;
        }
    }

    swap(arr[low], arr[i - 1]);
    return i - 1;

    //课堂给出的
//    T temp = arr[low];
//    while (low<high){
//        while (low<high && arr[high]>= temp){
//            high--;
//        }
//        if (low<high){
//            arr[low]=arr[high];
//            low++;
//        }
//        while (low<high && arr[low]<= temp){
//            low++;
//        }
//        if (low<high){
//            arr[high]=arr[low];
//            high--;
//        }
//    }
//    arr[low] = temp;
//    return low;
}

template<class T>
vector<T> SortManagement<T>::selectSort() {
    cout<<"--------简单选择排序--------"<<endl;
    vector<T> ts2 = ts;
    cout << "简单选择排序开始" << endl;
    clock_t start_time = clock();
    int n = ts2.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (ts2[j] < ts2[minIndex]) {
                minIndex = j;
            }
        }
        if (i!=minIndex) {
            swap(ts2[i], ts2[minIndex]);
        }
    }
    clock_t end_time = clock();
    double time_used = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    printf("简单选择排序结束，用时%f秒\n\n", time_used);
    return ts2;
}

//大根堆
template<class T>
vector<T> SortManagement<T>::heapSort() {
    cout<<"---------堆排序---------"<<endl;
    vector<T> ts2 = ts;
    cout << "堆排序开始" << endl;
    clock_t start_time = clock();
    int n = ts2.size();
    //以0为序号起始
    //初始建堆
    //错误点：是--i不是++i
    for (int i = n/2-1 ; i >= 0; --i) {
        heapSortAdjust(ts2,n,i);
    }
    //依次取出堆顶元素，进行排序
    for (int i = n - 1; i > 0; --i) {
        //将当前堆顶元素（最大值）与末尾元素交换
        swap(ts2[0], ts2[i]);
        //重新建堆
        heapSortAdjust(ts2, i, 0);
    }
    clock_t end_time = clock();
    double time_used = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    printf("堆排序结束，用时%f秒\n\n", time_used);
    return ts2;
}

//有n个元素的数组，以下标为i建堆
template<class T>
void SortManagement<T>::heapSortAdjust(vector<T>& arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    //左节点与最大值比较
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    //继续将右节点与最大值比较
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    // 如果最大值不是当前节点，交换并继续调整
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapSortAdjust(arr, n, largest);
    }
}

template<class T>
vector<T> SortManagement<T>::mergeSort() {
    cout<<"-------二路归并排序-------"<<endl;
    vector<T> ts2 = ts;
    cout << "二路归并排序开始" << endl;
    clock_t start_time = clock();
    int n = ts2.size();
    mergeSortRecursive(ts2, 0, n - 1);
    clock_t end_time = clock();
    double time_used = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    printf("二路归并排序结束，用时%f秒\n\n", time_used);
    return ts2;
}

template<class T>
void SortManagement<T>::mergeSortRecursive(vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + ((right - left) / 2);
        //将左右数组排序为分别有序
        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);
        //合并两个有序数组
        merge(arr, left, mid, right);
    }
}

template<class T>
void SortManagement<T>::merge(vector<T>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // 创建临时数组来存储左右两侧的元素
    vector<T> leftArr(n1);
    vector<T> rightArr(n2);

    // 将数据复制到临时数组中
    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[low + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // 合并左右两个有序数组
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    // 将剩余的元素复制回原数组
    while (i < n1) {
        arr[k++] = leftArr[i++];
    }
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

template<class T>
vector<T> SortManagement<T>::radixSort() {
    cout<<"--------基数排序--------"<<endl;
    vector<T> ts2 = ts;
    cout << "基数排序开始" << endl;
    clock_t start_time = clock();
    int n = ts2.size();
//    if (n>300){
//        throw myExpection("抱歉，基数排序要求个数小于300");
//    }
    int rounds = 0;//循环次数
    int radix = 0;//桶数
    for (T t:ts2) {
        rounds = max(rounds,t.getRounds());
        radix = max(radix,t.getRadix());
    }

    for (int round = 0; round < rounds; ++round) {
        vector<vector<T>> buckets(radix+10);
        //将元素放入桶中
        for (int i = 0; i < n; ++i) {
            int tSortNum = ts2[i].getRoundsOf(round);
            buckets[tSortNum].push_back(ts2[i]);
        }
        //再将桶中元素按序取回
        int index = 0;
        for (int i = 0; i < radix; ++i) {
            for(T t:buckets[i]){
                ts2[index++] = t;
            }
        }
    }
    clock_t end_time = clock();
    double time_used = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    printf("基数排序结束，用时%f秒\n\n", time_used);
    return ts2;
}

template<class T>
void SortManagement<T>::input() {
    cout<<"--------输入元素--------"<<endl;
    int num = 0;
    cout << "请输入元素个数:";
    num = inputInt();
    while (num < 5) {
        cout << "请输入5以上的个数以便排序:";
        num = inputInt();
    }
    cout<<"开始初始化元素信息，请稍等..."<<endl;
    vector<T> ts2;
    for (int i = 0; i < num; ++i) {
        T t;
        t.input(i+1,num);
        ts2.push_back(t);
    }
    ts = ts2;
    cout<<"元素信息生成完成。"<<endl;
    cout<<"--------------------------"<<endl;
}
#endif //RANK_OF_SCHOLARSHIP_SORTMANAGEMENT_H
