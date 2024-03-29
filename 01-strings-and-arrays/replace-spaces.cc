#include <iostream>
#include <string>
using namespace std;

char *replace_spaces2(const char *s, size_t length) {
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

char *replace_spaces(const char *str,size_t length) {
	// get the number of spaces
	size_t spaces,i,new_length,j;
	spaces = 0;
	for(i = 0; i < length; i++) {
		if(str[i] == ' ') spaces++;
	}
	new_length = length + 2*spaces;
	char *arr = (char *)calloc(1,new_length + 1);

	// replace the spaces with %20
	j =  0;
	for(i = 0; i < length; i++) {
		if(str[i] == ' ') {
			arr[j] = '%';
			arr[j+1] = '2';
			arr[j+2] = '0';
			j += 3;
		} else {
			arr[j++] = str[i];
		}
	}
	return arr;
}

int main() {
	string s;
	cout << "Enter a string: ";
	getline(cin,s);
	while(s != "") {
	  char *ns = replace_spaces(s.c_str(),s.size());
	  cout << ns << endl;
	  cout << "Enter a string: ";
	  getline(cin,s);
	}
	return 0;
}
