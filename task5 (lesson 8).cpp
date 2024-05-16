#include <iostream>
#include <string>

class Contact {
public:
  virtual void send(const std::string &msg) {}
  virtual ~Contact();
};

class User {
private:
  std::string name;
  Contact *contact;

public:
  User(const std::string &_name, Contact *_contact)
      : name(_name), contact(_contact) {}

  void wakeup() { contact->send(std::string("Wakey, wakey, ") + name); }

  // remember to delete the pointer
  ~User() { delete contact; }

  // make it safe
  User(const User &) = delete;
  User &operator=(const User &) = delete;
};

class Email : public Contact {
private:
  std::string address;

public:
  Email(const std::string &_address) : address(_address) {}
  virtual void send(const std::string &msg) {
    std::cout << "sending an email to " + address << std::endl;
  }
};

class Phone : public Contact {
private:
  std::string phone;

public:
  Phone(const std::string &_phone) : phone(_phone) {}
  virtual void send(const std::string &msg) {
    std::cout << "calling  " + phone << std::endl;
  }
};

int main() {
  User moss("Moss", new Email("moss@reynholm-industries.com"));
  moss.wakeup();

  User emergency("Emergency", new Phone("01189998819991197253"));
  emergency.wakeup();
}
