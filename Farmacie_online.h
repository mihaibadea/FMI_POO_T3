#ifndef FARMACIE_ONLINE_H
#define FARMACIE_ONLINE_H

#include "Farmacie.h"

#include <vector>


class Farmacie_online : public Farmacie
{
    public:
        Farmacie_online();
        Farmacie_online(std::string, int, std::map<std::string, long long>, std::string, int, double);
        virtual ~Farmacie_online()=default;
        Farmacie_online(const Farmacie_online&)=default;
        Farmacie_online& operator=(Farmacie_online &)=default;
        friend std::ostream & operator << (std::ostream &, Farmacie_online &);
        friend std::istream & operator >> (std::istream &, Farmacie_online &);
        int nr_viz();

    protected:

    private:
        std::tuple<std::string, int, double> info; // <url, nr_vizitatori, discount>
};

#endif // FARMACIE_ONLINE_H
