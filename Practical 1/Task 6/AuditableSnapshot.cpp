class AuditableSnapshot {
 public:
  virtual std::string GetUsername() const = 0;
  virtual std::string date() const = 0;
  virtual std::string state() const = 0;
};