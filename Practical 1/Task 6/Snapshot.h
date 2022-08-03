#pragma once
#include <ctime>
#include "AuditableSnapshot.h"

class Snapshot: public AuditableSnapshot {
private:
    std::string _state;
    std::string _date;
    Snapshot(std::string state);
    std::string state() const;
    std::string date() const;
    std::string GetUsername() const;

    friend class User;
};

