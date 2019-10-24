#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<iomanip.h>
#include<string.h>

/*	these variables are made global,hence they can be changed from any
	function. */

char table[62], num1[300], num2[300], r[300];
int b1, b2;
long double n1, n2, op;

/*	When program runs gtable generates the base table */

void gtable(void)
{
	int i, j;

	for (i = 0, j = 48; i < 10; i++, j++)
	{
		table[i] = j;
	}

	for (i = 10, j = 65; i < 36; i++, j++)
	{
		table[i] = j;
	}

	for (i = 36, j = 97; i < 62; i++, j++)
	{
		table[i] = j;
	}
}

/*	this function takes in number, checks wheather it lies in it's base
	or not. if not then user has to input number again. after receiving
	correct number, it copies that number in global variable according
	to the value of parameter a  */

void gnum(int a)
{
	char n, num[300];
	int f, s, m, l, i, b;

	do
	{
		f = 0;
		cout << "\nEnter the number:\t";
		n = getchar();
		num[0] = n;
		for (i = 1; n != '\n'; i++)
		{
			n = getchar();
			num[i] = n;
		}

		cout << "Enter the base in which the given number is present:\t";
		cin >> b;

		for (i = 0; num[i] != '\n'; i++)
		{
			if (num[i] == '.' || num[0] == '-' || num[0] == '+')
			{
				goto xyz;
			}

			s = 0;
			l = b - 1;

			while (s <= l)
			{
				m = (s + l) / 2;
				if (num[i] == table[m])
				{
					goto xyz;
				}
				else if (num[i] > table[m])
				{
					s = m + 1;
				}
				else
				{
					l = m - 1;
				}
			}
			f = 1;
			break;
		xyz:
			;
		}

		if (f == 1)
		{
			cout << "The base you entered doesn't matches with the number.";
			cout << "\nEnter the number and base again.";
		}
	} while (f == 1);

	/*	if user doesn't enter the sign with the number then this will add
		+ sign to the number */

	if (a == 1)
	{
		if (num[0] != '+' && num[0] != '-')
		{
			num1[0] = '+';
			for (i = 0; num[i] != '\n'; i++)
			{
				num1[i + 1] = num[i];
			}
			num1[i + 1] = '\0';
		}
		else
		{
			for (i = 0; num[i] != '\n'; i++)
			{
				num1[i] = num[i];
			}
			num1[i] = '\0';
		}
		b1 = b;
	}
	if (a == 2)
	{
		if (num[0] != '+' && num[0] != '-')
		{
			num2[0] = '+';
			for (i = 0; num[i] != '\n'; i++)
			{
				num2[i + 1] = num[i];
			}
			num2[i + 1] = '\0';
		}
		else
		{
			for (i = 0; num[i] != '\n'; i++)
			{
				num2[i] = num[i];
			}
			num2[i] = '\0';
		}
		b2 = b;
	}
}

/*	this function converts the number in base 10 then it converts the
	number in passed value of parameter b */

void cbase(int a, int b)
{
	int i, ob, l1 = 0, l2 = 0, tl, f, l, m, p, j, k;
	char num[300], val[300], t;
	long double term, sum = 0, e, nb;
	unsigned long s, s1, x;

	//	copies number from global variable to temparary variable

	if (a == 1)
	{
		for (i = 0; num1[i] != '\0'; i++)
		{
			num[i] = num1[i];
		}
		num[i] = '\0';
		ob = b1;
	}
	if (a == 2)
	{
		for (i = 0; num2[i] != '\0'; i++)
		{
			num[i] = num2[i];
		}
		num[i] = '\0';
		ob = b2;
	}

	cout << "\nConverting the number to base 10.";

	while (num[l1] != '\0')	//this will tell total length
	{
		l1++;
	}

	while (num[l2] != '.' && num[l2] != '\0')	//this will tell length of whole part
	{
		l2++;
	}

	tl = l2 - 1;
	i = 0;

	if (num[0] == '-' || num[0] == '+')
	{
		i++;
		tl--;
	}

	for (; i < l1; i++, tl--)
	{
		if (i == l2)
		{
			i++;
		}

		f = 0;
		l = ob - 1;

		while (f <= l)
		{
			m = (f + l) / 2;

			if (table[m] == num[i])
			{
				p = m;
				break;
			}

			if (num[i] < table[m])
			{
				l = m - 1;
			}

			else
			{
				f = m + 1;
			}
		}

		e = (long double)pow(ob, tl);
		term = (long double)(p * e);

		cout << "\n" << num[i] << " X " << ob << "^" << tl << "=" << term;
		sum = sum + term;
	}

	if (num[0] == '-')
	{
		cout << "\n\nNumber in base 10 =\t-" << sum;
	}

	else
	{
		cout << "\n\nNumber in base 10 =\t+" << sum;
	}

	cout << "\n\nNow converting the number to base " << b;

	s = (unsigned long)sum;
	i = 0;
	nb = (unsigned long)b;

	while (s >= nb)
	{
		x = (unsigned long)fmod(s, nb);
		val[i] = table[x];
		i++;
		cout << endl << s << " / " << b << " = ";
		s = (unsigned long)(s / nb);
		cout << s << "\tRemainder=" << x;
	}

	val[i] = table[s];
	i++;

	if (num[0] == '-')
	{
		val[i] = '-';
		i++;
	}

	if (num[0] == '+')
	{
		val[i] = '+';
		i++;
	}

	val[i] = '\0';
	j = i - 1;
	k = 0;

	while (k < j)	//reversing the number
	{
		t = val[j];
		val[j] = val[k];
		val[k] = t;
		k++;
		j--;
	}

	if (l1 > l2)	//for decimal part
	{
		val[i] = '.';
		i++;
		s1 = (unsigned long)sum;
		sum = (long double)(sum - s1);
		cout << endl;
		for (j = 0; j < 5; j++)
		{
			cout << endl << sum << " X " << b << " = ";
			sum = (long double)(sum * b);
			cout << sum;
			s1 = (unsigned long)sum;
			val[i] = table[s1];
			i++;
			sum = (long double)(sum - s1);
		}
		val[i] = '\0';
	}

	cout << "\n\nThe number in base " << b << " =\t";

	for (i = 0; val[i] != '\0'; i++)
	{
		cout << val[i];
	}

	//	coping to global variable
	if (a == 1)
	{
		for (i = 0; val[i] != '\0'; i++)
		{
			num1[i] = val[i];
		}
		num1[i] = '\0';
		b1 = b;
	}

	if (a == 2)
	{
		for (i = 0; val[i] != '\0'; i++)
		{
			num2[i] = val[i];
		}
		num2[i] = '\0';
		b2 = b;
	}
}

//	this function convert a number in base 10 only

void bts1(int a)
{
	int i, ob, l1 = 0, l2 = 0, tl, f, l, m, p;
	char num[300];
	long double term, sum = 0, e;

	if (a == 1)
	{
		for (i = 0; num1[i] != '\0'; i++)
		{
			num[i] = num1[i];
		}
		num[i] = '\0';
		ob = b1;
	}
	if (a == 2)
	{
		for (i = 0; num2[i] != '\0'; i++)
		{
			num[i] = num2[i];
		}
		num[i] = '\0';
		ob = b2;
	}
	while (num[l1] != '\0')
	{
		l1++;
	}
	while (num[l2] != '.' && num[l2] != '\0')
	{
		l2++;
	}

	tl = l2 - 1;
	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		i++;
		tl--;
	}
	for (; i < l1; i++, tl--)
	{
		if (i == l2)
		{
			i++;
		}
		f = 0;
		l = ob - 1;
		while (f <= l)
		{
			m = (f + l) / 2;
			if (table[m] == num[i])
			{
				p = m;
				break;
			}
			if (num[i] < table[m])
			{
				l = m - 1;
			}
			else
			{
				f = m + 1;
			}
		}
		e = (long double)pow(ob, tl);
		term = (long double)(p * e);
		sum = sum + term;
	}
	if (a == 1)
	{
		n1 = sum;
	}
	if (a == 2)
	{
		n2 = sum;
	}
}

//	this function converts number from 10 to the given base

void bts2(void)
{
	int i, j, k;
	char t;
	long double s;
	unsigned long s1, x;

	s = op;
	i = 0;
	while (s >= b1)
	{
		x = (unsigned long)fmod(s, b1);
		r[i] = table[x];
		i++;
		s = (long double)(s / b1);
	}
	x = (unsigned long)s;
	r[i] = table[x];
	j = i;
	k = 0;
	while (k < j)
	{
		t = r[j];
		r[j] = r[k];
		r[k] = t;
		k++;
		j--;
	}
	i++;
	r[i] = '.';
	i++;
	s1 = (unsigned long)op;
	op = (long double)(op - s1);
	for (j = 0; j < 5; j++)
	{
		op = (long double)(op * b1);
		s1 = (unsigned long)op;
		r[i] = table[s1];
		i++;
		op = (long double)(op - s1);
	}
	r[i] = '\0';
}

void main()
{
	clrscr();
	gtable();

	int choise, b, a, i, l1, l2, l, s, j;
	char cn;

	cout << "Welcome Sir/Ma'am \nThis is calculator.";
	cout << "\nFor sake of convenience,highest number for a base is shown.\n";

	for (i = 0; i < 62; i++)
	{
		cout << i + 1 << "=" << table[i] << "\t";
	}

	do
	{
		cout << "\nNow,which function do you want to perform?";
		cout << "\n(Enter the number corresponding to the function)";
		cout << "\n1\tConvert Base \n2\tAddition \n3\tSubtraction";
		cout << "\n4\tMultiplication \n5\tDivision \n6\tNOT";
		cout << "\n7\tOR \n8\tAND\nChoise:\t";
		cin >> choise;

		if (choise == 1)	//convert base
		{
			a = 1;
			gnum(a);
			do
			{
				cout << "In which base do you want to convert the number?\t";
				cin >> b;
				if (b < 2 || b>62)
				{
					cout << "You entered wrong base. Please chose correct base.";
				}
			} while (b < 2 || b>62);
			cbase(1, b);
		}

		else if (choise == 2)	//addition
		{
			cout << "\nEnter the details of number 1:";
			a = 1;
			gnum(a);
			cout << "\nEnter the details of number 2:";
			a = 2;
			gnum(a);
			if (b1 != b2)
			{
				cout << "\nBase of both the numbers are not same.";
				cout << "\nIn which base do you want to see the answer?\t";
				cin >> b;
				cbase(1, b);
				cbase(2, b);
			}
			cout << "\n\nNumber 1\n";
			puts(num1);
			cout << "\n\nNumber 2\n";
			puts(num2);

			bts1(1);	//converts the number in base 10
			bts1(2);

			//in addition there will be 6 cases
			//here all cases are considerd

			if (num1[0] == '+' && num2[0] == '+')
			{
				op = n1 + n2;
				bts2();
				cout << "\n\nAddition\n+";
				puts(r);
			}

			if (num1[0] == '+' && num2[0] == '-')
			{
				if (n1 > n2)
				{
					op = n1 - n2;
					bts2();
					cout << "\n\nAddition\n+";
					puts(r);
				}
				if (n2 > n1)
				{
					op = n2 - n1;
					bts2();
					cout << "\n\nAddition\n-";
					puts(r);
				}
			}

			if (num1[0] == '-' && num2[0] == '+')
			{
				if (n1 > n2)
				{
					op = n1 - n2;
					bts2();
					cout << "\n\nAddition\n-";
					puts(r);
				}
				if (n2 > n1)
				{
					op = n2 - n1;
					bts2();
					cout << "\n\nAddition\n+";
					puts(r);
				}
			}

			if (num1[0] == '-' && num2[0] == '-')
			{
				op = n1 + n2;
				bts2();
				cout << "\n\nAddition\n-";
				puts(r);
			}
		}

		else if (choise == 3)	//subtraction
		{
			cout << "\nEnter the details of number 1:";
			a = 1;
			gnum(a);
			cout << "\nEnter the details of number 2:";
			a = 2;
			gnum(a);
			if (b1 != b2)
			{
				cout << "\nBase of both the numbers are not same.";
				cout << "\nIn which base do you want to see the answer?\t";
				cin >> b;
				cbase(1, b);
				cbase(2, b);
			}
			cout << "\n\nNumber 1\n";
			puts(num1);
			cout << "\n\nNumber 2\n";
			puts(num2);

			bts1(1);
			bts1(2);

			//subtraction will have 6 cases
			//here all the cases are considered

			if (num1[0] == '+' && num2[0] == '+')
			{
				if (n1 > n2)
				{
					op = n1 - n2;
					bts2();
					cout << "\n\nSubtraction\n+";
					puts(r);
				}
				if (n2 > n1)
				{
					op = n2 - n1;
					bts2();
					cout << "\n\nSubtraction\n-";
					puts(r);
				}
			}

			if (num1[0] == '+' && num2[0] == '-')
			{
				op = n1 + n2;
				bts2();
				cout << "\n\nSubtraction\n+";
				puts(r);
			}

			if (num1[0] == '-' && num2[0] == '+')
			{
				op = n1 + n2;
				bts2();
				cout << "\n\nSubtraction\n-";
				puts(r);
			}

			if (num1[0] == '-' && num2[0] == '-')
			{
				if (n1 > n2)
				{
					op = n1 - n2;
					bts2();
					cout << "\n\nSubtraction\n-";
					puts(r);
				}
				if (n2 > n1)
				{
					op = n2 - n1;
					bts2();
					cout << "\n\nSubtraction\n+";
					puts(r);
				}
			}
		}

		else if (choise == 4)	//multiplication
		{
			cout << "\nEnter the details of number 1:";
			a = 1;
			gnum(a);
			cout << "\nEnter the details of number 2:";
			a = 2;
			gnum(a);
			if (b1 != b2)
			{
				cout << "\nBase of both the numbers are not same.";
				cout << "\nIn which base do you want to see the answer?\t";
				cin >> b;
				cbase(1, b);
				cbase(2, b);
			}
			cout << "\n\nNumber 1\n";
			puts(num1);
			cout << "\n\nNumber 2\n";
			puts(num2);

			bts1(1);
			bts1(2);

			if ((num1[0] == '+' && num2[0] == '+') || (num1[0] == '-' && num2[0] == '-'))
			{
				op = n1 * n2;
				bts2();
				cout << "\n\nMultiplication\n+";
				puts(r);
			}
			else
			{
				op = n1 * n2;
				bts2();
				cout << "\n\nMultiplication\n-";
				puts(r);
			}
		}

		else if (choise == 5)	//division
		{
			cout << "\nEnter the details of number 1:";
			a = 1;
			gnum(a);
			cout << "\nEnter the details of number 2:";
			a = 2;
			gnum(a);
			if (b1 != b2)
			{
				cout << "\nBase of both the numbers are not same.";
				cout << "\nIn which base do you want to see the answer?\t";
				cin >> b;
				cbase(1, b);
				cbase(2, b);
			}
			cout << "\n\nNumber 1\n";
			puts(num1);
			cout << "\n\nNumber 2\n";
			puts(num2);

			bts1(1);
			bts1(2);
			if (n2 == 0)
			{
				cout << "\nCan't divide by 0.";
			}
			else
			{
				if ((num1[0] == '+' && num2[0] == '+') || (num1[0] == '-' && num2[0] == '-'))
				{
					op = n1 / n2;
					bts2();
					cout << "\n\nDivition\n+";
					puts(r);
				}
				else
				{
					op = n1 / n2;
					bts2();
					cout << "\n\nDivition\n-";
					puts(r);
				}
			}
		}

		else if (choise == 6) 	//NOT
		{
			cout << "\nEnter the details of number 1:";
			a = 1;
			gnum(a);
			if (b1 != 2)
			{
				cbase(1, 2);
			}
			cout << "\n\nNumber\n";
			puts(num1);
			for (i = 1; num1[i] != '\0'; i++)
			{
				if (num1[i] == '.')
				{
					i++;
				}
				if (num1[i] == '0')
				{
					num1[i] = '1';
				}
				else
				{
					num1[i] = '0';
				}
			}
			cout << "\n\nNOT\n";
			puts(num1);
		}

		else if (choise == 7)  	//OR
		{
			cout << "\nEnter the details of number 1:";
			a = 1;
			gnum(a);
			cout << "\nEnter the details of number 2:";
			a = 2;
			gnum(a);
			if (b1 != 2)
			{
				cbase(1, 2);
			}
			if (b2 != 2)
			{
				cbase(2, 2);
			}
			l1 = 0;
			l2 = 0;
			for (i = 0; num1[i] != '\0'; i++)
			{
				l1++;
			}
			for (i = 0; num2[i] != '\0'; i++)
			{
				l2++;
			}
			if (l1 > l2)
			{
				l = l1 - l2;
				s = l2;
				for (i = 0; i < l; i++)
				{
					for (j = 1; j < l2; j++, s--)
					{
						num2[s] = num2[s - 1];
					}
					num2[1] = '0';
					l2++;
					s = l2;
					num2[s] = '\0';
				}
			}
			if (l2 > l1)
			{
				l = l2 - l1;
				s = l1;
				for (i = 0; i < l; i++)
				{
					for (j = 1; j < l1; j++, s--)
					{
						num1[s] = num1[s - 1];
					}
					num1[1] = '0';
					l1++;
					s = l1;
					num1[s] = '\0';
				}
			}

			cout << "\n\nNumber 1\n";
			for (i = 1; num1[i] != '\0'; i++)
			{
				cout << num1[i];
			}
			cout << "\n\nNumber 2\n";
			for (i = 1; num2[i] != '\0'; i++)
			{
				cout << num2[i];
			}
			for (i = 1; num1[i] != '\0'; i++)
			{
				if (num1[i] == '0' && num2[i] == '0')
				{
					r[i] = '0';
				}
				else
				{
					r[i] = '1';
				}
			}
			cout << "\n\nOR\n";
			for (i = 1; r[i] != '\0'; i++)
			{
				cout << r[i];
			}
		}

		else if (choise == 8) 	//AND
		{
			cout << "\nEnter the details of number 1:";
			a = 1;
			gnum(a);
			cout << "\nEnter the details of number 2:";
			a = 2;
			gnum(a);
			if (b1 != 2)
			{
				cbase(1, 2);
			}
			if (b2 != 2)
			{
				cbase(2, 2);
			}
			l1 = 0;
			l2 = 0;
			for (i = 0; num1[i] != '\0'; i++)
			{
				l1++;
			}
			for (i = 0; num2[i] != '\0'; i++)
			{
				l2++;
			}
			if (l1 > l2)
			{
				l = l1 - l2;
				s = l2;
				for (i = 0; i < l; i++)
				{
					for (j = 1; j < l2; j++, s--)
					{
						num2[s] = num2[s - 1];
					}
					num2[1] = '0';
					l2++;
					s = l2;
					num2[s] = '\0';
				}
			}
			if (l2 > l1)
			{
				l = l2 - l1;
				s = l1;
				for (i = 0; i < l; i++)
				{
					for (j = 1; j < l1; j++, s--)
					{
						num1[s] = num1[s - 1];
					}
					num1[1] = '0';
					l1++;
					s = l1;
					num1[s] = '\0';
				}
			}

			cout << "\n\nNumber 1\n";
			for (i = 1; num1[i] != '\0'; i++)
			{
				cout << num1[i];
			}
			cout << "\n\nNumber 2\n";
			for (i = 1; num2[i] != '\0'; i++)
			{
				cout << num2[i];
			}
			for (i = 1; num1[i] != '\0'; i++)
			{
				if (num1[i] == '1' && num2[i] == '1')
				{
					r[i] = '1';
				}
				else
				{
					r[i] = '0';
				}
			}
			cout << "\n\nOR\n";
			for (i = 1; r[i] != '\0'; i++)
			{
				cout << r[i];
			}

		}
		else
		{
			cout << "\nWrong choise";
		}
		cout << "\n\nDo you want to continue?\n(Press y for YES and any other key for NO)";
		cin >> cn;
	} while (cn == 'y' || cn == 'Y');

}