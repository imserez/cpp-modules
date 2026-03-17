#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) this->_db = other._db;
    return (*this);
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::_trim(std::string& s) const {
    size_t first = s.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        s = "";
        return ;
    }
    size_t last = s.find_last_not_of(" \t\r\n");
    s = s.substr(first, (last - first + 1));
}

bool BitcoinExchange::_isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2008 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    return true;
}

bool BitcoinExchange::_isValidValue(const std::string& valueStr, float& value) const {
    char* end;
    double tempValue = std::strtod(valueStr.c_str(), &end);

    if (end == valueStr.c_str() || *end != '\0')
        return false;

    value = static_cast<float>(tempValue);
    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database" << std::endl;
        std::exit(1);
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t sep = line.find(',');
        if (sep != std::string::npos) {
            std::string date = line.substr(0, sep);
            float rate = static_cast<float>(std::strtod(line.substr(sep + 1).c_str(), NULL));
            _db[date] = rate;
        }
    }
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return ;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t sep = line.find('|');
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string valStr = line.substr(sep + 1);
        _trim(date);
        _trim(valStr);

        float value;
        if (!_isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!_isValidValue(valStr, value)) continue;

        std::map<std::string, float>::iterator it = _db.lower_bound(date);
        if (it == _db.end() || it->first != date) {
            if (it == _db.begin()) {
                std::cerr << "Error: no data available before this date" << std::endl;
                continue;
            }
            --it;
        }
        std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
    }
}