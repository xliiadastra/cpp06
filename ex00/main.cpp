#include "Conversion.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "./convent <number>" << std::endl;
        return (0);
    }
    else
    {
        Conversion  conversion(argv[1]);
        std::cout << conversion;
    }
    return (0);
}
