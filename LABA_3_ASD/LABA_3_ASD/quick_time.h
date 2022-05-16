#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

#include <iostream>
#include <fstream>

#include "sorts.h"
//________________________________quick___________________________
unsigned int rand_quick(int cap)
{

	
	std::vector<unsigned int> arr(cap);

	random_vector(arr);
	unsigned int start_time = clock();
	quickSort(arr, 0, arr.size() - 1);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	return search_time;

}
unsigned int otsort_quick(unsigned int cap)
{
	std::vector<unsigned int> arr(cap);
	random_vector(arr);
	sort(arr.begin(), arr.end());

	unsigned int start_time = clock();
	quickSort(arr, 0, arr.size() - 1);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	return search_time;
}

unsigned int obr_sort_quick(int cap)
{
	std::vector<unsigned int> arr(cap);
	random_vector(arr);
	std::sort(arr.begin(), arr.end(), std::greater<int>());

	unsigned int start_time = clock();
	quickSort(arr, 0, arr.size() - 1);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	return search_time;
}

unsigned int sort_10pr_quick(int cap)
{
	std::vector<unsigned int> arr(cap);
	random_vector(arr);
	std::sort(arr.begin(), arr.end());
	for (int i = arr.size() - 1; i >= 1; i -= arr.size() - arr.size() * 0.1)
	{
		int j = rand() % (i + 1);
		int tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	}


	unsigned int start_time = clock();
	quickSort(arr, 0, arr.size() - 1);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	return search_time;
}

unsigned int semi_sort_quick(int cap)
{
	std::vector<unsigned int> arr(cap);
	random_vector(arr);
	std::sort(arr.begin(), arr.begin() + arr.size() / 2);
	std::sort(arr.begin() + arr.size() / 2, arr.end());

	unsigned int start_time = clock();
	quickSort(arr, 0, arr.size() - 1);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	return search_time;
}