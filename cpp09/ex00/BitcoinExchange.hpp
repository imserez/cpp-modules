#ifndef BTC_EXCH_HPP
# define BTC_EXCH_HPP

# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <algorithm>

class BitcoinExchange {
    private:
        std::map<std::string, float> _db;
        bool _isValidDate(const std::string& date) const;
        bool _isValidValue(const std::string& valueStr, float& value) const;
        void _trim(std::string& s) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        ~BitcoinExchange();

        void loadDatabase(const std::string& filename);
        void processInput(const std::string& filename);
};

#endif