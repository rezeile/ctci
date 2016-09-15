#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FileReader {
	public:
		void print_last_k_lines(string filename);
};

void FileReader::print_last_k_lines(string filename) {
	ifstream input(filename.c_str(), ios_base::ate);
	if(!input) {
		cerr << "filename: " << filename << " is invalid." << endl;
		exit(1);
	}
	input.seekg(0,input.end);
	int length = input.tellg();
	cout << "length is: " << length << endl;
	// otherwise go to the last k lines of the file
	
	char *buffer = new char[length];
	input.read(buffer,length);

	input.close();

	// print content
	cout.write(buffer,length);

	delete[] buffer;
}

int main() {
	string s;
	cout << "Enter a filename: ";
	cin >> s;
	FileReader *fr = new FileReader();
	fr->print_last_k_lines(s.c_str());
	return 0;
}
