#include "Tool.h"

double inputDouble(){
    return doubleNumberTest(inputString());
}

int inputInt(){
    return intNumberTest(inputString());
}

string inputString(){
    string tmp;
    cin>>tmp;
    exitTest(tmp);
    return tmp;
}

//double转换
double doubleNumberTest(string num){
    double tempDouble = 0;
    istringstream iss(num);
    if (iss >> tempDouble) {
        return tempDouble;
    } else {
        throw myExpection("在需要输入小数的地方输入的不是一个数字，操作失败！");
    }
};

int intNumberTest(string num){
    int tempDouble = 0;
    std::istringstream iss(num);
    if (iss >> tempDouble) {
        return tempDouble;
    } else {
        throw myExpection("在需要输入整数的地方输入的不是一个数字，操作失败！");
    }
}

//随机整数
int generateRandomInt(int low,int high) {
    // 使用随机设备生成种子
    random_device rd;
    // 使用 mt19937 引擎和生成的种子初始化随机数生成器
    mt19937 gen(rd());
    // 定义均匀分布
    uniform_int_distribution<> dis(low, high);

    // 生成随机整数
    int randomInt = dis(gen);
    return randomInt;
}

//整数位数
int getDigitCount(int number) {
    // 将整数转换为字符串
    string numberString = to_string(abs(number));
    // 获取字符串的长度，即位数
    int digitCount = static_cast<int>(numberString.length());
    return digitCount;
}

void exitTest(string s){
    if (s == "q"){
        throw myExpection("已手动退出进程。");
    }
}