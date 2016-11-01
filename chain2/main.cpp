//
//  main.cpp
//  chain2
//
//  Created by Jep Xia on 16/10/31.
//  Copyright © 2016年 Jep Xia. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
using namespace std;
#ifndef null
#define null 0
#endif

typedef struct node
{
    int coefficient; //系数
    int exponentn;	//指数
    struct node *next;
}Elemsn;

Elemsn *createElemsn(int number);

int main(int argc, char const *argv[])
{
    
    int number1, number2;/*ms用来存放结点的个数*/
    
    Elemsn *last;
    
    printf("Please input node number:");
    cin >> number1;
    Elemsn *head1 = createElemsn(number1);
    
    printf("Please input node number:");
    cin >> number2;
    Elemsn *head2 = createElemsn(number2);
    
    int *shishikan;
    shishikan = (int *)malloc((number1 + number2) * sizeof(int));
    
    
    for (last = head1; last != NULL; last = last->next)//链接链表
    {
        if (last->next == NULL) {
            last->next = head2;
            break;
        }
    }
    int i = 0;
    for (Elemsn *p = head1; p != NULL; p = p->next, i++)
    {
        shishikan[i] = p->exponentn;
    }
    for (int j = 0, i, temp; j < (number2 + number1) - 1; j++) {
        for (i = 0; i < (number2 + number1) - 1 - j; i++) {
            if (shishikan[i] > shishikan[i + 1]) {
                temp = shishikan[i];
                shishikan[i] = shishikan[i + 1];
                shishikan[i + 1] = temp;
            }
        }
    }//对shishikan进行排序
    
    for (int i = 0; i < number2 + number1 - 1; i++)
    {
        if (shishikan[i] == shishikan[i + 1]){
            shishikan[i + 1] = -1;
        }
    }
    for (int i = 0; i < number2 + number1; i++) {
        cout << shishikan[i];
    }
    Elemsn *head, *ap;
    head = ap = (Elemsn *)malloc(sizeof(Elemsn));
    head->coefficient = 0;
    for (Elemsn *p = head1; p != NULL; p = p->next)
    {
        if (shishikan[0] == p->exponentn)
        {
            head->coefficient += p->coefficient;
            cout << head->coefficient;
            head->exponentn = p->exponentn;
            cout << head->exponentn<<endl;
        }
    }
    head->next = NULL;/*创立头结点*/
    for (int i = 1; i < number2 + number1; i++){
        ap->next = (Elemsn *)malloc(sizeof(Elemsn));
        ap->coefficient = 0;
        for (Elemsn *p = head1; p != NULL; p = p->next)
        {
            if (shishikan[i] == p->exponentn)
            {
                ap->coefficient += p->coefficient;
                ap->exponentn = p->exponentn;
            }
        }
        ap->next->next = NULL;
        ap = ap->next;
    }
    for (Elemsn *p = head; p != NULL; p = p->next, i++)
    {
        cout << "系数:" << p->coefficient;
        cout << "指数:" << p->exponentn;
    }
    printf("\n");
    system("pause");
    return 0;
    
}

Elemsn *createElemsn(int number)  {
    
    Elemsn *head, *p;
    
    head = p = (Elemsn *)malloc(sizeof(Elemsn));
    printf("Please input data:");
    
    int xishu, zhishu;
    cin >> xishu >> zhishu;
    head->coefficient = xishu;
    head->exponentn = zhishu;
    head->next = NULL;/*创建第一个结点，因为是头结点，所以单独写出来*/
    
    for (int i = 0; i < number - 1; i++)/*创建后面的ms-1个结点*/
    {
        p->next = (Elemsn *)malloc(sizeof(Elemsn));
        printf("Please input data:");
        cin >> xishu >> zhishu;
        p->next->coefficient = xishu;
        p->next->exponentn = zhishu;
        p->next->next = NULL;
        p = p->next;
    }
    return head;
}
