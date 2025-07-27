#include "../lexer/token.hpp"
#include <iostream>
#include <string>
using namespace std;
string buf, t;
vector <vest_token> tokens;
int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	while (getline(cin, t))
	{
		buf += t;
		buf += '\n';
	}
	tokens = tokenize(buf);
	for (vector <vest_token> ::iterator p = tokens.begin(); 
		p != tokens.end(); p++)
	{
		switch ((*p).type)
		{
			case int_:
				cout << "(interger) " << ((vest_token_int *) (*p).data) -> num << endl;
				break;
			case flt_:
				cout << "(float) " << ((vest_token_float *) (*p).data) -> num << endl;
				break;
			case com_:
				cout << "(comma)" << endl;
				break;
			case brc_:
				cout << "(bracket) ";
				if (((vest_token_bracket *) (*p).data) -> dir) cout << "post ";
				else cout << "pre ";
				switch (((vest_token_bracket *) (*p).data) -> btype)
				{
					case round_: cout << "round"; break;
					case squar_: cout << "square"; break;
					case curly_: cout << "curly"; break;
					default: cout << "???";
				}
				cout << endl;
				break;
			case opr_:
				cout << "(operator) ";
				switch (((vest_token_operator *) (*p).data) -> op)
				{
					case add_: cout << "plus"; break;
					case sub_: cout << "minus"; break;
					case mul_: cout << "times"; break;
					case div_: cout << "divide"; break;
					case pow_: cout << "power"; break;
					case mod_: cout << "modulus"; break;
					case not_: cout << "not"; break;
					case and_: cout << "and"; break;
					case or_: cout << "or"; break;
					case xor_: cout << "xor"; break;
					case lt_: cout << "less than"; break;
					case gt_: cout << "greater than"; break;
					case le_: cout << "less than or equal to"; break;
					case ge_: cout << "greater than or equal to"; break;
					case eq_: cout << "equal to"; break;
					case ne_: cout << "not equal to"; break;
					case assign_: cout << "assignment"; break;
					case attribute_: cout << "attribute"; break;
					case add_eq_: cout << "plus equals"; break;
					case sub_eq_: cout << "minus equals"; break;
					case mul_eq_: cout << "times equals"; break;
					case div_eq_: cout << "divide equals"; break;
					case mod_eq_: cout << "modulus equals"; break;
					case pow_eq_: cout << "power equals"; break;
					case and_eq_: cout << "and equals"; break;
					case or_eq_: cout << "or equals"; break;
					case xor_eq_: cout << "xor equals"; break;
					case logical_and_: cout << "logical and"; break;
					case logical_or_: cout << "logical or"; break;
					case logical_xor_: cout << "logical xor"; break;
					default: cout << "???";
				}
				cout << endl;
				break;
			case idn_:
				cout << "(identifier) " << ((vest_token_identifier *) (*p).data) -> text << endl;
				break;
			case kwd_:
				cout << "(keyword) " << ((vest_token_keyword *) (*p).data) -> text << endl;
				break;
			case str_:
				cout << "(string) " << ((vest_token_string *) (*p).data) -> text << endl;
				break;
			case cmt_:
				cout << "(comment) " << ((vest_token_comment *) (*p).data) -> text << endl;
				break;
			case smc_:
				cout << "(semicolon)" << endl;
				break;
			default:
				char ch = ((vest_token_unknown *) (*p).data) -> ch;
				if (ch == '#')
					cout << "(preprocessor)" << endl;
				else if (isspace(ch))
					if (ch == '\n')
						cout << "(newline)" << endl;
					else if (ch == '\t')
						cout << "(tab)" << endl;
					else if (ch == ' ')
						cout << "(space)" << endl;
					else if (ch == '\r')
						cout << "(carriage return)" << endl;
					else if (ch == '\v')
						cout << "(vertical tab)" << endl;
					else if (ch == '\f')
						cout << "(form feed)" << endl;
				else
					cout << "(unknown) " << ch << endl;
				break;
		}
	}
	return 0;
}
