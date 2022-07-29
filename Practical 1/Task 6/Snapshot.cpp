#include "Snapshot.h"

Snapshot::Snapshot(std::string state) : _state(state) {
    std::time_t curr = std::time(0);
    this->_date = std::ctime(&curr);
}

std::string Snapshot::state() {
    return _state;
}

std::string Snapshot::date() {
    return _date;
}

std::string Snapshot::GetUsername() {
    return std::string();
}
