// Passing multiple arguments via a structure

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

struct Student{
        int regno;
        char name[20];
        int marks;
};

void *myfunc(void *arg){
        printf("Student Details are \n");
        struct Student *ps = (struct Student *)arg;
        printf("%d %s %d\n", ps->regno, ps->name, ps->marks);
        return NULL;
}

int main(){
        struct Student s1 = {165,"Ankith Kumar",72};

        pthread_t t1;
        pthread_create(&t1 , NULL, myfunc , &s1);
        pthread_exit(NULL);

        return 0;
}
