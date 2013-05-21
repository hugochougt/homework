#include<iostream>

using namespace std;

int Direction(int *pi, int *pj, int *pk)
{
    int pa[2], pb[2];
    
    pa[0] = pk[0] - pi[0];
    pa[1] = pk[1] - pi[1];
    
    pb[0] = pj[0] - pi[0];
    pb[1] = pj[1] - pi[1];
    
    return pa[0] * pb[2] - pa[1] * pb[0];
}

bool On_Segment(int *pi, int *pj, int *pk)
{
    int Xmax, Xmin, Ymax, Ymin;
    if(pi[0] > pj[0])
    {
        Xmax = pi[0];
        Xmin = pj[0];
    }
    else
    {
        Xmin = pi[0];
        Xmax = pj[0];
    }
    if(pi[1] > pj[1])
    {
        Ymax = pi[1];
        Ymin = pj[1];
    }
    else
    {
        Ymin = pi[1];
        Ymax = pj[1];
    }
    if( (Xmin <= pk[0] && Xmax >= pk[0]) && (Ymin <= pk[1] && Ymax >= pk[1]) )
        return true;
    else
        return false;
}

bool Segment_Intersect(int *p1, int *p2, int *p3, int *p4)
{
    int d1 = Direction(p3, p4, p1);
    int d2 = Direction(p3, p4, p2);
    int d3 = Direction(p1, p2, p3);
    int d4 = Direction(p1, p2, p4);
    if( ( (d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0) ) &&
        ( (d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0) ) )
        return true;
    else if((0 == d1) && On_Segment(p3, p4, p1))
        return true;
    else if((0 == d2) && On_Segment(p3, p4, p2))
        return true;
    else if((0 == d3) && On_Segment(p1, p2, p3))
        return true;
    else if((0 == d4) && On_Segment(p1, p2, p4))
        return true;
    else
        return false;
}

int main()
{
    int p1[2],p2[2],p3[2],p4[2];
    int i,j;
    while(1)
    {
        cin >> p1[0] >> p1[1];
        cin >> p2[0] >> p2[1];
        cin >> p3[0] >> p3[1];
        cin >> p4[0] >> p4[1];
        if(Segment_Intersect(p1, p2, p3, p4))
            cout << "Intersect" << endl;
        else
            cout << "Not intersct" << endl;
    }
    return 0;
}
