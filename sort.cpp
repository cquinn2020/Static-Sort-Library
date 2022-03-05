#include "SortLib.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <vector>
#include <cstring>

using std::cout; using  std::endl; using std::vector;
// helper printing function
void print(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        if (i != size-1)
        {
            cout << arr[i] << " ";
        }
        else {
            cout << arr[i] <<  endl;
        }
    }  
}

int main(int argc, char* argv[]) {
	// Define array of numbers and the count so it stays in scope.
	int* numsArr = nullptr;
	int listCount = 0;
	
	// Debug statement-> how do you use lldb with file with mutliple args?
	if (argc < 3) { // must have at least 3 arguments for ./sort -a <algorithm>
		std::cerr << "Usage: " << argv[0] << " -a <algorithm> [-i <infile> -o <outfile> -t]" << std::endl;
        return 1;
	}

	// Parse the arguments
	// You can assume if -a is present, so is the algorithm
	// And if -i is present, so is the filename, and so on
	// Create flags for -a, -i, -o, -t
	bool algorithm = false;
	bool inputFile = false; 
	bool outputFile = false;
	bool timing = false;

	// Parse and see which arguments were provided
	std::string algorithmToDo;
	std::string inputFileName;
	std::string outFile;
	for (int i = 0; i < argc; i++)
	{	
		if (!std::strcmp(argv[i], "-a"))
		{
			algorithm = true;
			algorithmToDo = argv[i+1];
			i++;
		} 
		if (!std::strcmp(argv[i], "-i")) {
			inputFile = true;
			inputFileName = argv[i+1];
			i++;
		} 
		if (!std::strcmp(argv[i], "-o")) {
			outputFile = true;
			outFile = argv[i+1];
		} 
		if (!std::strcmp(argv[i], "-t")) {
			timing = true;
		}
	}
	

	// Read the input data
	// If a file was provided with -i, read from the file
	// Else, read from stdin (cin)
	if (!inputFile) { // If file was not provided.
		// Get the size of the list.
		std::cin >> listCount;
		// Create an array to store the numbers for the list.
		numsArr = new int[listCount];
		for (int i = 0; i < listCount; i++)
		{
			int num;
			std::cin >> num;
			numsArr[i] = num;
		}
	} else { // Else a file name was provided.
		
		// Create file stream object and try to open file.
		std::ifstream ifs;
		ifs.open(inputFileName);
		if (!ifs.is_open())
		{ // If file is not open output message.
			std::cout << "Unable to open file.";
			return 1;
		}
		// Declare vector to read numbers into.
		std::vector<int> inputNums;
		int size;
		ifs >> size;
		int number; int i = 0;
		// Get the data from the file.
		while (ifs >> number && i < size)
		{
			inputNums.push_back(number);
			i++;
		}
		// Close the file.
		ifs.close();
	
		// Transfer numbers from vector to an array so 
		// sorting algorithm can be applied.
		listCount = inputNums.size();
		numsArr = new int[listCount];
		for (int i = 0; i < listCount; i++)
		{
			numsArr[i] = inputNums[i];
		}
	}

	// Set up your timer
	// You can use the included "chrono" library from C++11!
	// Hint: The following line of code would give you the current time
	// auto start = std::chrono::high_resolution_clock::now();
	// Using time point and system_clock
	std::chrono::time_point<std::chrono::system_clock> start, end; 
	std::chrono::duration<double> elapsed_seconds;
	// Apply the sorting algorithm based on the given argument
	if (algorithmToDo == "exchange")
	{
		// Run exchangeSort algorithm and time
		start = std::chrono::system_clock::now();
		SortLib::ExchangeSort<int>(numsArr, listCount);
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;

	}
	else if (algorithmToDo == "counting")
	{
		// Run countSort algorithm and time
		start = std::chrono::system_clock::now();
		SortLib::CountingSort<int>(numsArr, listCount);
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;

	}
	else if (algorithmToDo == "merge") 
	{
		// Run mergesort algorithm and time
		start = std::chrono::system_clock::now();
		SortLib::MergeSort<int>(numsArr, listCount);
		end = std::chrono::system_clock::now();	
		elapsed_seconds = end - start;
	}
	else if (algorithmToDo == "bubble") 
	{
		// Run mergesort algorithm and time
		start = std::chrono::system_clock::now();
		SortLib::BubbleSort<int>(numsArr, listCount);
		end = std::chrono::system_clock::now();	
		elapsed_seconds = end - start;
	}
	else if (algorithmToDo == "quick") 
	{
		// Run mergesort algorithm and time
		start = std::chrono::system_clock::now();
		SortLib::QuickSort<int>(numsArr, listCount);
		end = std::chrono::system_clock::now();	
		elapsed_seconds = end - start;
	}
	else if (algorithmToDo == "radix") 
	{
		// Run mergesort algorithm and time
		start = std::chrono::system_clock::now();
		SortLib::RadixSort<int>(numsArr, listCount);
		end = std::chrono::system_clock::now();	
		elapsed_seconds = end - start;
	}

	// Write the output data
	// If a file was provided with -o, write to that file
	if (outputFile)
	{	
		// Create ofstream variable and attempt to open the file.
		std::ofstream out;
		out.open(outFile);
		// If file does not open, output message indicating that.
		if (!out.is_open())
		{
			cout << "Unable to open output file." << endl;
			return 1;
		} else { // Else write to the file
			// Loop through the sorted array and write to the file
			for (int i = 0; i < listCount; i++)
			{
				if (i != listCount-1)
				{
					out << numsArr[i] << " ";
				}
				else {
					out << numsArr[i] << endl;
				}
			}
		}
		// Close the file.
		out.close();
	
	} else { // Else, write to stdout (cout)
		print(numsArr, listCount);
	}

	// If -t was set, print the elapsed time as "Elapsed Time: <duration>"
	if (timing)
	{
		cout << "Elapsed Time: " << elapsed_seconds.count()  << endl;
	}
	
	// Cleanup; remember to delete your dynamic data array!
	delete[] numsArr;
	numsArr = nullptr;
	
	return 0;
}

