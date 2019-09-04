#ifndef VECTOR
#define VECTOR
class Vector
{
private:
	unsigned short int **vector;
	int const tamano = 4;
public:
	Vector();
	unsigned short int** getVector();
	void setVector(unsigned short int** NewArray);
};

#endif // !VECTOR