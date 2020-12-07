#include<iostream>
#include<math.h>
#include<cmath>

using namespace std;

class DT
{
private:
	int n;
	double* a;
public:
	DT()//ham tao khong doi
	{
		this->n = 0;this->a = NULL;
	}
	DT(int n1)//ham tao 1 doi
	{
		this->n = n1;
		this->a = new double[n1 + 1];
	}
	int getN() { return n; }
	friend ostream& operator<<(ostream& os, const DT& d);
	friend istream& operator>>(istream& is, DT& d);
	DT operator-()//ham dao dau cua da thuc
	{
		for (int i = 0; i <= this->n; i++)
		{
			this->a[i] = -this->a[i];
		}
		return *this;
	}
	DT operator+(const DT& d2);//ham cong
	DT operator-(const DT& d2);//ham tru
	DT operator*(const DT& d2);//ham nhan
	double operator ^(const double& x);//da thuc mu x
	double operator[](int i)//truy nhap vao 1 he so bat ki cua da thuc
	{
		if (i < 0)
			return double(n);
		else
			return a[i];
	}
	DT(DT& d2);//ham thiet lap sao chep
	DT& operator=(const DT& d2);
	~DT();//ham huy
};

ostream& operator<<(ostream& os, const DT& d)
{
	cout << "da thuc la :";
	os << *(d.a);
	for (int i = 1;i <= d.n;i++)
	{
		if (*(d.a + i) >= 0)
		{
			os << "+" << *(d.a + i) << "X^" << i;
		}
		else
		{
			os << *(d.a + i) << "X^" << i;
		}
	}
	return os;
}
istream& operator>>(istream& is, DT& d)
{
	cout << "nhap bac cua da thuc :" << endl;
	is >> d.n;
	d.a = new double[d.n];
	cout << "nhap he so cua da thuc tu bac thap nhat :" << endl;
	for (int i = 0;i <= d.n;i++)
	{
		is >> *(d.a + i);
	}
	return is;
}

DT DT::operator+(const DT& d2)
{
	DT sum;
	if (d2.n > n)
	{
		sum.n = d2.n;
	}
	else
		sum.n = n;
	sum.a = new double[sum.n];
	for (int i = 0;i <= sum.n; i++)
	{
		*(sum.a + i) = *(a + i) + *(d2.a + i);
	}
	return sum;
}
DT DT::operator-(const DT& d2)
{
	DT sub;
	if (d2.n > n)
	{
		sub.n = d2.n;
	}
	else
		sub.n = n;
	sub.a = new double[sub.n];
	for (int i = 0;i <= sub.n; i++)
	{
		*(sub.a + i) = *(a + i) - *(d2.a + i);
	}
	return sub;
}

DT DT::operator*(const DT& d2)
{
	DT mul;
	mul.n = n + d2.n;
	mul.a = new double[mul.n];
	//*(d.a) = *d1.a * *d2.a;
	for (int i = 0;i <= mul.n;i++)
	{
		*(mul.a + i) = 0;
	}
	for (int i = 0;i <= n;i++)
	{
		for (int j = 0;j <= d2.n;j++)
		{
			*(mul.a + j + i) = *(a + i) * *(d2.a + j) + *(mul.a + j + i);
		}
	}
	return mul;
}

DT::DT(DT& d2) {
	int i;
	cout << "su dung ham tao sao chep: " << endl;
	cout << "tao doi tuong " << this << endl;
	//xin cap phat bo nho dong bang kich thuoc co doi tuong cu
	a = new double[n = d2.n];
	cout << "xin cap phat bo nho " << n << " so thuc tai" << a << endl;
	for (i = 0;i <= n;i++)
	{
		a[i] = d2.a[i];//gan doi tuong cu sang moi
	}
}
DT::~DT()
{
	cout << "giai phong " << a << " cua doi tuong tai " << this << endl;
	delete[] a;
}

DT& DT::operator=(const DT& d2) {
	if (n != d2.n) {
		delete[] a;
		n = d2.n;
		a = new double[n];
	}
	for (int i = 0;i <= n;i++)
	{
		a[i] = d2.a[i];
	}
	return *this;
}
double DT::operator^(const double& x)
{
	double f = 0;
	for (int i = 0; i <= n; i++)
	{
		f += a[i] * pow(x, i);
	}
	return f;
}
double F(DT& f, double x)
{
	double F = 0;
	int size = f.getN();
	for (int i = 0; i <= size; i++)
	{
		F += f[i] * pow(x, i);
	}
	return F;
}

int main()
{
	DT p, q, r, s, f;
	cin >> p >> q >> r >> s;
	f = -(p + q) * (r - s);
	cout << f << endl;
	cout << F(f, 3) << endl;
	DT z = p;
	cout << p << endl;
}
