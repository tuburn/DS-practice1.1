#include<stdio.h>
#include<stdlib.h>
#define N 20
#define M 30
#define W 20

typedef struct{
    char stuname[20];
    int schnum;
    int score;
}Rank;
typedef struct{
    Rank ranks[6];
    int eventnum;
}Event;
typedef struct{
    int eventnum;
    int ranknum;
    char name[20];
    int score;
}Sch;
typedef struct{
    Sch sch[50];
}School;

Event events[50];
School schools[20];
int prizenum[6]={0};
int i,j,k,n,m,w;

int main(){

    /*����ģ��*/
    printf("������μӱ�����ѧУ���������ӱ�����Ŀ������Ů�ӱ�����Ŀ������\n");
    scanf("%d,%d,%d",&n,&m,&w);
    while(n>N||m>M||w>W){
        printf("�������ݴ������������루ѧУ����������20��������Ŀ����������30��Ů����Ŀ����������20����\n");
        scanf("%d,%d,%d",&n,&m,&w);
    }
    printf(" \n");
    for(i=1;i<=m+w;i++){
        printf("�������%d�����������\n",i);
        if(i%2==0){
            for(j=1;j<=3;j++){
                printf("�������%d��������ѧУ������\n",j);
                events[i].ranks[j].schnum=0;
                scanf("%d,%s",&events[i].ranks[j].schnum,events[i].ranks[j].stuname);
                while(events[i].ranks[j].schnum>n||events[i].ranks[j].schnum==0){
                    printf("�����ʽ����ѧУ����Ӧ������%d�������������룺\n",n);
                    scanf("%d,%s",&events[i].ranks[j].schnum,events[i].ranks[j].stuname);
                }
                switch(j){
                    case 1:events[i].ranks[j].score=5;break;
                    case 2:events[i].ranks[j].score=3;break;
                    case 3:events[i].ranks[j].score=2;break;
                }
            }
        }
        else{
            for(j=1;j<=5;j++){
                printf("�������%d��������ѧУ������\n",j);
                events[i].ranks[j].schnum=0;
                scanf("%d,%s",&events[i].ranks[j].schnum,events[i].ranks[j].stuname);
                printf("%d",events[i].ranks[j].schnum);
                while(events[i].ranks[j].schnum>n||events[i].ranks[j].schnum==0){
                    printf("�����ʽ����ѧУ����Ӧ������%d�������������룺\n",n);
                    scanf("%d,%s",&events[i].ranks[j].schnum,events[i].ranks[j].stuname);
                }
                switch(j){
                    case 1:events[i].ranks[j].score=7;break;
                    case 2:events[i].ranks[j].score=5;break;
                    case 3:events[i].ranks[j].score=3;break;
                    case 4:events[i].ranks[j].score=2;break;
                    case 5:events[i].ranks[j].score=1;break;
                }
            }
        }
    }

    /*���ݴ���ģ��*/
    for(k=1;k<=n;k++){
        for(i=1;i<=m+w;i++){
            if(i%2==0){
                for(j=1;j<=3;j++){
                    if(events[i].ranks[j].schnum==k){
                        prizenum[k]++;
                        schools[k].sch[prizenum[k]].eventnum=i;
                        schools[k].sch[prizenum[k]].ranknum=j;
                        schools[k].sch[prizenum[k]].score=events[i].ranks[j].score;
                        strcpy(schools[k].sch[prizenum[k]].name,events[i].ranks[j].stuname);
                    }
                }
            }
            else{
                for(j=1;j<=5;j++){
                    if(events[i].ranks[j].schnum==k){
                        prizenum[k]+=1;
                       // printf("%d  ",prizenum[k]);
                        schools[k].sch[prizenum[k]].eventnum=i;
                        schools[k].sch[prizenum[k]].ranknum=j;
                        schools[k].sch[prizenum[k]].score=events[i].ranks[j].score;
                        strcpy(schools[k].sch[prizenum[k]].name,events[i].ranks[j].stuname);
                    }
                }
            }
        }
    }

    /*���ģ��*/
    printf(" \n");
    printf(" \n");
    printf("��ѧУ�ɼ���\n");
    printf(" \n");
    for(k=1;k<=n;k++){
        printf("ѧУ%d�ĳɼ���\n",k);
        for(i=1;i<=prizenum[k];i++){
            printf("��Ŀ�ţ�%d    ���Σ�%d    ������%s    �÷֣�%d\n",schools[k].sch[i].eventnum,schools[k].sch[i].ranknum,schools[k].sch[i].name,schools[k].sch[i].score);
        }
        printf(" \n");
    }
    printf(" \n");
    printf("��ѧУ�����ֱܷ���\n");
    printf(" \n");
    int malesum=0,femalesum=0,sum=0;
    for(k=1;k<=n;k++){
        printf("ѧУ%d������ɼ�\n",k);
        for(i=1;i<=prizenum[k];i++){
            if(schools[k].sch[i].eventnum<=m){
                malesum+=schools[k].sch[i].score;
            }
            else{
                femalesum+=schools[k].sch[i].score;
            }
        }
        sum=malesum+femalesum;
        printf("У�ţ�%d    ���������ܷ֣�%d    Ů�������ܷ֣�%d    �ܷ֣�%d\n",k,malesum,femalesum,sum);
        printf(" \n");
    }
    return 0;
}
