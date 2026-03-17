#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <stdexcept>
# include <algorithm>
# include <sys/time.h>
# include <cstdlib>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int>  _deq;

        void _parseArguments(int argc, char** argv);
        void _printSequence(const std::string& prefix, const std::vector<int>& seq) const;
        double _getTimeMicro() const;

        std::vector<int> _generateJacobsthal(int n) const;

        void _sortVector(std::vector<int>& arr);
        void _sortDeque(std::deque<int>& arr);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void run(int argc, char** argv);
};

#endif