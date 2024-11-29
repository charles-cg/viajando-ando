#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include <string>

using namespace std;

class Booking {
private:
    int num_booking;
    string username;
    bool first_class, active;
    float price;
public:
    Booking() {
        num_booking = 0;
        username = "";
        first_class, active = false;
        price = 0;
    }
    void setNumBooking(int nb);
    void setUsername(string un);
    void setFirstClass(bool fc);
    void setPrice(float p);
};

#endif //RESERVA_H
