#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

#include <iostream>
#include <fstream>

#include "sorts.h"

//___________________________________bucket_sort___________________________________

unsigned int rand_bucket(int cap)
{


	std::vector<unsigned int> arr(cap);

	random_vector(arr);
	unsigned int start_time = clock();
	bucketSort(arr);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	return search_time;

}
unsigned int otsort_bucket(int cap)
{
	std::vector<unsigned int> arr(cap);
	random_vector(arr);
	bucketSort(arr);

	unsigned int start_time = clock();
	bucketSort(arr);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	return search_time;
}

unsigned int obr_sort_bucket(int cap)
{
	std::vector<unsigned int> arr(cap);
	random_vector(arr);
	std::sort(arr.begin(), arr.end(), std::greater<int>());

	unsigned int start_time = clock();
	bucketSort(arr);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	return search_time;
}

unsigned int sort_10pr_bucket(int cap)
{
	std::vector<unsigned int> arr(cap);
	random_vector(arr);
	std::sort(arr.begin(), arr.end());
	for (size_t i = arr.size() - 1; i >= 1; i -= size_t(arr.size() - arr.size() * 0.1))
	{
		int j = rand() % (i + 1);
		int tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	}


	unsigned int start_time = clock();
	bucketSort(arr);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	return search_time;
}

unsigned int semi_sort_bucket(int cap)
{
	std::vector<unsigned int> arr(cap);
	random_vector(arr);
	std::sort(arr.begin(), arr.begin() + arr.size() / 2);
	std::sort(arr.begin() + arr.size() / 2, arr.end());

	unsigned int start_time = clock();
	bucketSort(arr);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	return search_time;
}
