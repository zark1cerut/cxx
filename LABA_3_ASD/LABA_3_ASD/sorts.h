#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

#include <iostream>
#include <fstream>
using namespace std;



void print_vector(std::vector<unsigned int> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << " ";
	}
}

std::vector<unsigned int> random_vector(std::vector<unsigned int>& a)
{
	srand(time(NULL));
	for (unsigned int i = 0; i < a.size(); i++)
	{
		a[i] = rand() % 50000;
	}

	return a;
}

unsigned int* random_arr(unsigned int *arr)
{
	srand(time(NULL));
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 50000;
	}

	return arr;
}

std::vector<unsigned int> selectSort(std::vector<unsigned int>& arr)
{
	unsigned int tmp;
	for (int i = 0; i < arr.size(); ++i)
	{
		int pos = i;
		tmp = arr[i];
		for (int j = i + 1; j < arr.size(); ++j)
		{
			if (arr[j] < tmp)
			{
				pos = j;
				tmp = arr[j];
			}
		}
		arr[pos] = arr[i];
		arr[i] = tmp;
	}

	return arr;
}

//-------------------------------------------------------------------


void swap(std::vector<unsigned int>& arr, size_t& pos1, size_t& pos2) {
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

void quickSort(std::vector<unsigned int>& arr, size_t low, size_t high)
{
	int i = low, j = high;
	int temp, pivot = arr[(low + high) / 2];

	while (i <= j)
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;

		if (i <= j)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
			}

			i++; j--;
		}
	};

	if (low < j) quickSort(arr, low, j);
	if (i < high) quickSort(arr, i, high);
}

//-------------------------------------------------------------------

std::vector<unsigned int> bucketSort(std::vector<unsigned int>& array)
{

	unsigned int** buckets = new unsigned int* [10];
	for (int i = 0; i < 10; i++)
	{
		buckets[i] = new unsigned int[array.size()];
	}
	unsigned int ostatok, temp;
	unsigned int count;

	for (unsigned int x = 1; x <= 100; x *= 10)
	{

		for (unsigned int i = 0; i < 10; i++)
			for (unsigned int j = 0; j < array.size(); j++)
				buckets[i][j] = -1;
		count = 0;

		for (unsigned int i = 0; i < array.size(); i++)
		{

			temp = array[i] / x;
			ostatok = temp % 10;
			buckets[ostatok][i] = array[i];

		}

		for (unsigned int i = 0; i < 10; i++)
		{

			for (unsigned int j = 0; j < array.size(); j++)
			{

				if (buckets[i][j] != -1)
				{

					array[count] = buckets[i][j];
					count++;

				}

			}

		}

	}

	return array;
}