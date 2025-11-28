#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isPseudoLiteral(const std::string& s)
{
    return (s == "nan" || s == "nanf" || s == "+inf"
        || s == "-inf" || s == "+inff" || s == "-inf");
}

static bool isCharLiteral(const std::string& s)
{
    return (s.length() == 1 && !std::isdigit(s[0]));
}

void ScalarConverter::convert(const std::string& literal)
{
    std::cout << std::fixed << std::setprecision(1);

    if (isPseudoLiteral(literal))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal[literal.length() - 1] == 'f')
        {
            std::cout << "float: " << literal <<  std::endl;
            std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
        }
        else
        {
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        }
        return;
    }

    double val;

    if (isCharLiteral(literal))
        val = static_cast<double>(literal[0]);
    else
    {
        char *end = NULL;
        val = strtod(literal.c_str(), &end);
        if (*end && *end != 'f')
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(val)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;

    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    
    std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;

    std::cout << "double: " << static_cast<double>(val) << std::endl;
}
