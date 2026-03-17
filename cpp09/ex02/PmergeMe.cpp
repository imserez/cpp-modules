#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other)
    {
        this->_vec = other._vec;
        this->_deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

long PmergeMe::_getTimeMicro() const
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000000) + time.tv_usec);
}

void PmergeMe::_parseArguments(int argc, char** argv) {
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg.empty())
            throw std::invalid_argument("Error: empty argument");
        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (arg[j] < '0' || arg[j] > '9')
            {
                if (j != 0 || arg[j] != '+')
                    throw std::invalid_argument("Error");
            }
        }

        char* endPtr;
        long val = std::strtol(arg.c_str(), &endPtr, 10);

        if (*endPtr != '\0' || val < 0 || val > 2147483647)
            throw std::invalid_argument("Error: invalid int number");

        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }
}

void PmergeMe::_printSequence(const std::string& prefix, const std::vector<int>& seq) const
{
    std::cout << prefix;
    size_t limit = seq.size() > 5 ? 5 : seq.size();

    for (size_t i = 0; i < limit; ++i)
    {
        std::cout << seq[i] << " ";
    }
    if (seq.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
}

std::vector<int> PmergeMe::_generateJacobsthal(int n) const {
    std::vector<int> jacob;
    if (n < 1) return jacob;

    jacob.push_back(0);
    if (n == 1)
        return jacob;
    jacob.push_back(1);

    int i = 2;
    while (true) {
        int nextVal = jacob[i - 1] + 2 * jacob[i - 2];
        jacob.push_back(nextVal);
        if (nextVal >= n)
            break;
        i++;
    }
    return jacob;
}

void PmergeMe::_sortVector(std::vector<int>& arr) {

    if (arr.size() <= 1)
        return;
    std::vector<int> mainChain;
    std::vector<int> pend;
    bool hasStraggler = arr.size() % 2 != 0;
    int straggler = 0;

    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    std::vector<int> largest;
    for (size_t i = 0; i < pairs.size(); ++i) {
        largest.push_back(pairs[i].first);
    }

    _sortVector(largest);

    for (size_t i = 0; i < largest.size(); ++i) {
        mainChain.push_back(largest[i]);
    }

    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].first) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }

    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
    }

    std::vector<int> jacob = _generateJacobsthal(pend.size());
    size_t lastPos = 1;

    for (size_t i = 2; i < jacob.size(); ++i) {
        size_t currentPos = jacob[i];
        if (currentPos > pend.size())
            currentPos = pend.size();

        for (size_t j = currentPos; j > lastPos; --j) {
            int valToInsert = pend[j - 1];
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), valToInsert);
            mainChain.insert(it, valToInsert);
        }
        lastPos = currentPos;
    }

    if (hasStraggler) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    arr = mainChain;
}

void PmergeMe::_sortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    std::deque<int> mainChain;
    std::deque<int> pend;
    bool hasStraggler = arr.size() % 2 != 0;
    int straggler = 0;

    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;

    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    std::deque<int> largest;
    for (size_t i = 0; i < pairs.size(); ++i) {
        largest.push_back(pairs[i].first);
    }

    _sortDeque(largest);

    for (size_t i = 0; i < largest.size(); ++i) {
        mainChain.push_back(largest[i]);
    }

    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].first) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }

    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
    }

    std::vector<int> jacob = _generateJacobsthal(pend.size());
    size_t lastPos = 1;

    for (size_t i = 2; i < jacob.size(); ++i) {
        size_t currentPos = jacob[i];
        if (currentPos > pend.size())
            currentPos = pend.size();

        for (size_t j = currentPos; j > lastPos; --j) {
            int valToInsert = pend[j - 1];
            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), valToInsert);
            mainChain.insert(it, valToInsert);
        }
        lastPos = currentPos;
    }

    if (hasStraggler) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    arr = mainChain;
}

void PmergeMe::run(int argc, char** argv) {
    _parseArguments(argc, argv);

    _printSequence("Before: ", _vec);

    long timeVecStart = _getTimeMicro();
    _sortVector(_vec);
    long timeVecEnd = _getTimeMicro();

    long timeDeqStart = _getTimeMicro();
    _sortDeque(_deq);
    long timeDeqEnd = _getTimeMicro();

    _printSequence("After:  ", _vec);

    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : ";
    std::cout << (timeVecEnd - timeVecStart) << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : ";
    std::cout << (timeDeqEnd - timeDeqStart) << " us" << std::endl;
}