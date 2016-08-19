#include <iostream>
#include <string>
using namespace std;

char *replace_space(const char *s, size_t length) {
	// get length of new string
	size_t spaces = 0; 
	for(size_t i = 0; i < length; i++) {
		if(s[i] == ' ') spaces++;
	}
	// allocate space for new string
	size_t new_length = length + 2*spaces;
	char *arr = (char *) calloc(new_length + 1,1);
	// replace spaces with %20
	size_t j = 0;
	for(size_t i = 0; i < length; i++) {
		if(s[i] != ' ') {
			arr[j++] = s[i];
		} else {
			arr[j] = '%';
			arr[j + 1] = '2';
			arr[j + 2] = '0';
			j += 3;
		}
	}
	return arr;
}

int main(int argc, char *argv[]) {
	string s;
	cout << "Enter a string: ";
	getline(cin,s);
	while(s != "") {
	  char *ns = replace_space(s.c_str(),s.size());
	  cout << ns << endl;
	  cout << "Enter a string: ";
	  getline(cin,s);
	}
	return 0;
}
