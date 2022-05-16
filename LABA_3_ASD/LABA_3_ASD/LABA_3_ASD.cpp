
#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

#include <iostream>
#include <fstream>

#include "sorts.h"
#include "select_time.h"
#include "quick_time.h"
#include "bucket_time.h"
using namespace std;

int test = 25;

int main()
{

	std::vector<unsigned int> arr(10000);
	random_vector(arr);
	quickSort(arr, 0, arr.size() - 1);
	quickSort(arr, 0, arr.size() - 1);

	print_vector(arr);

	//print_vector(arr);

	/*
	
	ofstream s1("Select test.csv", std::ios::app);
	ofstream q1("Bucket test.csv", std::ios::app);
	ofstream b1("Quick test.csv", std::ios::app);

	 
	s1 << ";" << "Random"       << ";" << ";" << ";" << ";" << "|" << ";" 
	   << ";" << "Sorted"       << ";" << ";" << ";" << ";" << "|" << ";" 
	   << ";" << "Back sorted " << ";" << ";" << ";" << ";" << "|" << ";" 
	   << ";" << "Sorted 10%"   << ";" << ";" << ";" << ";" << "|" << ";"
	   << ";" << "Semi sorted"  << ";" << ";" << ";" << ";" << "|" << ";"
		<< endl;
	s1 << "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << ";"
	   << "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << ";"
	   << "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << ";"
	   << "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << ";"
	   << "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << endl;
	for (int i = 0; i < n; i++)
	{
		s1 << rand_select(100) << ";" << rand_select(1000) << ";" << rand_select(10000) << ";" << rand_select(50000) << ";" << ";" << "|" << ";"
			<< otsort_select(100) << ";" << otsort_select(1000) << ";" << otsort_select(10000) << ";" << otsort_select(50000) << ";" << ";" << "|" << ";"
			<< rev_sort_select(100) << ";" << rev_sort_select(1000) << ";" << rev_sort_select(10000) << ";" << rev_sort_select(50000) << ";" << ";" << "|" << ";"
			<< sort_10pr_select(100) << ";" << sort_10pr_select(1000) << ";" << sort_10pr_select(10000) << ";" << sort_10pr_select(50000) << ";" << ";" << "|" << ";"
			<< semi_sort_select(100) << ";" << semi_sort_select(1000) << ";" << semi_sort_select(10000) << ";" << semi_sort_select(50000) << ";" << ";" << "|" << endl;


	}

	cout << 1 << endl;

	q1 << ";" << "Random" << ";" << ";" << ";" << ";" << "|" << ";"
		<< ";" << "Sorted" << ";" << ";" << ";" << ";" << "|" << ";"
		<< ";" << "Back sorted " << ";" << ";" << ";" << ";" << "|" << ";"
		<< ";" << "Sorted 10%" << ";" << ";" << ";" << ";" << "|" << ";"
		<< ";" << "Semi sorted" << ";" << ";" << ";" << ";" << "|" << ";"
		<< endl;
	q1 << "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << ";"
		<< "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << ";"
		<< "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << ";"
		<< "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << ";"
		<< "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << endl;

	for (int i = 0; i < n; i++)
	{
		q1 << rand_quick(100) << ";" << rand_quick(1000) << ";" << rand_quick(10000) << ";" << rand_quick(50000) << ";" << ";" << "|" << ";"
			<< otsort_quick(100) << ";" << otsort_quick(1000) << ";" << otsort_quick(10000) << ";" << otsort_quick(50000) << ";" << ";" << "|" << ";"
			<< obr_sort_quick(100) << ";" << obr_sort_quick(1000) << ";" << obr_sort_quick(10000) << ";" << obr_sort_quick(50000) << ";" << ";" << "|" << ";"
			<< sort_10pr_quick(100) << ";" << sort_10pr_quick(1000) << ";" << sort_10pr_quick(10000) << ";" << sort_10pr_quick(50000) << ";" << ";" << "|" << ";"
			<< semi_sort_quick(100) << ";" << semi_sort_quick(1000) << ";" << semi_sort_quick(10000) << ";" << semi_sort_quick(50000) << ";" << ";" << "|" << endl;


	}


	cout << 2 << endl;

	b1 << ";" << "Random" << ";" << ";" << ";" << ";" << "|" << ";"
		<< ";" << "Sorted" << ";" << ";" << ";" << ";" << "|" << ";"
		<< ";" << "Back sorted " << ";" << ";" << ";" << ";" << "|" << ";"
		<< ";" << "Sorted 10%" << ";" << ";" << ";" << ";" << "|" << ";"
		<< ";" << "Semi sorted" << ";" << ";" << ";" << ";" << "|" << ";"
		<< endl;
	b1 << "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << ";"
		<< "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << ";"
		<< "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << ";"
		<< "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << ";"
		<< "100cap" << ";" << "1000cap" << ";" << "10000cap" << ";" << "50000cap" << ";" << ";" << "|" << endl;

	for (int i = 0; i < n; i++)
	{
		b1 << rand_bucket(100) << ";" << rand_bucket(1000) << ";" << rand_bucket(10000) << ";" << rand_bucket(50000) << ";" << ";" << "|" << ";"
			<< otsort_bucket(100) << ";" << otsort_bucket(1000) << ";" << otsort_bucket(10000) << ";" << otsort_bucket(50000) << ";" << ";" << "|" << ";"
			<< obr_sort_bucket(100) << ";" << obr_sort_bucket(1000) << ";" << obr_sort_bucket(10000) << ";" << obr_sort_bucket(50000) << ";" << ";" << "|" << ";"
			<< sort_10pr_bucket(100) << ";" << sort_10pr_bucket(1000) << ";" << sort_10pr_bucket(10000) << ";" << sort_10pr_bucket(50000) << ";" << ";" << "|" << ";"
			<< semi_sort_bucket(100) << ";" << semi_sort_bucket(1000) << ";" << semi_sort_bucket(10000) << ";" << semi_sort_bucket(50000) << ";" << ";" << "|" << endl;

	}

	cout << 3 << endl;
	
	
	*/

	return 0;
}