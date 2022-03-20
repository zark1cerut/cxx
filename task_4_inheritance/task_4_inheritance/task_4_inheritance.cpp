#include <iostream>
#include <string>


class Shop
{
protected:

    int rental_price;

    std::string address;

    


public:


    Shop()
    {

    }

    Shop(int rental_price, std::string address)
    {
        this->rental_price = rental_price;
        this->address = address;
       

    }

    void Print_Sh()
    {

        std::cout << "Address: " << address << "\nRental price: " << rental_price << std::endl;

    }

    ~Shop()
    {

    }
};


class Food_Sh : public Shop
{
private:
    std::string title;

public:


    Food_Sh()
    {

    }

    Food_Sh(int rental_price, std::string address, std::string title)
    {
        this->rental_price = rental_price;
        this->address = address;
        this->title = title;
    }

   




    void Print_Sh()
    {
        
        std::cout << "Address: "  << address << "\nTitle: " << title << "\nRental price: " << rental_price << std::endl;

    }

    ~Food_Sh()
    {

    }

};

class Chemicals_Sh : public Shop
{
private:

    std::string title;

public:

    Chemicals_Sh()
    {

    }






    Chemicals_Sh(int rental_price, std::string address, std::string title)
    {
        this->rental_price = rental_price;
        this->address = address;
        this->title = title;
    }






    void Print_Sh()
    {

        std::cout << "Address: " << address << "\nTitle: " << title << "\nRental price: " << rental_price << std::endl;

    }


    ~Chemicals_Sh()
    {

    }


};

class Hypermarket_Sh : public Shop
{
private:
    std::string title;

public:

    Hypermarket_Sh()
    {

    }




    Hypermarket_Sh(int rental_price, std::string address, std::string title)
    {
        this->rental_price = rental_price;
        this->address = address;
        this->title = title;
    }






    void Print_Sh()
    {

        std::cout << "Address: " << address << "\nTitle: " << title << "\nRental price: " << rental_price << std::endl;

    }

    ~Hypermarket_Sh()
    {

    }


};





int main()
{
   

    Shop s1 = Shop(21434, "ssffss");

    Food_Sh f1 = Food_Sh(350, "Masherova, 4", "Diskaunter");

    f1.Print_Sh();

    return 0;
}
