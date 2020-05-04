#include <iostream>
#include <thread>

class Vehicle
{
public:
    Vehicle() : _id(0), _name("a") {}
    void addID(int id) { _id = id; }
    void printID()
    {
        std::cout << "Vehicle ID=" << _id << std::endl;
    }

    void setName(std::string name) { _name = name; }
    void printName()
    {
        std::cout << "Vehicle Name=" << _name << std::endl;
    }

private:
    int _id;
    std::string _name;
};

int main()
{
    // create thread
    Vehicle v1, v2;

    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t = std::thread(&Vehicle::addID, v, 5); // shared_pointer
    

    //std::thread t1 = std::thread(&Vehicle::addID, v1, 1); // call member function on object v
    //std::thread t2 = std::thread(&Vehicle::addID, &v2, 2); // call member function on object v

    std::thread t2 = std::thread(&Vehicle::setName, v,  "name");
    // wait for thread to finish
    t.join();
    //t1.join();
    t2.join();

    // print Vehicle id
    
    v->printName();
    v->printID();
    //v2.printID();

    return 0;
}