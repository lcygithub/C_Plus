#ifndef USER_H
#define USER_H
#include <QString>
class User {
public:
    User();
    QString getname() const { return name; }
    QString getpassword() const {return password; }
private:
    QString name;
    QString password;
    QString sex;
    int age;
};
#endif // USER_H
