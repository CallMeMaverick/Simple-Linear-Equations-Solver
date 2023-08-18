#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <math.h>
#include "exceptions/EquationsExceptions.cpp"

using namespace std;

string Equation(double a, double b, double c)
{
    stringstream equationStream;

    string A = (a < 0 ? "" : "");
    string B = (b < 0 ? "" : "+");
    string C = (c < 0 ? "" : "+");

    equationStream << A << a << "x²" << B << b << 'x' << C << c << "=0";
    return equationStream.str();
}

/**
 * @brief Finds discriminant following the formula: b²-4ac
 * 
 * @param a parameter a
 * @param b parameter b
 * @param c parameter c
 * @return typenameT discriminant value
 */
template<typename T>
T Discriminant(T a, T b, T c)
{
    T discriminant = ((pow(b, 2)) - 4 * a * c);
    return discriminant;
}


template<typename T>
string FindRoots(T discriminant, double a, double b, double c)
{
    stringstream rootsStream;
    rootsStream << fixed << setprecision(2);

    if (discriminant < 0)
        return "No roots have been found;";
    
    if (discriminant == 0)
    {
        T theOnlyRoot = -b / (2.0 * a);
        stringstream ss;
        ss << fixed << "The only root found is " << setprecision(2) << theOnlyRoot;
        return ss.str();
    }

    if (discriminant > 0)
    {
        T firstRoot = (-b + sqrt(discriminant)) / (2.0 * a);
        T secondRoot = (-b - sqrt(discriminant)) / (2.0 * a);
        string result = "Roots for discriminant > 0:\n";
        rootsStream << "[" << firstRoot << ", " << secondRoot << "]";
        return result + rootsStream.str();
    }

    return "";
}

void SetValues(double& a, double& b, double& c)
{
    cout << "New a: ";
    cin >> a;

    cout << "New b: ";
    cin >> b;

    cout << "New c: ";
    cin >> c;
}

int main()
{
    cout << fixed << setprecision(2); // Set precision to 2 decimal places

    double a, b, c;

    cout << "a: ";
    cin >> a;

    cout << "b: ";
    cin >> b;

    cout << "c: ";
    cin >> c;

    // Handle exceptions
    try 
    {
        if (abs(a) == 0 || abs(b) == 0 || abs(c) == 0)
            throw ZeroParameter();
    }
    catch (ZeroParameter& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return 0;
    }

    cout << Equation(a, b, c) << endl;

    bool flag = true;
    while (flag)
    {
        int userAction;

        cout << "What would you like to with the equation?" << endl;
        cout << "---> 1. Discriminant" << endl;
        cout << "---> 2. Roots" << endl;
        cout << "---> 3. Both Discriminant and Roots" << endl;
        cout << "---> 4. Set new equation" << endl;
        cout << "---> 5. Exit" << endl;

        cin >> userAction;

        switch (userAction)
        {
        case 1:
            cout << "Discriminant: " << Discriminant(a, b, c) << endl;
            break;
        case 2:
            cout << "Roots: " << FindRoots(Discriminant(a, b, c), a, b, c) << endl;
            break;
        case 3:
            cout << "Discriminant: " << Discriminant(a, b, c) << endl;
            cout << "Roots: " << FindRoots(Discriminant(a, b, c), a, b, c) << endl;
            break;
        case 4:
            while (true) 
            {
                SetValues(a, b, c);
            
                try 
                {
                    if (abs(a) == 0 || abs(b) == 0 || abs(c) == 0)
                        throw ZeroParameter();

                    break;
                }
                catch (ZeroParameter& e)
                {
                    std::cout << "Error: " << e.what() << std::endl;
                }
            }
            break;
        case 5:
            flag = !flag; 
            break;

        default:
            cout << "Invalid command provided" << endl;
            cout << Equation(a, b, c) << endl;
            break;
        }
    }

    return 0;
}