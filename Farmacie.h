#ifndef FARMACIE_H
#define FARMACIE_H

#include <string>
#include <map>

class Farmacie
{
    public:
        Farmacie();
        Farmacie(std::string, int, std::map<std::string, long long>);
        virtual ~Farmacie()=default;
        std::string denumire() const;
        friend std::ostream & operator << (std::ostream &, Farmacie &);
        friend std::istream & operator >> (std::istream &, Farmacie &);
        Farmacie(const Farmacie&)=default;
        Farmacie& operator=(Farmacie &)=default;
        long long profit_total();
        int angajati();

    protected:
        std::string nume;
        int nr_ang;
        std::map<std::string, long long> profit;

    private:
};

#endif // FARMACIE_H
