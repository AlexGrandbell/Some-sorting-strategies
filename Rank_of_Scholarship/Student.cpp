#include "Student.h"

ostream& operator<<(ostream &out, const Student &s) {
    return out<<"姓名:"<<left<<setw(8)<<s.name<<"学号:"<<left<<setw(8)<<s.number<<"语文:"<<left<<setw(4)<<s.chinese<<"数学:"<<left<<setw(4)<<s.math<<"英语:"<<left<<setw(4)<<s.english<<"总分:"<<left<<setw(5)<<s.sum;
}

bool Student::operator==(const Student & s) const {
    if (sum == s.sum){
        if (math == s.math){
            if (number == s.number){
                return true;
            }
        }
    }
    return false;
}

bool Student::operator>(const Student & s) const {
    if (sum > s.sum){
        return true;
    } else if (sum < s.sum) {
        return false;
    } else{
        if (math > s.math){
            return true;
        } else if (math < s.math) {
            return false;
        } else{
            if (number < s.number){
                return true;
            } else{
                return false;
            }
        }
    }
}

bool Student::operator<(const Student & s) const {
    if (sum < s.sum){
        return true;
    } else if (sum > s.sum) {
        return false;
    } else{
        if (math < s.math){
            return true;
        } else if (math > s.math) {
            return false;
        } else{
            if (number > s.number){
                return true;
            } else{
                return false;
            }
        }
    }
}

bool Student::operator>=(const Student & s) const {
    return (*this==s)||(*this>s);
}

bool Student::operator<=(const Student & s) const {
    return (*this==s)||(*this<s);
}

void Student::calSum() {
    sum = math+chinese+english;
}

void Student::setName(string s) {
    name = s;
}

void Student::setNumber(int n) {
    number = n;
}

void Student::setChinese(int c) {
    chinese = c;
    calSum();
}

void Student::setMath(int m) {
    math = m;
    calSum();
}

void Student::setEnglish(int e) {
    english = e;
    calSum();
}