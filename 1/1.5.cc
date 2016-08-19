/* 
 * Author: Eliezer Abate
 * Date: Aug 15 2016
 * Problem 1.5 of ctci. Algorithm for basic 
 * string compression. Example:
 *
 * aaabbc -> a3b2c1
 */

 #include<iostream>
 using namespace std;
 
 /*
  * test with aabb 
  */
 string compress(string &s) {
 	size_t i, freq;
	freq = 1;
	string ns;
	for(i = 1; i < s.size(); i++) {
	  if(s[i] == s[i - 1]) {
		 freq++;
	  } else {
		 char c = '0' + freq;
	  	 string append = "";
		 append += s[i - 1];
		 append += c;
		 ns += append;
		 freq = 1;
	  }
	}
	string append = "";
	append += s[i - 1];
	char c = '0' + freq;
	append += c;
	ns += append;
	return ns;
 }
 
 int main(int argc, char *argv[]) {
    string s;
	cout << "Enter a string: ";
	getline(cin,s);
	
	while(s != "") {
	  string ns = compress(s); // print compressed string
	  cout << ns << endl;
	  cout << "Enter a string: ";
	  getline(cin,s);
	}
 }
