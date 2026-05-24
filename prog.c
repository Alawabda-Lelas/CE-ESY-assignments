#include <stdio.h>
#include <string.h>
#define SIZE 20

char buffer[SIZE];
int head = 0;    // ﻣﺆﺷﺮ اﻟﻘﺮاءة
int tail = 0;    // ﻣﺆﺷﺮ اﻟﻜﺘﺎﺑﺔ
int count = 0;   // ﻋﺪد اﻟﻌﻨﺎﺻﺮ اﻟﻤﻮﺟﻮدة اﻟﻤﺨﺰن //

void init() {
    head = 0;
    tail = 0;
    count = 0;}

    //الإدخال (الكتابة )
void enqueue(char x) {
    if (isFull()){
        printf("overflow! cant add '%c'\n",x);
        return;
    }
    buffer[tail]=x;
    tail= (tail + 1) % SIZE;
    count ++; }

    // الإزالة (القراءة)
char dequeue() {
    if (isEmpty()){
        printf("underflow\n");
        return '\0';
    }
    char val = buffer[head];
    head = (head + 1 ) % SIZE;
    count --;
    return val; }

    // حالة إمتلاء المخزن
    int isFull() {
        return count == SIZE;
    }

    //حالة فراغ المخزن
    int isEmpty() {
        return count == 0;
    }

    int main() {
        char name [50];
        init();

        //إدخال الاسم
        printf("Enter your name: ");
        scanf("%s", name);

        // إضافة CE-ESY
        strcat(name, " CE-ESY");
        for (int i = 0; name[i] != '\0'; i++) {
            enqueue(name[i]);
        }
        // قراءة وطباعة
        printf("Result: ");
        while (count > 0) {
            printf("%c",dequeue());
        }
       // تأكيد أن الرتل فارغ
        if (isEmpty()) {
           printf("\nbufer is empty\n");
          return '\0' ; 
        }
        return 0;
        }