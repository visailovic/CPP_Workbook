struct Resident
{
    char name[20];
    char surname[20];
    Resident* leftNeighbour;
    Resident* rightNeighbour;
};

int main()
{
    Resident Pera = { "Petar", "Petrovic", 0, 0 };
    Resident Mika = { "Milos", "Milosevic", 0, 0 };
    Resident Laza = { "Lazar", "Lazarevic", 0, 0 };

    //   Pera <-> Mika <-> Laza
    Pera.rightNeighbour = &Mika;
    Mika.leftNeighbour = &Pera;
    Mika.rightNeighbour = &Laza;
    Laza.leftNeighbour = &Mika;

    //   Pera <-> Laza <-> Mika
    Pera.leftNeighbour = 0;
    Pera.rightNeighbour = &Laza;
    Pera.rightNeighbour->leftNeighbour = &Pera; //Equivalent to Laza.leftNeighbour;
    Pera.rightNeighbour->rightNeighbour = &Mika;//Equivalent to 
                                                //Laza.rightNeighbour;
    Pera.rightNeighbour->rightNeighbour->leftNeighbour = &Laza;//Equivalent to 
                                                               //Mika.leftNeighbour
    Pera.rightNeighbour->rightNeighbour->rightNeighbour = 0;//Equivalent to 
                                                            //Mika.rightNeighbour;

    //   Try to restore to the previous state: Pera <-> Mika <-> Laza
    Pera.leftNeighbour = 0;
    *Pera.rightNeighbour = Mika;// Did we really want this!?
               // *Pera.rightNeighbour is Laza!!!
    return 0;
}
