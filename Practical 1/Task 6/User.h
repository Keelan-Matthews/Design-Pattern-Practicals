#pragma once
#include "Snapshot.h"
class User {

private:
    std::string _username;
    std::string _password;

    std::string GenerateRandomString(int length);

public:
    User(std::string username, std::string password);
    void SetPassword(std::string password);
    AuditableSnapshot * Save();
    void Restore(AuditableSnapshot *memento);
};