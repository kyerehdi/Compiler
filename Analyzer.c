//Add program description, author name, last edit date as in the project1
//Do not modify anything below this line

#include <stdio.h>
#include <stdlib.h>
#include "p2-support.h"


struct Email {
    char sender[50];
    char receiver[50];
    char subject[200];
    char body[2000];
    struct sent_date{
int month;
int day;
int year;
    };
int ID;
};
struct Mailbox {

};

int main(){
    struct Mailbox* ib;
    ib = (struct Mailbox*) malloc(sizeof(struct Mailbox));
    initialize(ib);
    display_inbox_menu(ib);
    free (ib);
    return 0;
}
