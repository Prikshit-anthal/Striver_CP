#include <bits/stdc++.h>
using namespace std;

int main()
{
    string r;
    cin >> r;

    unsigned long long NB = 0, NS = 0, NC = 0;
    for (auto i : r)
    {
        if (i == 'S')
            NS++;
        else if (i == 'C')
            NC++;
        else
            NB++;
    }

    unsigned long long nb, ns, nc;
    cin >> nb >> ns >> nc;

    unsigned long long pb, ps, pc;
    cin >> pb >> ps >> pc;

    unsigned long long money;
    cin >> money;

    if(NS==0) ns=0;
    if(NB==0) nb=0;
    if(NC==0) nc=0;

    unsigned long long count = (money + ns * ps + nc * pc + nb * pb) / (NS * ps + NB * pb + NC * pc);
    cout << count;

    return 0;
}