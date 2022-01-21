#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <format>
#include <exception>
using namespace std;

// Returns false on error
bool changeNumberForID(string_view filename, int id, string_view newNumber);

int main()
{
	/* implement a try catch block*/
	try
	{
		changeNumberForID("data.txt", 263, "415-555-3333");
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << std::endl;
	}
	
}

bool changeNumberForID(string_view filename, int id, string_view newNumber)
{
	fstream ioData{ filename.data() };
	if (!ioData) {

		//cerr << "Error while opening file " << filename << endl;
		//return false;
		throw runtime_error{ format("Error opening file: {}",filename.data()) };
	}

	// Loop until the end of file
	while (ioData) {
		// Read the next ID.
		int idRead;
		ioData >> idRead;
		if (!ioData)
			break;

		// Check to see if the current record is the one being changed.
		if (idRead == id) {
			// Seek the write position to the current read position.
			ioData.seekp(ioData.tellg());
			if (!ioData)
			{
				throw runtime_error{ "Failed to seek to the proper position in the output stream." };
			}
			// Output a space, then the new number.
			ioData << " " << newNumber;
			if (!ioData) {
				throw runtime_error{ "Failed to write to the output stream." };
			}
			break;
		}

		// Read the current number to advance the stream.
		string number;
		ioData >> number;
		if (!ioData) {
			throw runtime_error{ "Failed to read next number from the input stream." };
		}
	}
	return true;
}