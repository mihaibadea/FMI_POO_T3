#include <iostream>
#include "Farmacie.h"
#include "Farmacie_online.h"
#include "Gestionare_Farmacii.h"

int main()
{

    int opt;

    std::cout<<"Te rog alege o opțiune: \n (1) Lanț de farmacii generice \n (2) Lanț de farmacii online \n (3) Mixt \n";
    std::cin>>opt;


    if(opt==1)
    {
        Gestionare_Farmacii<Farmacie> *sefu = Gestionare_Farmacii<Farmacie>::get();

        sefu->citeste();

        sefu->afiseaza();

        delete sefu;

    }

    else if(opt==2)
    {
        Gestionare_Farmacii<Farmacie_online> *sefu = Gestionare_Farmacii<Farmacie_online>::get();

        sefu->citeste();

        sefu->afiseaza();

        delete sefu;
    }

    else if(opt==3)
    {
        std::vector<Farmacie*> f;


        bool fin=0;

        int optt;

        while(!fin)
        {

            std::cout<<"Introdu (1) pentru farmacie fizică, (2) pentru farmacie online, (0) pentru a ieși din program\n";
            std::cin>>optt;
            if(optt==1)
            {
                std::cout<<"Introdu numele, numărul de angajați, numărul de luni de activitate și profitul pe fiecare lună sub forma (lună, valoare) pentru farmacie:\n";
                Farmacie *tmp = new Farmacie;
                std::cin>>*tmp;

                f.push_back(tmp);

                std::cout<<"Am reținut.\n";
            }
            else if(optt==2)
            {
                std::cout<<"Introdu numele, numărul de angajați, numărul de luni de activitate, profitul pe fiecare lună sub forma (lună, valoare), adresa web și discount-ul aplicat pentru farmacie:\n";
                Farmacie_online *tmp = new Farmacie_online;
                std::cin>>*tmp;

                f.push_back(tmp);

                std::cout<<"Am reținut.\n";
            }

            else
            {
                fin=1;

                std::sort(f.begin(), f.end(), [](const Farmacie* a, const Farmacie *b)
                {
                    return a->profit_total() > b->profit_total();
                }
                );

                int toptrei=0;


                if(f.size()>=3)
                {

                    for(int i=0; i<3; i++)
                    {
                        if(dynamic_cast<Farmacie_online*>(f[i])) toptrei++;
                    }
                    std::cout<<"Dintre primele 3 cele mai profitabile farmacii, "<<toptrei<<" sunt online.\n";
                }

                else
                {
                    std::cout<<"Ai introdus mai puțin de 3 farmacii.\n";
                }

                for(int i=0; i<f.size(); i++)
                {
                    delete f[i];
                }


            }
        }

    }

    else
    {
        std::cout<<"Te rugăm să încerci mai târziu. :(\n";
    }


    return 0;
}
