int number_of_paths(int s_x,int s_y,int X,int Y,int **grid) {
	if(s_x > (X - 1) || s_y > (Y - 1)) return 0;
	if(s_x == (X -1)) return 1;
	if(s_y == (Y - 1)) return 1;
	return number_of_paths(s_x + 1, s_y, X, Y, grid) + number_of_paths(s_x, s_y + 1,X,Y,grid);
}

int main() {
	return 0;
}
