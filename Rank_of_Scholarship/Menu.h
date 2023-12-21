//
// Created by 沈嘉瑞 on 2023.11.21.
//

#ifndef TEACHING_PLANNING_MENU_H
#define TEACHING_PLANNING_MENU_H

#include "SortManagement.h"
#include "Student.h"
#include "Integer.h"

template<class T>
class Menu {
private:
    SortManagement<T> sortManagement;
public:
    static_assert(is_base_of<Sortable, T>::value, "T必须继承自Sortable");
    void Welcome();
    void DoMenu();
    void show(vector<T>);
};

template<class T>
void Menu<T>::Welcome() {
    cout << "\n欢迎进入排名系统" << endl;
    cout<<"你可以随时输入'q'来退出当前操作。"<<endl;
    cout<<"----------任意输入以开始----------"<<endl;
    string tmp = inputString();
    cout<<endl;
}

template<class T>
void Menu<T>::DoMenu() {
    sortManagement.input();
    int nSelection = -1;//判断用户输入的数字选择对应的菜单
    //不断循环，执行操作
    do {
        //界面与输入
        cout<<"\n --------排序菜单--------"<<endl;
        cout<<" 1.直接插入排序"<<endl;
        cout<<" 2.希尔排序"<<endl;
        cout<<" 3.冒泡排序"<<endl;
        cout<<" 4.快速排序"<<endl;
        cout<<" 5.简单选择排序"<<endl;
        cout<<" 6.堆排序"<<endl;
        cout<<" 7.归并排序"<<endl;
        cout<<" 8.基数排序"<<endl;
        cout<<" 9.都来一遍比较时间"<<endl;
        cout<<" 10.更新数据"<<endl;
        cout<<" 0.退出当前程序"<<endl;
        cout<<" -----------------------"<<endl;
        //输出提示选择编号
        cout<<"请选择菜单项编号(0-10):";
        fflush(stdin);//清除输入流缓存
        nSelection = -1;
        try {
            nSelection = inputInt();

            //根据输入选择行为
            switch (nSelection) {
                case 0: {
                    cout<<"\n欢迎再次使用，再见。"<<endl;
                    return;
                }
                case 1: {
                    show(sortManagement.insertSort());
                    break;
                }
                case 2: {
                    show(sortManagement.shellSort());
                    break;
                }
                case 3:{
                    show(sortManagement.bubbleSort());
                    break;
                }
                case 4:{
                    show(sortManagement.quickSort());
                    break;
                }
                case 5:{
                    show(sortManagement.selectSort());
                    break;
                }
                case 6:{
                    show(sortManagement.heapSort());
                    break;
                }
                case 7:{
                    show(sortManagement.mergeSort());
                    break;
                }
                case 8:{
                    show(sortManagement.radixSort());
                    break;
                }
                case 9:{
                    vector<double> times;
//                    sortManagement.insertSort();
                    sortManagement.shellSort();
//                    sortManagement.bubbleSort();
                    sortManagement.quickSort();
//                    sortManagement.selectSort();
                    sortManagement.heapSort();
                    sortManagement.mergeSort();
                    sortManagement.radixSort();
                    break;
                }
                case 10:
                    sortManagement.input();
                    break;
                default: {
                    cout<<"您输入的序号错误。";
                    break;
                }
            }//完成
        } catch (const exception &e) {
            cout << e.what() << endl;
        }
        if (nSelection != 0) {
            cout<<"继续操作请按1，关闭程序请按0:";
            fflush(stdin);//清除输入流缓存
            nSelection = -1;
            try {
                nSelection = inputInt();
                if (nSelection == 0) {
                    cout<<"\n欢迎再次使用，再见。"<<endl;
                }
            }catch  (const exception& e){
                cout<<e.what()<<endl;
            }
        }
    } while (nSelection != 0);
}

template<class T>
void Menu<T>::show(vector<T> ss) {
    cout<<"请输入任意按键以查看:";
    inputString();
    cout<<"排名如下:"<<endl;
    for (int i = 1; i <= ss.size(); ++i) {
        cout<<"第"<<left<<setw(3)<<i<<"名: "<<ss[ss.size()-i]<<endl;
    }
    cout<<"排名展示结束"<<endl;
}

#endif //TEACHING_PLANNING_MENU_H
