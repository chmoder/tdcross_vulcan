/*
   Thomas Cross
    FILE srec.h
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Srec {
    char fname[10];
    char initial;
    char lname[10];
    unsigned long sid;
    float gpa;
};

enum {
    lname_cmp = 1,
    fname_cmp = 2,
    sid_cmp = 3,
    gpa_cmp = 4
};

struct Srec *newSrec(void);
void initSrec(struct Srec *);
void printSrec(struct Srec *);
void stringSrec(struct Srec *, char *);
void setLname(struct Srec *, const char *);
void setInitial(struct Srec *, char);
void setFname(struct Srec *, const char *);
void setSid(struct Srec *, unsigned long);
void setGpa(struct Srec *, float);
void setSrec(struct Srec *, const char *, char, const char *, unsigned long, float);
void copySrec(struct Srec *, struct Srec *);



struct Srec *newSrec(void)
{
    struct Srec *srec = (struct Srec *)malloc(1 * sizeof(struct Srec));
    initSrec(srec);
    return srec;
}

void initSrec(struct Srec *srec)
{
    srec->lname[0] = '\0';
    srec->initial = '\0';
    srec->fname[0] = '\0';
    srec->sid = 0;
    srec->gpa = 0;
}

void printSrec(struct Srec *srec)
{
    printf("| %05lu | %-9s | %-9s | %c | %-1.2f |\n", srec->sid, srec->lname, srec->fname, srec->initial, srec->gpa);

}

void stringSrec(struct Srec *srec, char *print_buf)
{
    char temp_str[BUFSIZ];
    sprintf(temp_str, "| %05lu | %-9s | %-9s | %c | %-1.2f |\n", srec->sid, srec->lname, srec->fname, srec->initial, srec->gpa);
    strcat(print_buf, temp_str);
}


void setLname(struct Srec *srec, const char *lname)
{
    strcpy(srec->lname, lname);
}

void setInitial(struct Srec *srec, char initial)
{
    srec->initial = initial;
}

void setFname(struct Srec *srec, const char *fname)
{
   strcpy(srec->fname, fname);
}

void setSid(struct Srec *srec, unsigned long sid)
{
    srec->sid = sid;
}

void setGpa(struct Srec *srec, float gpa)
{
    srec->gpa = gpa;
}

void setSrec(struct Srec *srec, const char *lname, char initial, const char *fname, unsigned long sid, float gpa)
{
    setLname(srec, lname);
    setInitial(srec, initial);
    setFname(srec, fname);
    setSid(srec, sid);
    setGpa(srec, gpa);
}

/*
    Copy from b to a 
*/
void copySrec(struct Srec *a, struct Srec *b)
{
    strcpy(a->fname, b->fname);
    strcpy(a->lname, b->lname);
    a->initial = b->initial;
    a->sid = b->sid;
    a->gpa = b->gpa;
}
