#ifndef TEACHING_PLANNING_MENU_H
#define TEACHING_PLANNING_MENU_H

#include "SortManager.h"
#include "Student.h"
#include "Integer.h"

template<class T>
class Menu {
private:
    SortManager<T> studentSortManager;
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
//    int num = 0;
//    cout << "请输入学生人数:";
//    num = inputInt();
//    while (num < 5) {
//        cout << "请输入5以上的人数以便排名:";
//        num = inputInt();
//    }
//    cout<<"请逐个输入学生信息:"<<endl;
//    for (int i = 0; i < num; ++i) {
//        Student student;
//        cout<<"请输入第"<<i+1<<"个学生的信息(姓名、学号、语文、数学、英语):";
//        student.setName(inputString());
//        student.setNumber(inputInt());
//        student.setChinese(inputInt());
//        student.setMath(inputInt());
//        student.setEnglish(inputInt());
//        studentSortManager.ts.push_back(student);
//    }

    for (int i = 0; i < 1000000; ++i) {
        studentSortManager.ts.push_back(Integer(1,100000));
    }

    int nSelection = -1;//判断用户输入的数字选择对应的菜单
    //不断循环，执行操作
    do {
        //界面与输入
        cout<<"\n --------排序菜单--------"<<endl;
        cout<<"1.直接插入排序"<<endl;
        cout<<"2.希尔排序"<<endl;
        cout<<"3.冒泡排序"<<endl;
        cout<<"4.快速排序"<<endl;
        cout<<"5.选择排序"<<endl;
        cout<<"6.堆排序"<<endl;
        cout<<"7.归并排序"<<endl;
        cout<<"8.基数排序"<<endl;
        cout<<"9.都来一遍比较时间"<<endl;
        cout<<"0.退出当前程序"<<endl;
        cout<<" -----------------------"<<endl;
        //输出提示选择编号
        cout<<"请选择菜单项编号(0-9):";
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
                    show(studentSortManager.insertSort());
                    break;
                }
                case 2: {
                    show(studentSortManager.shellSort());
                    break;
                }
                case 3:{
                    show(studentSortManager.bubbleSort());
                    break;
                }
                case 4:{
                    show(studentSortManager.quickSort());
                    break;
                }
                case 5:{
                    show(studentSortManager.selectSort());
                    break;
                }
                case 6:{
                    show(studentSortManager.heapSort());
                    break;
                }
                case 7:{
                    show(studentSortManager.mergeSort());
                    break;
                }
                case 8:{
                    show(studentSortManager.radixSort());
                    break;
                }
                case 9:{
                    vector<double> times;
                    studentSortManager.insertSort();
                    studentSortManager.shellSort();
                    studentSortManager.bubbleSort();
                    studentSortManager.quickSort();
                    studentSortManager.selectSort();
                    studentSortManager.heapSort();
                    studentSortManager.mergeSort();
                    studentSortManager.radixSort();
                    break;
                }
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
