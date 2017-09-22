#undef KEY
#undef BUFLEN

template <int XORSTART, int BUFLEN, int XREFKILLER>
class XorStr
{
public:
	char s[BUFLEN];
	XorStr(const char* xs);
#ifndef DEBUG_OPTION
	~XorStr() { for (int i = 0; i<BUFLEN; i++)s[i] = 0; }
#endif

private:
	XorStr();
};

template <int XORSTART, int BUFLEN, int XREFKILLER>
XorStr<XORSTART, BUFLEN, XREFKILLER>::XorStr(const char* xs)
{
	int xvalue = XORSTART;
	int i = 0;
	for (; i<(BUFLEN - 1); i++) {
		s[i] = xs[i - XREFKILLER] ^ xvalue;
		xvalue += 1;
		xvalue %= 256;
	}
	s[BUFLEN - 1] = 0;
}