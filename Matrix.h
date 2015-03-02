class Matrix {
	float ms[2][2]; 

public:
	Matrix(); 

	Matrix(float m[2][2]); 

	Matrix(float x0, float x1, float y0, float y1);

	~Matrix(); 

	const char *display(); 

	Matrix operator +(Matrix m2);

	Matrix operator * (Matrix b);
};
