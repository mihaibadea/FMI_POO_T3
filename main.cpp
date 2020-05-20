#include <iostream>
#include "Farmacie.h"
#include "Farmacie_online.h"
#include "Gestionare_Farmacii.h"


/*bool poatefireturnatin14zile(auto societate, std::string produs)
{
    Farmacie_online f;
    return typeid(societate) == typeid(f);
}*/


int main()
{

    int opt;

    std::cout<<"Te rog alege o opțiune: \n (1) Lanț de farmacii generice \n (2) Lanț de farmacii online \n";
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
    else
    {
        std::cout<<"Te rugăm să încerci mai târziu. :(\n";
    }


    return 0;
}
