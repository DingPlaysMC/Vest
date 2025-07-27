#ifndef VEST_TOKEN_HPP
#define VEST_TOKEN_HPP

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstddef>
#include <string>
#include <vector>
using namespace std;
//#include "runtime.h"
#ifndef bool_
#define bool_ int
#endif

enum vest_token_type {int_, flt_, str_, brc_, com_, 
				idn_, kwd_, opr_, ukn_, smc_,
				cmt_};
enum vest_bracket_type {round_, squar_, curly_};
enum vest_oper_type {add_, sub_, mul_, div_, mod_, 
				pow_, and_, or_, not_, xor_, 
				lt_, gt_, le_, ge_, eq_, 
				logical_and_, logical_or_, logical_xor_, ne_, assign_, 
				attribute_, add_eq_, sub_eq_, mul_eq_, div_eq_,
				mod_eq_, pow_eq_, and_eq_, or_eq_, xor_eq_};
string vest_keywords[] = {
    // keywords from C
    "auto", "break", "case", "char", "const",
    "continue", "default", "do", "else",
    "enum", "extern", "for", "goto",
    "if", "register", "return",
    "sizeof", "static", "struct",
    "switch", "typedef", "union", "while", 
    // keywords from Python
    "and", "as", "async", "await", "class",
    "continue", "func", "elif", "catch", "finally",
    "from", "global", "if", "import", "in",
    "is", "lambda", "nonlocal", "not", "or",
    // add more keywords here
};
#define vest_keyword_count (sizeof(vest_keywords)/sizeof(vest_keywords[0]))

// operator adding has been completed

class vest_token_data
{
	// empty
};

class vest_token_int: public vest_token_data
{
	public:
		int num;
};

class vest_token_float: public vest_token_data
{
	public:
		double num;
};

class vest_token_bracket: public vest_token_data
{
	public:
		vest_bracket_type btype;
		bool dir;
};

class vest_token_comma: public vest_token_data
{
	// empty
};

class vest_token_keyword: public vest_token_data
{
	public:
		string text;
};

class vest_token_identifier: public vest_token_data
{
	public:
		string text;
};

class vest_token_string: public vest_token_data
{
	public:
		string text;
};

class vest_token_operator: public vest_token_data
{
	public:
		vest_oper_type op;	
};

class vest_token_semicolon: public vest_token_data
{
	// empty
};

class vest_token_comment: public vest_token_data
{
	public:
		string text;
};

class vest_token_unknown: public vest_token_data
{
	public:
		char ch;
};

class vest_token
{
	public:
		size_t lineno;
		size_t charno;
		size_t len;
		vest_token_type type;
		vest_token_data *data;
		void set_token(vest_token_type t)
		{
			type = t;
			switch (t)
			{
				case int_:
					data = new vest_token_int;
					break;
				case flt_:
					data = new vest_token_float;
					break;
				case com_:
					data = new vest_token_comma;
					break;
				case brc_:
					data = new vest_token_bracket;
					break;
				case opr_:
					data = new vest_token_operator;
					break;
				case idn_:
					data = new vest_token_identifier;
					break;
				case kwd_:
					data = new vest_token_keyword;
					break;
				case str_:
					data = new vest_token_string;
					break;
				case cmt_:
					data = new vest_token_comment;
					break;
				case smc_:
					data = new vest_token_semicolon;
					break;
				default:
					data = new vest_token_unknown;
					break;
			}
		}
		template <class T>
		void set_token()
		{
			
		}
		vest_token(vest_token_type t)
		{
			set_token(t);
		}
		vest_token(const vest_token & vd)
		{
			lineno = vd.lineno;
			charno = vd.charno;
			len = vd.len;
			set_token(vd.type);
			switch (type)
			{
				case int_:
					*((vest_token_int *) data) = *((vest_token_int *) vd.data);
					break;
				case flt_:
					*((vest_token_float *) data) = *((vest_token_float *) vd.data);
				case com_:
					*((vest_token_comma *) data) = *((vest_token_comma *) vd.data);
					break;
				case brc_:
					*((vest_token_bracket *) data) = *((vest_token_bracket *) vd.data);
					break;
				case opr_:
					*((vest_token_operator *) data) = *((vest_token_operator *) vd.data);
					break;
				case idn_:
					*((vest_token_identifier *) data) = *((vest_token_identifier *) vd.data);
					break;
				case kwd_:
					*((vest_token_keyword *) data) = *((vest_token_keyword *) vd.data);
					break;
				case str_:
					*((vest_token_string *) data) = *((vest_token_string *) vd.data);
					break;
				case cmt_:
					*((vest_token_comment *) data) = *((vest_token_comment *) vd.data);
					break;
				case smc_:
					*((vest_token_semicolon *) data) = *((vest_token_semicolon *) vd.data);
					break;
				default:
					*((vest_token_unknown *) data) = *((vest_token_unknown *) vd.data);
					break;
			}
		}
		vest_token & operator=(const vest_token & vd)
		{
			delete data;
			lineno = vd.lineno;
			charno = vd.charno;
			len = vd.len;
			set_token(vd.type);
			switch (type)
			{
				case int_:
					*((vest_token_int *) data) = *((vest_token_int *) vd.data);
					break;
				case flt_:
					*((vest_token_float *) data) = *((vest_token_float *) vd.data);
				case com_:
					*((vest_token_comma *) data) = *((vest_token_comma *) vd.data);
					break;
				case brc_:
					*((vest_token_bracket *) data) = *((vest_token_bracket *) vd.data);
					break;
				case opr_:
					*((vest_token_operator *) data) = *((vest_token_operator *) vd.data);
					break;
				case idn_:
					*((vest_token_identifier *) data) = *((vest_token_identifier *) vd.data);
					break;
				case kwd_:
					*((vest_token_keyword *) data) = *((vest_token_keyword *) vd.data);
					break;
				case str_:
					*((vest_token_string *) data) = *((vest_token_string *) vd.data);
					break;
				case cmt_:
					*((vest_token_comment *) data) = *((vest_token_comment *) vd.data);
					break;
				case smc_:
					*((vest_token_semicolon *) data) = *((vest_token_semicolon *) vd.data);
					break;
				default:
					*((vest_token_unknown *) data) = *((vest_token_unknown *) vd.data);
					break;
			}
			return *this;
		}
		~vest_token()
		{
			delete data;
		}
};

/*
 * size_t tokenize(char *, vest_token *)
 * Turns paramenter [code] into vest tokens stored in paramenter [tokens].
 * Returns the length of [tokens].
 * Remember to free [tokens] after use. 
*/
vector <vest_token> tokenize(string code)
{
	//printf("start parsing\n");
	vector <vest_token> tokens;
	for (string::iterator p = code.begin(); p != code.end(); )
	{
		int ft = 0;
		vest_token tok(ukn_);
		if (*p == ',')
		{
			tok = vest_token(com_);
			ft = 1;
		}
		else if (*p == ';')
		{
			tok = vest_token(smc_);
			ft = 1;
		}
		else if (*p == '(')
		{
			tok = vest_token(brc_);
			((vest_token_bracket *) tok.data) -> btype = round_;
			((vest_token_bracket *) tok.data) -> dir = 0;
			ft = 1;
		}
		else if (*p == ')')
		{
			tok = vest_token(brc_);
			((vest_token_bracket *) tok.data) -> btype = round_;
			((vest_token_bracket *) tok.data) -> dir = 1;
			ft = 1;
		}
		else if (*p == '[')
		{
			tok = vest_token(brc_);
			((vest_token_bracket *) tok.data) -> btype = squar_;
			((vest_token_bracket *) tok.data) -> dir = 0;
			ft = 1;
		}
		else if (*p == ']')
		{
			tok = vest_token(brc_);
			((vest_token_bracket *) tok.data) -> btype = squar_;
			((vest_token_bracket *) tok.data) -> dir = 1;
			ft = 1;
		}
		else if (*p == '{')
		{
			tok = vest_token(brc_);
			((vest_token_bracket *) tok.data) -> btype = curly_;
			((vest_token_bracket *) tok.data) -> dir = 0;
			ft = 1;
		}
		else if (*p == '}')
		{
			tok = vest_token(brc_);
			((vest_token_bracket *) tok.data) -> btype = curly_;
			((vest_token_bracket *) tok.data) -> dir = 1;
			ft = 1;
		}
		else if (*p == '+')
			if (*(p + 1) == '=')
			{
				// come oooooooooooooooooooooon!!
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = add_eq_;
				ft = 2;
			}
			else
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = add_;
				ft = 1;
			}
		else if (*p == '*')
			if (*(p + 1) == '\0' && *(p + 1) == '*')
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = pow_;
				ft = 2;
			}
			else if (*(p + 1) == '=')
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = mul_eq_;
				ft = 2;
			}
			else
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = mul_;
				ft = 1;
			}
		else if (*p == '/')
		{
			if (*(p + 1) == '=')
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = div_eq_;
				ft = 2;
			}
			else if (*(p + 1) == '/')
			{
				tok = vest_token(cmt_);
				((vest_token_comment *) tok.data) -> text = "";
				for (p += 2; p != code.end() && *p != '\n'; p++)
					((vest_token_comment *) tok.data) -> text.push_back(*p);
				p--;
				ft = 1;
			}
			else if (*(p + 1) == '*')
			{
				tok = vest_token(cmt_);
				((vest_token_comment *) tok.data) -> text = "";
				for (p += 2; p + 1 != code.end() && (*p != '*' || *(p + 1) != '/'); p++)
					((vest_token_comment *) tok.data) -> text.push_back(*p);
				if (*p == '*') p++;
				if (*p == '/') p++;
				p--;
				ft = 1;
			}
			else
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = div_;
				ft = 1;
			}
		}
		else if (*p == '%')
			if (*(p + 1) == '=')
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = mod_eq_;
				ft = 2;
			}
			else
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = mod_;
				ft = 1;
			}
		else if (*p == '.')
		{
			tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = attribute_;
			ft = 1;
		}
		else if (*p == '!')
			if (*(p + 1) == '=')
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = ne_;
				ft = 2;
			}
			else
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = not_;
				ft = 1;
			}
		else if (*p == '&')
			if (*(p + 1) == '=')
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = and_eq_;
				ft = 2;
			}
			else if (*(p + 1) == '&')
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = logical_and_;
				ft = 2;
			}
			else
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = and_;
				ft = 1;
			}
		else if (*p == '|')
			if (*(p + 1) == '=')
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = xor_eq_;
				ft = 2;
			}
			else if (*(p + 1) == '|')
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = logical_or_;
				ft = 2;
			}
			else 
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = or_;
				ft = 1;
			}
		else if (*p == '^')
			if (*(p + 1) == '^')
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = logical_xor_;
				ft = 2;
			}
			else
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = xor_;
				ft = 1;
			}
		else if (*p == '=')
			if (*(p + 1) == '=')
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = eq_;
				ft = 2;
			}
			else
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = assign_;
				ft = 1;
			}
		else if (*p == '>')
			if (*(p + 1) == '=')
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = ge_;
				ft = 2;
			}
			else
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = gt_;
				ft = 1;
			}
		else if (*p == '<')
			if (*(p + 1) == '=')
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = le_;
				ft = 2;
			}
			else
			{
				tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = lt_;
				ft = 1;
			}
		
		else if (*p == '0' && *(p + 1) != 0 && 
			strchr("bBoOxX", *(p + 1)) != 0)
		{
			if (tolower(*(p + 1)) == 'x')
			{
				p += 2;
				int n = 0;
				tok = vest_token(int_);
				for (; p != code.end() && isxdigit(*p); p++)
				{
					n <<= 4;
					if (*p >= '0' && *p <= '9') n |= *p - '0';
					else if (*p >= 'A' && *p <= 'F') n |= *p - 'A' + 10;
					else if (*p >= 'a' && *p <= 'f') n |= *p - 'a' + 10;
				}
				((vest_token_int *) tok.data) -> num = n;
			}
			else if (tolower(*(p + 1)) == 'b')
			{
				p += 2;
				int n = 0;
				tok = vest_token(int_);
				for (; p != code.end() && (*p == '0' || *p == '1'); p++)
				{
					n <<= 1;
					if (*p == '1') n |= 1;
				}
				((vest_token_int *) tok.data) -> num = n;
			}
			else if (*(p + 1) == 'o')
			{
				p += 2;
				int n = 0;
				tok = vest_token(int_);
				for (; *p != 0 && isdigit(*p); p++)
				{
					n <<= 3;
					if (*p >= '0' && *p <= '7') n |= *p - '0';
				}
				((vest_token_int *) tok.data) -> num = n;
			}
		}
		else if (isdigit(*p) || 
			(*p == '-' && p + 1 != code.end() && isdigit(*(p + 1))))
		{
			int n = 0;
			bool_ f = 0;
			if (*p == '-')
			{
				f = 1;
				p++;
			}
			while (isdigit(*p))
				n = n * 10 + *(p++) - '0';
			if (*p == '.')
			{
				p++;
				double t, x = n;
				for (t = 10; *p != '\0' && isdigit(*p) && t <= 1e20; t *= 10)
					x = (x * t + *(p++) - '0') / t;
				if (f) x *= -1;
				while (isdigit(*p)) p++;
				tok = vest_token(flt_);
				((vest_token_float *) tok.data) -> num = x;
			}
			else
			{
				if (f) n *= -1;
				tok = vest_token(int_);
				((vest_token_int *) tok.data) -> num = n;

			}
		}
		else if (*p == '-')
		{
			tok = vest_token(opr_);
				((vest_token_operator *) tok.data) -> op = sub_;
			ft = 1;
		}
		else if (*p == '_' || isalpha(*p))
		{
			string t;
			for (; p != code.end() && (*p == '_' || isalnum(*p)); p++)
				t.push_back(*p);
			bool f = 0;
			for (size_t i = 0; i < vest_keyword_count; i++)
			{
				if (t == vest_keywords[i])
				{
					f = 1;
					break;
				}
			}
			if (f)
			{
				tok = vest_token(kwd_);
				((vest_token_keyword *) tok.data) -> text = t;
			}
			else
			{
				tok = vest_token(idn_);
				((vest_token_identifier *) tok.data) -> text = t;
			}
			p--;
			ft = 1;
		}
		else if (*p == '"')
		{
			tok = vest_token(str_);
			((vest_token_string *) tok.data) -> text = "";
			for (; p != code.end() && *p != '"'; p++)
			{
				char c;
				if (*p == '\\')
				{
					p++;
					if (*p == 'n') c = '\n';
					else if (*p == 't') c = '\t';
					else if (*p == 'r') c = '\r';
					else if (*p == 'a') c = '\a';
					else if (*p == 'b') c = '\b';
					else if (*p == 't') c = '\t';
					else if (*p == 'f') c = '\f';
					else if (*p == 'v') c = '\v';
					else if (*p == '0') c = '\0';
					else if (*p == '?') c = '?';
					else if (*p == 'x' && isxdigit(*(p + 1)))
					{
						int i;
						for (c = 0, i = 0, p++; i < 2 && p != code.end() && isxdigit(*p); i++, p++)
						{
							c <<= 4;
							if (*p >= '0' && *p <= '9') c |= *p - '0';
							else if (*p >= 'A' && *p <= 'F') c |= *p - 'A' + 10;
							else if (*p >= 'a' && *p <= 'f') c |= *p - 'a' + 10;
						}
						if (i == 0) c = 'x'; 
						p--;
					}
					else if (isdigit(*p))
					{
						int i;
						for (c = 0, i = 0; i < 3 && p != code.end() && isdigit(*p); i++, p++)
						{
							c <<= 3;
							if (*p >= '0' && *p <= '7') c |= *p - '0';
						}
						p--;
					}
					else if (*p == '\\') c = '\\';
					else if (*p == '"') c = '"';
					else if (*p == '\'') c = '\'';
					else c = *p;
				}
				else
					c = *p;
				((vest_token_keyword *) tok.data) -> text.push_back(c);
			}
			ft = 1;
		}
		else
		{
			//throw_error("unknown token");
			tok = vest_token(ukn_);
			((vest_token_unknown *) tok.data) -> ch = *p;
			ft = 1;
		}
		tokens.push_back(tok);
		p += ft;
	}
	//printf("end parsing\n");
	return tokens;
}

#endif
