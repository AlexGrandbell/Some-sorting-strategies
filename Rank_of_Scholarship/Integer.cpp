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


