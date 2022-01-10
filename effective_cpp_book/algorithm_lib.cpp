#include <iostream>
#include <memory>
#include<Algorithm>
#include <vector>
#include<string>
#include <list>
using namespace std;


bool IsEven(int a) {

	return a % 2 == 0;
}

int gene()
{
	return rand();
}

int main()
{

	//##################HEAPS###################################
	vector<int>x = { 1,19,4,21,21,6,8,9 };
	vector<int>::iterator it;
	// creates a heap. it is good way to find max element!
	make_heap(x.begin(), x.end());
	//cout << *x.begin() << endl;

	x.push_back(22);

	// pushes new value to heap.(to the right position)
	push_heap(x.begin(), x.end());
	//cout << *x.begin() << endl;

	for (it = x.begin(); it != x.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	//pops head from beginning(biggest value) and merge it to end of the heap
	//22,21,19,9,8,6,4,3,1 -> 21,19,9,8,6,4,3,1,  22    than we have to delete last element.

	//poping it continuously is gonna create and sorted list at the end!!
	pop_heap(x.begin(),x.end());





	//########################################################################
	// SORTING

	// sort heap sorts the heap like pop_heap creates the sorted heap at the end.(it sortes the heap)
	//sort_heap(x.begin(), x.end());

	//PARTIAL SORT, if we would like to sort first 4 elements. it would be perfect match.

   /* partial_sort(x.begin(),x.begin()+4,x.end());*/



	//NTH_ELEMENT
	// IT returns the given location of the element.

	//finding the median of the given numbers!!
	// 
	auto m = x.begin() + (x.size() / 2);
	nth_element(x.begin(), m, x.end());
	std::cout << "\nThe median is " << x[x.size() / 2] << '\n';

	//INPLACE_MERGE

	//vector<int>y = { 1,2,3,4,5,6,7,8 };
	//vector<int>z = { 9,10,11,12 };

	//inplace_merge(y.begin(), y.begin() + (y.size() + z.size()) / 2, z.end());


	//PARTITIONING (you can divide a array to any specific feature.(exp: you can divide an arr to odd and even numbers) )
	// it will convert our arr to -> 22,8,4,6  ,3,9,19,21,1


	//partition(x.begin(), x.end(), IsEven);


	// PARTITION_POINT this will give you to point which divides your arr you your predicate(our point is 3)

  /* vector<int>::iterator f = partition_point(x.begin(), x.end(), IsEven);
   cout << *f << endl;*/

   //ROTATE this takes the last element of the arr and make it first each time.
	//abt the mid value: move numbers from beggining of x to begin + given value to the end. 

   rotate(x.begin(),x.begin()+1,x.end());
   for (it = x.begin(); it != x.end(); it++)
   {
	   cout << *it <<" ";
   }

   //SHUFFLE is shuffles randomly a given arr.
   /*shuffle(x.begin(),x.end(),rand);*/

   //REVERSE reverses the array.
	reverse(x.begin(), x.end());
	for (it = x.begin(); it != x.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//NUMERIC ALGORITHMS################################################################################
	//COUNT it returnes, how many times the given value appears in the given array.
	int z = count(x.begin(), x.end(), 3);
	cout << z << endl;

	//ACCUMULATE
	// add all the elements and returns the sum.


	//QUERYING A PROPERTY
	//ALL_OF(first,last, unary predicate) Checks if unary predicate p returns true for all elements in the range [first, last).
	cout << all_of(x.begin(), x.end(), IsEven) << endl; // it ll return 0 because not all the elements re even.(it returns true when arr is empty)
	cout << any_of(x.begin(), x.end(), IsEven) << endl; // it ll return 1 because some of the elements re even.(it returns false when arr is empty)
	cout << none_of(x.begin(), x.end(), IsEven) << endl; // it ll return 0 because some of the elements re even.(it returns true when arr is empty)

	//QUERYING A PROPERTY ON 2 RANGES
	//EQUAL(p arr should has equal size or more.)(if has more and its first elements mathes with q equal will return true as well.!!)
	vector<int>q = { 1,19,4,3,21,6,8 };
	vector<int>p = { 1,19,4,3,21,8,8,9 };
	vector<int>::iterator it1;
	cout << equal(q.begin(), q.end(), p.begin()) << endl;

	//lexicographical_compare(checks if the first one is smaller.)
	cout << lexicographical_compare(q.begin(), q.end(), p.begin(), p.end()) << endl;

	//MISMATCH displays the first position they differ.(this func is good option to find mirrored arrays like   abbcbba )
	pair<vector<int>::iterator, vector<int>::iterator> g = mismatch(q.begin(), q.end(), p.begin(), p.end());
	cout << *g.first << " " << *g.second << endl;


	//SEARCHING A VALUE IN AN UNSORTED lIST
	// find() finds a given element IN A NOT sorted array.
   /* find(x.begin(), x.end(), 7);*/

	//adjacent_find(x.begin(),x.end()) finds {1,2,3,4,5,6,4,4 } it returns the second 4th position because the first time two 4 is contiguous order.

	auto l = adjacent_find(x.begin(), x.end());
	if (l != x.end())
		cout << *l << endl;
	else
		cout << "no adjacent value!!" << endl;


	//SEARCHING A VALUE IN A SORTED LIST
	//equal_range, it returns

	for (it = x.begin(); it != x.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	pair<vector<int>::iterator, vector<int>::iterator> p2;
	p2 = equal_range(x.begin(), x.end(), 10);
	cout << *p2.first << " " << *p2.second << endl;
	// lower_bound returns the lower bound of equal range.
	// upper_bound returns the upper bound of equal range.

	//SEARCHING IN A RANGE
	//search() searches a pattern in an another array.if it appears in the array it returns the positionf of the starting point!!
	vector<char> c1 = { 'a','s','d','b','c','q','w','e','f' };
	vector<char> c2 = { 'b','c','q' };

	vector<char>::iterator it2;
	it2 = search(c1.begin(), c1.end(), c2.begin(), c2.end());
	cout << *it2 << endl;

	// it rerturns the lastest occurance of the pattern( returns the first element of that pattern)
	it2 = find_end(c1.begin(), c1.end(), c2.begin(), c2.end());
	cout << *it2 << endl;

	//find_first_Of
	std::string str("Please, replace the vowels in this sentence by asterisks.");
	std::size_t found = str.find_first_of("aeiou");
	while (found != std::string::npos)
	{
		str[found] = '*';
		found = str.find_first_of("aeiou", found + 1);
	}

	std::cout << str << '\n';

	//SEARCHING A RELATIVE VALUE
	vector<int>::iterator kl = min_element(x.begin(), x.end());
	vector<int>::iterator kl2 = max_element(x.begin(), x.end());
	cout << endl;
	cout << *kl << endl;
	cout << *kl2 << endl;


	//SETS
	cout << endl;
	vector<int> klX = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int>klX2 = { 4,5,6,7,12,13,14,15,16,17,18 };
	vector<int> storage(100);

	//O(n) 
	set_difference(klX.begin(), klX.end(), klX2.begin(), klX2.end(), storage.begin());
	vector<int>::iterator itt;
	for (itt = storage.begin(); itt != storage.end(); itt++)
	{
		cout << *itt << " ";
	}
	cout << endl;
	//set_union(klX.begin(), klX.end(), klX2.begin(), klX2.end(), storage.begin());
	//for (itt = storage.begin(); itt != storage.end(); itt++)
	//{
	//    cout << *itt << endl;
	//}



	std::vector<char> v = { 'a', 'b', 'c', 'd', 'e' };
	std::list<char> lx = { '1', '2', '3', '4', '5' };

	vector<char>::iterator vi;
	list<char>::iterator lxi;
	//print("Before swap_ranges:\n" "v: ", v);
	//print("l: ", l);

	std::swap_ranges(v.begin(), v.begin() + 3, lx.begin());
	for (vi = v.begin(); vi != v.end(); vi++)
	{
		cout << *vi << " ";
	}
	cout << endl;
	for (lxi = lx.begin(); lxi != lx.end(); lxi++)
	{
		cout << *lxi << " ";
	}


	//#######################
	vector<int> my_vec(10);
	generate(my_vec.begin(), my_vec.end(), gene());
	fill(my_vec.begin(), my_vec.end(), 3);
	replace(my_vec.begin(), my_vec.end(), 3, 5);


	//STL’s sort ran faster than C’s qsort, because C++’s templates generate optimized code for a particular data type and a particular comparison function.
	sort(x.begin(), x.end());








}