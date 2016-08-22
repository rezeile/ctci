#ifndef __LIST
#define __LIST

#include <sstream>
#include <iostream>
using namespace std;

void print_node(const node *head);
node *construct_list(stringstream &s);
void delete_list(node *head);

#endif
