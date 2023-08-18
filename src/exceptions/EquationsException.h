#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

// --- DISCRIMINANT ---
// Define exception for invalid parameters (which is x = 0)
class ZeroParameter : public std::exception 
{
public:
    const char * what() const throw()
    {
        return ">>> One of the parameters is zero <<<\n>>> Please make sure to validate parameters <<<";
    }
};


#endif