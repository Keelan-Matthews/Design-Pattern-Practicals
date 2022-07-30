#pragma once
#include "User.h"
#include <iostream>
#include <vector>

class UserManager {
private:
    User *User_;
    std::vector<AuditableSnapshot *> mementos_;

public:
    UserManager(User *User);
    void Backup();
    void Undo();
    void ShowHistory();
};