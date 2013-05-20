//Airport simulation
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define MAX 3
#define ARRIVE 0
#define DEPART 1

struct plane
{
    int id;
    int tm;    
};

struct queue
{
    int count;
    int front;
    int rear;
    struct plane p[MAX];
};

void initqueue(struct queue *);
void addqueue(struct queue *, struct plane);
struct plane delqueue(struct queue *);
int size(struct queue);
int empty(struct queue);
int full(struct queue);

void initqueue(struct queue *pq)
{
    pq -> count = 0;
    pq -> front = 0;
    pq -> rear = -1;
}

void addqueue(struct queue * pq, struct plane item)
{
    if(pq -> count >= MAX)
    {
        printf("\nQueue is full.\n");
        return ;
    }
    (pq -> count)++;
    pq -> rear = (pq -> rear + 1) % MAX;
    pq -> p[pq -> rear] = item;
}

struct plane delqueue(struct queue *pq)
{
    struct plane pl;
    if(pq -> count <= 0)
    {
        printf("\nQueue is empty.\n");
        pl.id = 0;
        pl.tm = 0;
    }
    else
    {
        (pq -> count)--;
        pl = pq -> p[pq -> front];
        pq -> front = (pq -> front + 1) % MAX;    
    }
    return pl;
}

int size(struct queue q)
{
    return q.count;    
}

int empty(struct queue q)
{
    return (q.count <= 0);    
}

int full(struct queue q)
{
    return (q.count >= MAX);    
}

struct airport
{
    struct queue landing;
    struct queue takeoff;
    struct queue *pl;
    struct queue *pt;
    int idletime;
    int landwait, takeoffwait;
    int nland, nplanes, nrefuse, ntakeoff;
    struct plane pln;
};

void initairport(struct airport *);
void start(int *, double *, double *);
void newplane(struct airport *, int , int );
void refuse(struct airport *, int );
void land(struct airport *, struct plane , int);
void fly(struct airport *, struct plane , int);
void idle(struct airport *, int );
void conclude(struct airport *, int );
int randomnumber(double );
void apaddqueue(struct airport *, char );
struct airport apdelqueue(struct airport *, char );
int apsize(struct airport , char );
int apfull(struct airport , char );
int apempty(struct airport , char );
void myrandomize();

void initairport(struct airport *ap)
{
    initqueue( &(ap -> landing) );
    initqueue( &(ap -> takeoff) );
    ap -> pl = &(ap -> landing);
    ap -> pt = &(ap -> takeoff);
    ap -> nplanes = ap -> nland = ap -> ntakeoff = ap -> nrefuse = 0;
    ap -> landwait = ap -> takeoffwait = ap -> idletime = 0;
}

void start(int *endtime,double *expectarrive, double *expectdepart)
{
    int flag = 0;
    char wish;
    printf("\nProgram that simulates an aorport with only one runway\n");
    printf("One plane can land or depart in each unit of time\n");
    printf("Up to %d planes can be waiting to land or take off at any time\n",MAX);
    printf("how many units of time will the simulation run?\n");
    scanf("%d",&endtime);
    myrandomize();
    do
    {
        printf("\nExpected number of arrivals per unit time?\n");
        scanf("%lf",expectarrive);
        printf("\nExpected number of departures per unit time?\n");
        scanf("%lf",expectdepart);
        if(*expectarrive < 0.0 || *expectdepart < 0.0)
        {
            printf("These numbers must be nonnegative\n");
            flag = 0;    
        }
        else
        {
            if(*expectdepart + *expectarrive > 1.0)
            {
                printf("The airport will become saturated. Read new numbers?\n");
                scanf("%c%*c",&wish);
                if(tolower(wish) == 'y')
                    flag = 0;
                else
                    flag = 1;
            }
            else
                flag = 1;
        }
    }while(flag == 0);
}
void newplane(struct airport *ap, int curtime, int action)
{
    (ap -> nplanes)++;
    ap -> pln.id = ap -> nplanes;
    ap -> pln.tm = curtime;
    switch(action)
    {
        case ARRIVE:
            printf("\nPlane %d ready to land\n",ap -> nplanes);
            break;
        case DEPART:
            printf("\nPlane %d ready to take off\n",ap -> nplanes);
            break;    
    }
}

void refuse(struct airport *ap, int action)
{
    switch(action)
    {
        case ARRIVE:
            printf("\tplane %d directd to another airport\n",ap -> pln.id);
            break;
        case DEPART:
            printf("\tplane %d told to try later\n",ap -> pln.id);
            break;    
    }    
    (ap -> nrefuse)++;
}

void land(struct airport *ap, struct plane pl, int curtime)
{
    int wait;
    wait = curtime - pl.tm;
    printf("%d: Plane %d landed ",curtime, pl.id);
    printf("in queue %d units \n",wait);
    (ap -> nland)++;
    (ap -> landwait) += wait;  
}

void fly(struct airport *ap, struct plane pl, int curtime)
{
    int wait;
    wait = curtime - pl.tm;
    printf("%d: Plane %d take off ",curtime, pl.id);
    printf("in queue %d units \n",wait);
    (ap -> ntakeoff)++;
    (ap -> takeoffwait) += wait;  
}

void idle(struct airport *ap, int curtime)
{
    printf("%d: Runway is idle\n",curtime);
    ap -> idletime++;    
}

void conclude(struct airport *ap, int endtime)
{
    printf("\tSimulation has concluded after %d units\n",endtime);
    printf("\tTotal number of planes processed: %d\n",ap -> nplanes);
    printf("\tNumber of planes landed: %d\n",ap -> nland);
    printf("\tNumber of planes taken off: %d\n",ap -> ntakeoff);
    printf("\tNumber of planes refused use: %d\n",ap -> nrefuse);
    printf("\tNimber of planes left ready to land: %d\n",apsize(*ap, 't'));
    if(endtime > 0)
        printf("\tPercentage of time runway idle: %lf\n",((double)ap -> idletime / endtime) * 100.0);
    if(ap -> nland > 0)
        printf("\tAverage wait time to land: %lf\n",((double)ap -> landwait / ap -> nland));
    if(ap -> ntakeoff > 0)
        printf("Average wait time to take off: %lf\n",((double)ap -> takeoffwait / ap -> ntakeoff));
}
