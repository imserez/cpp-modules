#pragma once

# include <vector>
# include <iterator>
# include <exception>

class Span {

    private:
        unsigned int _maxN;
        std::vector<int> _nums;
        Span();
    public:
        Span(unsigned int N);
        Span(const Span &obj);
        Span&   operator=(const Span &obj);
        ~Span();

        void    addNumber(int num);
        int     shortestSpan() const;
        int     longestSpan() const;

        template <typename InputIterator>
        void addNumbers(InputIterator begin, InputIterator end) {
            if (std::distance(begin, end) + _nums.size() > _maxN) {
                throw std::length_error("Error: not enough span space");
            }
            _nums.insert(_nums.end(), begin, end);
        }

        class SpanFullException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Error: span full";
            }
        };

        class NoSpanFoundException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Error: not enough items";
            }
        };
};