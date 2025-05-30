#include "Span.hpp"

Span::Span() : _maxsize(0) {}

Span::Span(uint32_t maxsize) : _maxsize(maxsize) {}

Span::Span(const Span& other) : _maxsize(other._maxsize), _vector(other._vector) {}

Span::~Span() {}

Span& Span::operator=(const Span& other)
{
	if (this != &other) {
		_maxsize = other._maxsize;
		_vector = other._vector;
	}
	return *this;
}

void	Span::addNumber(int N) {
	if (_vector.size() >= _maxsize)
		throw std::length_error("Span is full");
	_vector.push_back(N);
}

int	Span::shortestSpan() const
{
	if (_vector.size() < 2)
		throw std::logic_error("Not enough elements to find a span");
	
	long long	span = std::numeric_limits<int>::max();
	long long	tmp = 0;
	
	std::vector<int> sorted = _vector;
	std::sort(sorted.begin(), sorted.end());

	for (size_t i = 1; i < sorted.size(); ++i) {
		tmp = std::abs(sorted[i] - sorted[i - 1]);
		span = std::min(tmp, span);
	}

	return static_cast<int>(span);
}

int Span::longestSpan() const
{
	if (_vector.size() < 2)
		throw std::logic_error("Not enough elements to find a span");

	std::vector<int> sorted = _vector;
	std::sort(sorted.begin(), sorted.end());

	return ( std::abs(sorted.back() - sorted.front()) );
}