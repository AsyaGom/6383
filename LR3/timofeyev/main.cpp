// 
// Лабораторная работа №3
// main.cpp
// Тимофеев Дмитрий, группа 6383
// 06.10.17
//
// Линейные структуры данных: стек, очередь, дек. 


#include <iostream>
#include<fstream>
#include"stack.h"

int readString(Stack<char> &st, std::istream &in){
    while(true){
        int c=in.get();
        if(c==EOF||c=='\n')return c;
        st.push(c);
    }
}

void writeString(Stack<char> &st, std::ostream &out){
    while(!st.isNull())out.put(st.pop());
    out.put('\n');
}

void proc(std::istream &in,std::ostream &out){
    Stack<char> stack;
    char ret;
    do{
        ret=readString(stack, in);
        writeString(stack, out);
    }while(ret!=EOF);
}


int main()
{
    std::ifstream input ("input.txt");
    std::ofstream output("output.txt");
    if(!input){
        std::cout<<"Входной файл не открыт!"<<std::endl;
        return -1;
    }
    proc(input,output);
    return 0;
}
