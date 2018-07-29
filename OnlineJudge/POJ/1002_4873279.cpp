using namespace std;
#include <iostream>
#include <string>
#include <cstring>

void quicksort(int* result, int* count, int left, int right)
{
	if (left >= right)
		return;
	int swap;
	int i = left + 10;
	int j = right;
	while (i <= j)
	{
		while (result[i] < result[left] && i <= right)
			i += 10;
		while (result[j] > result[left])
			j -= 10;
		if (i < j)
		{
			swap = result[i];
			result[i] = result[j];
			result[j] = swap;
			swap = count[i];
			count[i] = count[j];
			count[j] = swap;
		}
	}
	swap = result[left];
	result[left] = result[j];
	result[j] = swap;
	swap = count[left];
	count[left] = count[j];
	count[j] = swap;
	quicksort(result, count, left, j);
	quicksort(result, count, i, right);
}
int main()
{
	int n;
	cin.sync_with_stdio(0);
	string s;
	int result[50000];
	int count[50000];
	int jishu[10];
	for (int i = 0; i < 10; i++)
	{
		jishu[i] = i;
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int s1 = 0;
		int j = 0;
		while (s[j] != '\0')
		{
			if (s[j] >= '0' && s[j] <= '9')
			{
				s1 = s1 * 10 + (s[j] - 48);
			}
			else if (s[j] >= 'A' && s[j] <= 'C')
			{
				s1 = s1 * 10 + 2;
			}
			else if (s[j] >= 'D' && s[j] <= 'F')
			{
				s1 = s1 * 10 + 3;
			}
			else if (s[j] >= 'G' && s[j] <= 'I')
			{
				s1 = s1 * 10 + 4;
			}
			else if (s[j] >= 'J' && s[j] <= 'L')
			{
				s1 = s1 * 10 + 5;
			}
			else if (s[j] >= 'M' && s[j] <= 'O')
			{
				s1 = s1 * 10 + 6;
			}
			else if (s[j] == 'P' || s[j] == 'R' || s[j] == 'S')
			{
				s1 = s1 * 10 + 7;
			}
			else if (s[j] >= 'T' && s[j] <= 'V')
			{
				s1 = s1 * 10 + 8;
			}
			else if (s[j] >= 'W' && s[j] <= 'Y')
			{
				s1 = s1 * 10 + 9;
			}
			j++;
		}
		for (j = s1 / 1000000; j < jishu[s1 / 1000000]; j += 10)
		{
			if (s1 == result[j])
			{
				count[j]++;
				break;
			}
		}
		if (j == jishu[s1 / 1000000])
		{
			result[j] = s1;
			count[j] = 1;
			jishu[s1 / 1000000] += 10;;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		int current = i;
		while (current < jishu[i])
		{
			while (count[jishu[i] - 10] == 1 && jishu[i] > i)
				jishu[i] -= 10;
			while (count[current] != 1 && current < jishu[i])
				current += 10;
			if (current < jishu[i])
			{
				result[current] = result[jishu[i] - 10];
				count[current] = count[jishu[i] - 10];
				jishu[i] -= 10;
			}
		}
	}
	bool empty = true;
	for (int i = 0; i < 10; i++)
	{
		if (jishu[i] != i)
		{
			empty = false;
			break;
		}
	}
	if (empty)
	{
		cout << "No duplicates.";
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		if (jishu[i] != i)
		{
			quicksort(result, count, i, jishu[i] - 10);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < jishu[i]; j += 10)
		{
			cout << result[j] / 1000000 << result[j] / 100000 % 10 << result[j] / 10000 % 10 << '-' << result[j] / 1000 % 10 << result[j] / 100 % 10 << result[j] / 10 % 10 << result[j] % 10 << ' ' << count[j] << '\n';
		}
	}
	return 0;
}
