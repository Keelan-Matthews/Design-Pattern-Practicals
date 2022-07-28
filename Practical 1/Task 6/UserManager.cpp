class UserManager {

 public:
  UserManager(User *User) : User_(User) {;
    // TODO : Implement
  }

  void Backup() {
    std::cout << "\nUserManager: Saving User's state...\n";
    // TODO : Implement
  }

  void Undo() {
    // TODO : Implement
  }

  void ShowHistory() const {
    std::cout << "UserManager: Here's the list of historal changes:\n";
    // TODO : Implement
  }
};