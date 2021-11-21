#ifndef DESKCLOCKEXCEPTION_H
#define DESKCLOCKEXCEPTION_H

#include "deskClockCore_global.h"
#include <exception>


class DESKCLOCKCORE_EXPORT DeskClockException : public std::exception
{
public:
    DeskClockException(){

    }
    virtual const char* what() const throw(){
        return "";
    }
};

class DESKCLOCKCORE_EXPORT ShortcutFullException : public DeskClockException
{
public:
    ShortcutFullException(){

    }
    virtual const char* what() const throw()
    {
        return "The number of shortcut in thge database is already full";
    }
};

#endif // DESKCLOCKEXCEPTION_H
