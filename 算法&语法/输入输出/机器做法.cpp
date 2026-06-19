#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

struct Process {
    int handle;
    double cpu_time;
    double memory;
    int pid;
    string name;
};

bool compare(const Process &a, const Process &b) {
    return a.cpu_time > b.cpu_time;
}

int main() {
    int n;
    cin >> n;
    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        cin >> processes[i].handle >> processes[i].cpu_time >> processes[i].memory >> processes[i].pid >> processes[i].name;
    }

    sort(processes.begin(), processes.end(), compare);

    for (const auto &process : processes) {
        cout << setw(8) << process.handle << " "
             << setw(10) << fixed << setprecision(2) << process.cpu_time << " "
             << setw(10) << fixed << setprecision(2) << process.memory << " "
             << setw(8) << process.pid << " "
             << left << process.name << endl;
    }

    return 0;
}
/*
做一个C+ +的题目。给出一个进程信息列表，要求按占用处理器时间从大到小排序后输出，每条进程信息包含:句柄、占用处理器时间（以秒为单位），占用内存量（以兆字节为单位），进程ID以及进程名称。
输入:第1行是一个正整数n（n小于等于100），表示进程信息的条数。接下来有n行，每行包含一个进程的相关信息，依次为:
①1个整数（小于1000000），表示句柄；
②1个实数（小于1000000），表示占用处理器时间；
③1个实数（小于1000000），表示占用内存量；
④1个整数（小于1000000），表示进程ID；
⑤1个字符串，长度不超过30，表示进程名称。
相隔两项数据之间用一个空格隔开。
输出:共n行，表示将进程信息按占用处理器时间从大到小排序输出结果。在一行输出的进程信息依次是:
①句柄（占8个字符宽度，右对齐）；
②占用处理器时间（占10个字符宽度，保留2位小数，右对齐，只显示数值，不显示单位）；
③占用内存量（占10个字符宽度，保留2位小数，右对齐，只显示数值，不显示单位）；
④进程ID（占8个字符宽度，右对齐）；
⑤进程名称（按字符串实际长度输出，左对齐）。
注意:相邻两项之间有一个额外的空格，要求严格按照给定的格式输出各项数据。
