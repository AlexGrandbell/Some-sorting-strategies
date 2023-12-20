#ifndef RANK_OF_SCHOLARSHIP_SORTABLE_H
#define RANK_OF_SCHOLARSHIP_SORTABLE_H
#include "Tool.h"

class Sortable {
public:
    //用于基数排序时的进制（桶）数
    virtual int getRadix()=0;

    //用于基数排序的关键字字数
    virtual int getRounds()=0;

    //用于接受基数排序的轮数内容
    virtual int getRoundsOf(int)=0;
};

#endif //RANK_OF_SCHOLARSHIP_SORTABLE_H
