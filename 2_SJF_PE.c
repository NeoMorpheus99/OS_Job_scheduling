#include <stdio.h>
#define LOOP(n) for (int i = 0; i < n; i++)

typedef struct Processtable
{
    int aT, bT, or, fT, rT, wT, tAT, rem, ter;
} process;

process ps[10];

void userinput(int n)
{
    LOOP(n) // defined in the macro
    {
        printf("\nEnter arrival Time: ");
        scanf("%d", &ps[i].aT);

        printf("Enter the Burst Time: ");
        scanf("%d", &ps[i].bT);

        // printf("Enter the order: ");
        // scanf("%d", &ps[i].or);

        ps[i].rem = ps[i].bT;
        ps[i].wT = 0;
    }
}

int allProcessTerminated(int n, process ps[])
{
    int i;
    for (i = 0; i < n; ++i)
        if (!ps[i].ter)
            return 0;
    return 1;
}

int nextProcessToRun(int n, process ps[], int ct)
{
    int min = 100;
    int x = -1;
    for (int i = 0; i < n; ++i)
        if (ps[i].aT <= ct && !ps[i].ter)
            if (ps[i].rem < min)
            {
                min = ps[i].rem ;
                x = i;
            }
    return x; // non terminated 
}
int main()
{
    int p;
    printf("Enter the Number of Prcoesses: ");
    scanf("%d", &p);

    // user input
    userinput(p);
    int ct = 0;
while(allProcessTerminated(p, ps) !=1)
{
    int x = nextProcessToRun(p, ps, ct);
    if (x == -1)
    {
        printf("t= %d idle\n", ct);
        ++ ct;
        continue;
    }
    if (ps[x].rem == ps[x].bT)
        ps[x].rT = ct - ps[x].aT;
    --ps[x].rem;

    if(ps[x].rem == 0)
        {
            ps[x].tAT = (ct + 1) - ps[x].aT;
            ps[x].ter =1;
        }

    for(int i=0; i<p; ++i)
        {
            if(x==i) 
                continue;
            if(ps[i].aT <= ct && !ps[i].ter)
                ++ps[i].wT;
        }
        printf("t = %d P%d\n", ct, x);
        ++ct;
}
    
    for(int i=0; i<p; i++)
        {
            printf("RT of P%d: %d\n", i, ps[i].rT);
            printf("WT of P%d: %d\n", i, ps[i].wT);
            printf("TAT of P%d: %d\n", i, ps[i].tAT);
            printf("\n\n");
        }
}