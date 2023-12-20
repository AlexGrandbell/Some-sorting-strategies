#ifndef RANK_OF_SCHOLARSHIP_INTEGER_H
#define RANK_OF_SCHOLARSHIP_INTEGER_H

#include "Sortable.h"

class Integer: public Sortable {
private:
    int value;

public:
    //构造函数生成low-high的随机整数
    Integer():value(generateRandomInt(1,100000)){}
    Integer(int low, int high) : value(generateRandomInt(low, high)) {}

    friend ostream &operator<<(ostream &out, const Integer &s);
    bool operator==(const Integer &) const;
    bool operator>(const Integer &) const;
    bool operator<(const Integer &) const;
    bool operator>=(const Integer &) const;
    bool operator<=(const Integer &) const;

    //用于基数排序时的进制（桶）数
    int getRadix() {
        return 10;
    };

    //用于基数排序的关键字字数
    int getRounds(){
        return getDigitCount(value);
    };

    //用于接受基数排序的轮数内容
    int getRoundsOf(int i){
        if (i <= 0) {
            return 0;
        }

        int digit = 0;
        // 使用循环和除法取余操作获取右边第i个数字
        for (int count = 1; count <= i; ++count) {
            digit = value % 10;
            value /= 10;

            if (value == 0 && count < i) {
                // 如果已经没有更多的数字，但i仍然大于count，则返回0
                return 0;
            }
        }

        return digit;
    };
};


#endif //RANK_OF_SCHOLARSHIP_INTEGER_H
