#include <string>
#include <vector>
using namespace std;

vector<string> permutations(string s) {
	if(s.size() <= 1) {
		vector<string> v;
		string ss = s.size() == 0 ? "" : string(1,s[0]);
		v.push_back(ss);
		return v;
	}
	vector<string> new_perms;
	char c = s[0];
	vector<string> old_perms = permutations(s.substr(1,s.size()));
	for(int i = 0; i < old_perms.size(); i++) {
		string perm = old_perms[i];
		for(int j = 0; j < perm.size() + 1; j++) {
			string new_string = perm.substr(0,j-1) + c + perm.substr(j,perm.size());
			new_perms.push_back(new_string);
		}
	}
	old_perms = new_perms;
	return old_perms;
}

int main() {
	return 0;
}
