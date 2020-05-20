#include "Farmacie_online.h"

#include <iostream>

Farmacie_online::Farmacie_online() : Farmacie("", 0, {})
{
    info = std::make_tuple("localhost", 0, 0.00);
}

Farmacie_online::Farmacie_online(std::string nume, int nr_ang, std::map<std::string, long long> profit, std::string url, int nr_viz, double discount) : Farmacie(nume, nr_ang, profit)
{
    info = std::make_tuple(url, nr_viz, discount);
}


std::ostream & operator << (std::ostream &out, Farmacie_online &f)
{
    out<<static_cast<Farmacie&>(f);

    out<<"Website: "<<std::get<0>(f.info)<<"; Număr vizitatori: "<<std::get<1>(f.info)<<"; Discount: "<<std::get<2>(f.info)<<"%\n\n";

    return out;
}


std::istream & operator >> (std::istream &in, Farmacie_online &f)
{
    std::string url;
    int nr_viz;
    double discount;


    in>>static_cast<Farmacie&>(f);

    in>>url>>nr_viz>>discount;

    f.info = std::make_tuple(url, nr_viz, discount);

    return in;
}

int Farmacie_online::nr_viz()
{
    return std::get<1>(info);
}
