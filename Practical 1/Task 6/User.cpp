class User {
  
 private:
  std::string _username;
  std::string _password;

  std::string GenerateRandomString(int length = 10) {
    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(alphanum) - 1;

    std::string random_string;
    for (int i = 0; i < length; i++) {
      random_string += alphanum[std::rand() % stringLength];
    }
    return random_string;
  }

 public:
  User(std::string username, std:string password) : _username(username), _password(password) {
    std::cout << "User: I have been initialized with username " << this->_username << " and a password of " << this->_password << "\n";
  }
    
  void SetPassword() {
    std::cout << "User: Setting a new secure password.\n";
    // TODO : Implement
    std::cout << "User: My password has been changed to: " << this->_password << "\n";
  }

  AuditableSnapshot *Save() {
    // TODO : Implement
  }

  void Restore(AuditableSnapshot *memento) {
    std::cout << "User: My password has changed to: " << this->_password << "\n";
  }
};
