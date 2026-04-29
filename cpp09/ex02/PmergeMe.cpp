#include "PmergeMe.hpp"
#include <iomanip>

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

void	startPmerge(std::vector<double>	vec, std::deque<double>	deq)
{
	double	vecSec;
	double	deqSec;

	std::cout << "Before: ";
	for (std::vector<double>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
	clock_t	startV = clock();
	mergeInsertSort(vec);
	clock_t	endV = clock();
	vecSec = static_cast<double>(endV - startV) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	for (std::vector<double>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << '\n';

	clock_t	startD = clock();
	mergeInsertSort(deq);
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