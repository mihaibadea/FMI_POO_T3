#include "Farmacie.h"

#include <istream>
#include <ostream>


Farmacie::Farmacie() : nume(""), nr_ang(0), profit({})
{

}

Farmacie::Farmacie(std::string nume, int nr_ang, std::map<std::string, long long> profit) : nume(nume), nr_ang(nr_ang), profit(profit)
{

}

std::string Farmacie::denumire() const
{
    return nume;
}

std::ostream & operator << (std::ostream &out, Farmacie &f)
{
    if(f.nr_ang<20)
    {
        out<<"Farmacia "<<f.nume<<": "<<f.nr_ang<<" angajați\n";
    }
    else
    {
        out<<"Farmacia "<<f.nume<<": "<<f.nr_ang<<" de angajați\n";
    }

    for(auto &i : f.profit)
    {
        out<<"Profit "<<i.first<<": "<<i.second<<'\n';
    }
    out<<'\n';
    return out;
}
std::istream & operator >> (std::istream &in,  Farmacie &f)
{
    std::string nume, luna;
    int nr_ang, luni;
    long long pr;

    in>>nume>>nr_ang>>luni;

    f.nume=nume;
    f.nr_ang=nr_ang;

    for(int i=0; i<luni; i++)
    {
        in>>luna>>pr;
        f.profit[luna]=pr;
    }

    return in;
}

long long Farmacie::profit_total()
{
    long long rez;

    for(auto &i : profit)
    {
        rez+=i.second;
    }

    return rez;
}

int angajati()
{
    return nr_ang;
}
