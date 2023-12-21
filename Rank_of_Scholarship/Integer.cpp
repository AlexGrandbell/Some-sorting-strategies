//
// Created by 沈嘉瑞 on 2023.12.20.
//

#include "Integer.h"

ostream &operator<<(ostream &out, const Integer & i) {
    return out<<i.value;
}

bool Integer::operator==(const Integer &i) const {
    return value==i.value;
}

bool Integer::operator>(const Integer &i) const {
    return value>i.value;
}

bool Integer::operator<(const Integer &i) const {
    return value<i.value;
}

bool Integer::operator>=(const Integer &i) const {
    return value>=i.value;
}

bool Integer::operator<=(const Integer &i) const {
    return value<=i.value;
}

void Integer::input(int i,int num) {
    if (num > 50000) {
        progressBar(i, num);
    }
    value = generateRandomInt(1, 10000);
}


