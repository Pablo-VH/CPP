#include "RPN.hpp"

static bool	isoperand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

static bool	parseStr(char *str)
{
	int	i = 0;
	int	j = 0;

	while (str[i])
	{
		if (std::isdigit(str[i]))
			j++;
		else if (isoperand(str[i]) && (str[i + 1] && !std::isspace(str[i + 1])))
			return (false);
		else if (isoperand(str[i]) && !std::isspace(str[i - 1]))
			return (false);
		else if (isoperand(str[i]) || std::isspace(str[i]))
			j = 0;
		else
			return (false);
		i++;
		if (j >= 2)
			return (false);
	}
	return (true);
}

int	operate(int a, int b, char c)
{
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	if (c == '*')
		return (a * b);
	else
		return (a / b);
}

bool	takeNums(char *str)
{
	std::stringstream	ss;
	int					num;
	std::list<int>		nums;
	int					i = 0;
	while (str[i])
	{
		if (std::isdigit(str[i]))
			ss << str[i];
		else
		{
			if (std::isspace(str[i]) && std::isdigit(str[i - 1]))
			{
				ss >> num;
				nums.push_back(num);
				ss.str("");
				ss.clear();
			}
			if (isoperand(str[i]))
			{
				if (nums.size() < 2)
					return (false);
				int b = nums.back();
				nums.pop_back();
				int a = nums.back();
				nums.pop_back();
				if (str[i] == '/' && b == 0)
				{
					std::cerr << "Undefined\n";
					return (false);
				}
				int result = operate(a, b, str[i]);
				nums.push_back(result);
			}
		}
		i++;
	}
	if (nums.size() > 1)
	{
		std::cerr << "Invalid input\n";
		return (false);
	}
	std::cout << "result: " << nums.back() << std::endl;
	return (true);
}

bool	reversePolishNotation(char *str)
{
	if (!parseStr(str) || !takeNums(str))
	{
		return (false);
	}
	return (true);
}