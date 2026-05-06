#include "PmergeMe.hpp"
#include <iomanip>
#include <algorithm>

template <typename Container>
static void insertionSortRange(Container& c,
    typename Container::size_type left,
    typename Container::size_type right)
{
    typedef typename Container::value_type T;
    typename Container::size_type i;
    typename Container::size_type j;

    if (right - left < 2)
        return;
    i = left + 1;
    while (i < right)
    {
        T key = c[i];
        j = i;
        while (j > left && c[j - 1] > key)
        {
            c[j] = c[j - 1];
            --j;
        }
        c[j] = key;
        ++i;
    }
}

template <typename Container>
static void mergeRange(Container& c,
    typename Container::size_type left,
    typename Container::size_type mid,
    typename Container::size_type right)
{
    typedef typename Container::value_type T;
    typedef typename Container::size_type SizeType;

    std::vector<T> tmp(right - left);
    SizeType i = left;
    SizeType j = mid;
    SizeType k = 0;

    while (i < mid && j < right)
    {
        if (c[i] <= c[j])
            tmp[k++] = c[i++];
        else
            tmp[k++] = c[j++];
    }
    while (i < mid)
        tmp[k++] = c[i++];
    while (j < right)
        tmp[k++] = c[j++];

    k = 0;
    while (k < tmp.size())
    {
        c[left + k] = tmp[k];
        ++k;
    }
}

template <typename Container>
static void mergeInsertSortRange(Container& c,
    typename Container::size_type left,
    typename Container::size_type right)
{
    const typename Container::size_type INSERTION_THRESHOLD = 16;
    typename Container::size_type mid;

    if (right - left < 2)
        return;
    if (right - left <= INSERTION_THRESHOLD)
    {
        insertionSortRange(c, left, right);
        return;
    }
    mid = left + (right - left) / 2;
    mergeInsertSortRange(c, left, mid);
    mergeInsertSortRange(c, mid, right);
    mergeRange(c, left, mid, right);
}

template <typename Container>
void mergeInsertSort(Container& c)
{
    if (c.size() <= 1)
		return ;
	mergeInsertSortRange(c, 0, c.size());
}


// Generate Jacobsthal numbers up to max (inclusive)
static std::vector<size_t> build_jacobsthal_numbers(size_t max)
{
	std::vector<size_t> J;
	J.push_back(0); // J0
	if (max == 0) return J;
	J.push_back(1); // J1
	// generate until > max
	while (true)
	{
		size_t sz = J.size();
		size_t next = J[sz - 1] + 2 * J[sz - 2];
		if (next > max) break;
		J.push_back(next);
	}
	return J;
}

// Build the Jacobsthal insertion order for pend indices (1-based)
static std::vector<size_t> build_jacobsthal_insertion_order(size_t m)
{
	std::vector<size_t> order;
	if (m == 0) return order;
	// always insert b1 first
	order.push_back(1);
	if (m == 1) return order;

	std::vector<size_t> J = build_jacobsthal_numbers(m);
	// ensure we have at least up to J3 if possible
	// find highest k such that J[k] <= m
	// process Jacobsthal blocks starting from k=3 (if present), ascending
	for (size_t idx = 3; idx < J.size(); ++idx)
	{
		size_t cur = J[idx];
		size_t prev = J[idx - 1];
		// we need to insert elements b_cur down to b_{prev+1}
		size_t start = cur;
		size_t end = prev + 1;
		if (start > m) start = m;
		if (end < 2) end = 2; // don't overwrite b1 which is already inserted
		for (size_t t = start; t >= end; --t)
		{
			order.push_back(t);
			if (t == end) break;
		}
	}

	// add any remaining indices not yet included (from 2..m)
	std::vector<char> seen(m + 1, 0);
	for (size_t ii = 0; ii < order.size(); ++ii)
	{
		size_t v = order[ii];
		if (v >= 1 && v <= m) seen[v] = 1;
	}
	for (size_t i = 2; i <= m; ++i)
		if (!seen[i]) order.push_back(i);

	return order;
}

// Binary insert helper for generic container with random access iterators
template <typename Container>
static void binary_insert(Container& c, const typename Container::value_type& value)
{
	typename Container::iterator it = std::lower_bound(c.begin(), c.end(), value);
	c.insert(it, value);
}

// Ford-Johnson implementation for std::vector<T>
template <typename T>
static void ford_johnson_vector(std::vector<T>& a)
{
	size_t n = a.size();
	if (n <= 1) return;

	std::vector<T> winners;
	std::vector<T> pend; // losers
	winners.reserve((n + 1) / 2);
	pend.reserve(n / 2);

	// pairing
	size_t i = 0;
	for (; i + 1 < n; i += 2)
	{
		if (a[i] <= a[i + 1])
		{
			winners.push_back(a[i]);
			pend.push_back(a[i + 1]);
		}
		else
		{
			winners.push_back(a[i + 1]);
			pend.push_back(a[i]);
		}
	}
	if (i < n) // odd last
		winners.push_back(a[i]);

	// sort winners recursively using the existing merge-insert (safe)
	mergeInsertSort(winners);

	// insertion order via Jacobsthal
	size_t m = pend.size();
	std::vector<size_t> order = build_jacobsthal_insertion_order(m);

	// start with winners as result container
	std::vector<T> result = winners;

	// Insert pend elements according to order (indices are 1-based in build)
	for (size_t ii = 0; ii < order.size(); ++ii)
	{
		size_t idx = order[ii];
		if (idx == 0 || idx > m) continue;
		binary_insert(result, pend[idx - 1]);
	}

	// ensure all pend inserted (safety)
	if (result.size() < n)
	{
		for (size_t j = 0; j < m; ++j)
		{
			// check if pend[j] is present
			if (!std::binary_search(result.begin(), result.end(), pend[j]))
				binary_insert(result, pend[j]);
		}
	}

	// copy back
	for (size_t k = 0; k < n; ++k) a[k] = result[k];
}

// Ford-Johnson implementation for std::deque<T>
template <typename T>
static void ford_johnson_deque(std::deque<T>& a)
{
	size_t n = a.size();
	if (n <= 1) return;

	std::deque<T> winners;
	std::deque<T> pend;
	//std::vector<T> pend; // keep pend in vector for easy indexing
	//pend.reserve(n / 2);

	size_t i = 0;
	for (; i + 1 < n; i += 2)
	{
		if (a[i] <= a[i + 1])
		{
			winners.push_back(a[i]);
			pend.push_back(a[i + 1]);
		}
		else
		{
			winners.push_back(a[i + 1]);
			pend.push_back(a[i]);
		}
	}
	if (i < n) winners.push_back(a[i]);

	// sort winners using merge-insert by moving to vector and back
	std::vector<T> winners_vec(winners.begin(), winners.end());
	mergeInsertSort(winners_vec);
	winners.assign(winners_vec.begin(), winners_vec.end());

	size_t m = pend.size();
	std::vector<size_t> order = build_jacobsthal_insertion_order(m);

	// insert pend into winners (deque) using lower_bound on deque via std::lower_bound
	for (size_t ii = 0; ii < order.size(); ++ii)
	{
		size_t idx = order[ii];
		if (idx == 0 || idx > m) continue;
		T val = pend[idx - 1];
		typename std::deque<T>::iterator it = std::lower_bound(winners.begin(), winners.end(), val);
		winners.insert(it, val);
	}

	if (winners.size() < n)
	{
		for (size_t j = 0; j < m; ++j)
		{
			T val = pend[j];
			if (!std::binary_search(winners.begin(), winners.end(), val))
			{
				typename std::deque<T>::iterator it = std::lower_bound(winners.begin(), winners.end(), val);
				winners.insert(it, val);
			}
		}
	}

	// copy back to original deque
	for (size_t k = 0; k < n; ++k) a[k] = winners[k];
}

void	startPmerge(std::vector<double>	vec, std::deque<double>	deq)
{
	double	vecSec;
	double	deqSec;

	std::cout << "Before: ";
	for (std::vector<double>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
	clock_t	startV = clock();
	// use Ford-Johnson for vector
	ford_johnson_vector(vec);
	clock_t	endV = clock();
	vecSec = static_cast<double>(endV - startV) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	for (std::vector<double>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << '\n';

	clock_t	startD = clock();
	// use Ford-Johnson for deque
	ford_johnson_deque(deq);
	clock_t	endD = clock();
	deqSec = static_cast<double>(endD - startD) / CLOCKS_PER_SEC;

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << vecSec << " s\n";
	std::cout << "Time to process a range of " << deq.size()
		<< " elements with std::deque  : " << deqSec << " s\n";
}

bool	initPmerge(char **argv)
{
	int	i = 1;
	std::stringstream	ss;
	double				num;
	char				extra;
	std::vector<double>	vec;
	std::deque<double>	deq;
	while (argv[i])
	{
		ss << argv[i];
		if (ss.bad() || ss.fail())
		{
			std::cerr << "Invalid input\n";
			return (false);
		}
		//ss >> num;
		if (!(ss >> num) || (ss >> extra))
		{
		    std::cerr << "Invalid input\n";
		    return false;
		}
		if (num < 0)
		{
			std::cerr << "Invalid number\n";
			return (false);
		}
		vec.push_back(num);
		deq.push_back(num);
		ss.str("");
		ss.clear();
		i++;
	}
	startPmerge(vec, deq);
	/*std::cout << "Vector: ";
	for (std::vector<double>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';

	std::cout << "Deque:  ";
	for (std::deque<double>::const_iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';*/

	return (true);
}