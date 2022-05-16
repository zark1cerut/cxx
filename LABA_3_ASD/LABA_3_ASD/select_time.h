#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

#include <iostream>
#include <fstream>

#include "sorts.h"
//_____________________select_________________


unsigned int rand_select(int cap)
{


	std::vector<unsigned int> arr(cap);

	random_vector(arr);
	unsigned int start_time = clock();
	selectSort(arr);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	//std::cout << i + 1 << " search_time = " << search_time << std::endl;



	return search_time;

}
unsigned int otsort_select(int cap)
{
	std::vector<unsigned int> arr(cap);
	random_vector(arr);
	selectSort(arr);

	unsigned int start_time = clock();
	selectSort(arr);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	return search_time;
}

unsigned int rev_sort_select(int cap)
{
	std::vector<unsigned int> arr(cap);
	random_vector(arr);
	std::sort(arr.begin(), arr.end(), std::greater<int>());

	unsigned int start_time = clock();
	selectSort(arr);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	return search_time;
}

unsigned int sort_10pr_select(int cap)
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
	selectSort(arr);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	return search_time;
}

unsigned int semi_sort_select(int cap)
{
	std::vector<unsigned int> arr(cap);
	random_vector(arr);
	std::sort(arr.begin(), arr.begin() + arr.size() / 2);
	std::sort(arr.begin() + arr.size() / 2, arr.end());

	unsigned int start_time = clock();
	selectSort(arr);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	return search_time;
}