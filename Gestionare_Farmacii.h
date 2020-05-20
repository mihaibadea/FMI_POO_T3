#ifndef GESTIONARE_FARMACII_H
#define GESTIONARE_FARMACII_H

#include <vector>
#include <algorithm>

class ValoareInvalida : public std::exception
{
    public:
        ValoareInvalida()=default;
        virtual char const * what() const noexcept
        {
            return "Valoarea introdusă este invalidă.";
        }
};


template<class T>
class Gestionare_Farmacii
{
    public:
        static Gestionare_Farmacii* get()
        {
            if(!instanta)
            {
                instanta = new Gestionare_Farmacii();
            }
            return instanta;
        }

        Gestionare_Farmacii & operator+=(const T &f)
        {
            farmacii.push_back(f);
            index++;
            return *this;
        }
        void citeste()
        {
            int nr;

            std::cout<<"Introdu numărul de farmacii: ";
            try
            {
                std::cin>>nr;

                if(nr<=0)
                {
                    throw(ValoareInvalida());
                }

                T tmp;

                for(int i=0; i<nr; i++)
                {
                    std::cout<<"Introdu numele, numărul de angajați, numărul de luni de activitate și profitul pe fiecare lună sub forma (lună, valoare) pentru farmacia "<<i+1<<": ";
                    std::cin>>tmp;
                    *this+=tmp;
                }
            }
            catch(ValoareInvalida e)
            {
                    std::cout<<e.what()<<'\n';
            }

        }
        void afiseaza()
        {
            std::cout<<"----------------------------------------------------------\n";

            if(index==1)
            {
                std::cout<<"Lanțul #"<<id<<" are o farmacie, mai exact:\n\n";
            }
            else if(index!=0)
            {
                std::cout<<"Lanțul #"<<id<<" are "<<index<<" farmacii, mai exact: \n\n";
            }

            for(auto &i : farmacii)
            {
                std::cout<<i;
            }
        }


    protected:

    private:
        Gestionare_Farmacii()=default;
        Gestionare_Farmacii(const Gestionare_Farmacii&)=delete;
        Gestionare_Farmacii* operator=(const Gestionare_Farmacii&)=delete;
        static Gestionare_Farmacii *instanta;
        std::vector<T> farmacii;
        T unit;
        int index=0;
        int id=1999;
};

template<class T>
Gestionare_Farmacii<T> *Gestionare_Farmacii<T>::instanta=nullptr;


template<>
class Gestionare_Farmacii<Farmacie_online>
{
    public:
        static Gestionare_Farmacii* get()
        {
            if(!instanta)
            {
                instanta = new Gestionare_Farmacii();
            }
            return instanta;
        }
        Gestionare_Farmacii & operator+=(Farmacie_online &f)
        {
            viz+=f.nr_viz();
            index++;
            return *this;
        }
        void citeste()
        {
            int nr;

            std::cout<<"Introdu numărul de farmacii: ";

            try
            {
                std::cin>>nr;

                if(nr<=0)
                {
                    throw(ValoareInvalida());
                }

                Farmacie_online tmp;

                for(int i=0; i<nr; i++)
                {
                    std::cout<<"Introdu numele, numărul de angajați, numărul de luni de activitate, profitul pe fiecare lună sub forma (lună, valoare), adresa web și discount-ul aplicat pentru farmacia "<<i+1<<": ";
                    std::cin>>tmp;
                    *this+=tmp;
                }
            }
            catch(ValoareInvalida e)
            {
                std::cout<<e.what()<<'\n';
            }
        }
        void afiseaza()
        {
            if(index!=0)
            {
                std::cout<<"----------------------------------------------------------\n"
                         <<"Cele "<<index<<" farmacii au avut un total de "<<viz<<" vizitatori.\n";
            }

        }

    protected:

    private:
        Gestionare_Farmacii()=default;
        Gestionare_Farmacii(const Gestionare_Farmacii&)=delete;
        Gestionare_Farmacii* operator=(const Gestionare_Farmacii&)=delete;
        static Gestionare_Farmacii *instanta;
        int index=0;
        int id=1999;
        int viz=0;
};

Gestionare_Farmacii<Farmacie_online> *Gestionare_Farmacii<Farmacie_online>::instanta=nullptr;

#endif // GESTIONARE_FARMACII_H

