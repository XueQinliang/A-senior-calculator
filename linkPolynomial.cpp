#include "linkpolynomial.h"
Status create_LinkPolynomial(LinkList& L){
    ElemType num=0,pow=0;
    int sign=1;
    L=(LinkList)malloc(sizeof(LNode));
    L->pow=~(1<<31);//把头结点的指数设为最大正整数，以便向后有序插入
    L->num=0;
    L->next=NULL;
    while(1){
        num=0;
        pow=0;
        if(scanf("%dx^%d",&num,&pow)==2){
            LinkList p=(LinkList)malloc(sizeof(LNode));
            p->num=num*sign;
            p->pow=pow;
            if(p->pow>=L->pow){
                cout<<"error\n";
                return OVERFLOW;
            }
            LinkList h=L;
            while(!(h->pow>p->pow&&((h->next==NULL)||(h->next->pow<=p->pow)))){
                h=h->next;
            }
            if(h->next!=NULL&&p->pow==h->next->pow){
                h->next->num+=p->num;
                if(h->next->num==0){
                    LinkList dele=h->next;
                    h->next=h->next->next;
                    free(dele);
                }
            }else{
                p->next=h->next;
                h->next=p;
            }
        }else{
            cout<<"error\n";
            string s;
            getline(cin,s,'\n');//回收错误的字符
            return ERROR;
        }
        char d=getchar();
        if(d=='+') sign=1;//判断下一项的符号
        if(d=='-') sign=-1;
        if(d=='\n') break;
    }
    return OK;
}
Status search(LinkList L,int spow,int &snum){//搜索某一链表多项式中某一项的系数值
    if(L==NULL)return ERROR;
    LinkList p=L->next;
    while(p!=NULL){
        if(p->pow==spow){
            snum=p->num;
            return OK;
        }
        p=p->next;
    }
    snum=0;
    return OK;
}
Status DestroyLink(LinkList &L){
    LinkList p=L,q=p;
    while(q!=NULL){//删掉所有结点
        q=p->next;
        free(p);
        p=q;
    }
    return OK;
}
Status ClearLink(LinkList &L){
    LinkList p=L->next,q=p;
    while(q!=NULL){//保留头结点，删掉剩下结点
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;
    return OK;
}
Status show_Link(LinkList L){
    LinkList p=L->next;
    if(p==NULL) printf("0");
    while(p!=NULL){
        if(p->num!=1)
            if(p->pow==1)
                printf("%dx",p->num);
                else if(p->pow==0)printf("%d",p->num);
                else printf("%dx^%d",p->num,p->pow);
        else{
            if(p->pow==1)
                printf("x");
            else if(p->pow==0)printf("1");
            else printf("x^%d",p->pow);
        }
        if(p->next!=NULL&&p->next->num>0)
        printf("+");
        p=p->next;
    }
    return OK;
}
Status addLink(LinkList &L,LinkList a,LinkList b){
    L=(LinkList)malloc(sizeof(LNode));
    L->pow=~(1<<31);
    L->num=0;
    L->next=NULL;
    LinkList la=a->next,lb=b->next,p=L;
    while(la!=NULL&&lb!=NULL){
        if(la->pow>lb->pow){
            LinkList newLNode=(LinkList)malloc(sizeof(LNode));
            newLNode->pow=la->pow;
            newLNode->num=la->num;
            newLNode->next=p->next;
            p->next=newLNode;
            la=la->next;
            p=p->next;
        }else if(la->pow<lb->pow){
            LinkList newLNode=(LinkList)malloc(sizeof(LNode));
            newLNode->pow=lb->pow;
            newLNode->num=lb->num;
            newLNode->next=p->next;
            p->next=newLNode;
            lb=lb->next;
            p=p->next;
        }else{
            LinkList newLNode=(LinkList)malloc(sizeof(LNode));
            newLNode->pow=lb->pow;
            newLNode->num=lb->num+la->num;
            if(newLNode->num!=0){
                newLNode->next=p->next;
                p->next=newLNode;
                p=p->next;
            }else free(newLNode);
            la=la->next;
            lb=lb->next;
        }
    }
    while(la!=NULL){
        LinkList newLNode=(LinkList)malloc(sizeof(LNode));
        newLNode->pow=la->pow;
        newLNode->num=la->num;
        newLNode->next=p->next;
        p->next=newLNode;
        p=p->next;
        la=la->next;
    }
    while(lb!=NULL){
        LinkList newLNode=(LinkList)malloc(sizeof(LNode));
        newLNode->pow=lb->pow;
        newLNode->num=lb->num;
        newLNode->next=p->next;
        p->next=newLNode;
        p=p->next;
        lb=lb->next;
    }
    return OK;
}
Status subLink(LinkList &L,LinkList a,LinkList b){//原理同加法
    L=(LinkList)malloc(sizeof(LNode));
    L->pow=~(1<<31);
    L->num=0;
    L->next=NULL;
    LinkList la=a->next,lb=b->next,p=L;
    while(la!=NULL&&lb!=NULL){
        if(la->pow>lb->pow){
            LinkList newLNode=(LinkList)malloc(sizeof(LNode));
            newLNode->pow=la->pow;
            newLNode->num=la->num;
            newLNode->next=p->next;
            p->next=newLNode;
            la=la->next;
            p=p->next;
        }else if(la->pow<lb->pow){
            LinkList newLNode=(LinkList)malloc(sizeof(LNode));
            newLNode->pow=lb->pow;
            newLNode->num=-lb->num;
            newLNode->next=p->next;
            p->next=newLNode;
            lb=lb->next;
            p=p->next;
        }else{
            LinkList newLNode=(LinkList)malloc(sizeof(LNode));
            newLNode->pow=lb->pow;
            newLNode->num=-lb->num+la->num;
            if(newLNode->num!=0){
                newLNode->next=p->next;
                p->next=newLNode;
                p=p->next;
            }else free(newLNode);
            la=la->next;
            lb=lb->next;
        }
    }
    while(la!=NULL){
        LinkList newLNode=(LinkList)malloc(sizeof(LNode));
        newLNode->pow=la->pow;
        newLNode->num=la->num;
        newLNode->next=p->next;
        p->next=newLNode;
        p=p->next;
        la=la->next;
    }
    while(lb!=NULL){
        LinkList newLNode=(LinkList)malloc(sizeof(LNode));
        newLNode->pow=lb->pow;
        newLNode->num=-lb->num;
        newLNode->next=p->next;
        p->next=newLNode;
        p=p->next;
        lb=lb->next;
    }
    return OK;
}
LinkList derivate_linkPolynomial(LinkList L){
    LinkList head;
    LinkList tail;
    head=(LinkList)malloc(sizeof(LNode));
    head->pow=~(1<<31);//把头结点的指数设为最大正整数，以便向后有序插入
    head->num=0;
    head->next=NULL;
    tail=head;
    LinkList p=L->next;
    int num=0;
    int pow=0;
    while(p!=NULL){
        num=p->num*p->pow;
        if(p->pow>0){
            pow=p->pow-1;
            LinkList newnode=(LinkList)malloc(sizeof(LNode));
            newnode->num=num;
            newnode->pow=pow;
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        p=p->next;
    }
    return head;
}
LinkList MultLink(LinkList L1,LinkList L2){
    LinkList p1,p2;
    p1=L1->next;
    p2=L2->next;
    LinkList head=(LinkList)malloc(sizeof(LNode));
    head->pow=~(1<<31);
    head->num=0;
    head->next=NULL;
    while(p1!=NULL){
        p2=L2->next;
        while(p2!=NULL){
            LinkList newnode=(LinkList)malloc(sizeof(LNode));
            newnode->num=p1->num*p2->num;
            if(newnode->num==0){
                p2=p2->next;
                continue;
            }
            newnode->pow=p1->pow+p2->pow;
            newnode->next=NULL;
            LinkList insert_pos=head;
            while(insert_pos->next!=NULL&&insert_pos->next->pow>newnode->pow){
                insert_pos=insert_pos->next;
            }
            if(insert_pos->next!=NULL&&insert_pos->next->pow==newnode->pow){
                insert_pos->next->num+=newnode->num;
                if(insert_pos->next->num==0){
                    LinkList de=insert_pos->next;
                    insert_pos->next=insert_pos->next->next;
                    free(de);
                }
            }else{
                newnode->next=insert_pos->next;
                insert_pos->next=newnode;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
    return head;
}
