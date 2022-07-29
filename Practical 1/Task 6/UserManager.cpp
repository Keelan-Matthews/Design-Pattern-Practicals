#include "UserManager.h"

UserManager::UserManager(User *User) : User_(User) {}

void UserManager::Backup() {
    std::cout << "\nUserManager: Saving User's state...\n";
    this->mementos_.push_back(this->User_->Save());
}

void UserManager::Undo() {
    if (this->mementos_.empty()) return;

    Snapshot *snapshot = this->mementos_.back();
    this->mementos_.pop_back();
    this->User_->Restore(snapshot);
}

void UserManager::ShowHistory() {
    std::cout << "UserManager: Here's the list of historal changes:\n";
    for (Snapshot *snapshot : this->mementos_)
        std::cout << snapshot->state() << " " << snapshot->GetUsername() << std::endl;
}