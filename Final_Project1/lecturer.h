#ifndef LECTURER_H
#define LECTURER_H
#include <string>
#include"user.h"

using std::string;

class Lecturer : public User
{
public:
    Lecturer(const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, const QString &);


private:

};

#endif // LECTURER_H
