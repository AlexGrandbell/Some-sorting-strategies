#ifndef RANK_OF_SCHOLARSHIP_STUDENT_H
#define RANK_OF_SCHOLARSHIP_STUDENT_H

#include "Sortable.h"

class Student: public Sortable{
private:
    string name;
    int number;
    int chinese;
    int math;
    int english;
    void calSum();
public:
    int sum;
    Student():name("无名"),number(0),chinese(0),math(0),english(0),sum(0){};
    Student(string na,int n,int c,int m,int e,int s):name(na),number(n),chinese(c),math(m),english(e),sum(s){};
    friend ostream& operator<<(ostream& out,const Student& s);
    bool operator==(const Student&) const;
    bool operator>(const Student&) const;
    bool operator<(const Student&) const;
    bool operator>=(const Student&) const;
    bool operator<=(const Student&) const;

    void setName(string);
    void setNumber(int );
    void setChinese(int );
    void setMath(int );
    void setEnglish(int );

    //用于基数排序时的进制（桶）数
    int getRadix() {
        int max = 0;
        if (number>max) max = number;
        if (chinese>max) max = chinese;
        if (math>max) max = math;
        if (english>max) max = english;
        return max;
    };

    //用于基数排序的关键字字数
    int getRounds(){
        return 3;
    };

    //用于接受基数排序的轮数内容
    int getRoundsOf(int i){
        switch (i) {
            case 0:
                return number;
            case 1:
                return math;
            default:
                return sum;
        }
    };
};



#endif //RANK_OF_SCHOLARSHIP_STUDENT_H
