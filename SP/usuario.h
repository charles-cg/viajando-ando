#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string name, email, password;
    int id;
public:
    User() {
        name, email, password = "";
        id = 0;
    }
    void setName(string n);
    string getName();
    void setEmail(string em);
    string getEmail();
    void setPassword(string pass);
    string getPassword();
    void setID(int id);
    void registerUser();
};
//set methods
inline void User::setName(string n) {
    name = n;
}
inline void User::setEmail(string em) {
    email = em;
}
inline void User::setPassword(string pass) {
    password = pass;
}
inline void User::setID(int i) {
    id = i;
}

//get methods
inline string User::getName() {
    return name;
}
inline string User::getPassword() {
    return password;
}
inline string User::getEmail() {
    return email;
}

//other methods
inline void User::registerUser() {
    string n, em, pass;

    cout << "Nombre del usuario: \n"; cin >> n;
    setName(n);
    cout << "Email del usuario: \n"; cin >> em;
    setEmail(em);
    cout << "Contraseña del usuario: \n"; cin >> pass;
    setPassword(pass);
}

#endif