#include "Headers/VEST_ALL.h"
#include "Headers/VEST_LEXER.h"

using namespace VEST;

static void ShellProc() {
	VEST_STREAM InputStream;
	VEST_STREAM OutputStream;
	InputStream.InitStdin();
	OutputStream.InitStdout();

	OutputStream.Write("VEST SHELL\n", sizeof("VEST SHELL\n"));
	OutputStream.Write("Thank you for using VEST Shell!!!\n",sizeof("Thank you for using VEST Shell!!!\n"));
	OutputStream.Write("Type 'exit' to exit the shell.\n\n", sizeof("Type 'exit' to exit the shell.\n\n"));
	
	while (true) {
		char Input[25565] = "";
		OutputStream.Write("VEST>>>", sizeof("VEST>>>"));
		InputStream.Read(Input, sizeof(Input));
		if (Input[0] == 'e' && Input[1] == 'x' && Input[2] == 'i' && Input[3] == 't') break;
		OutputStream.Write(Input, sizeof(Input));
	}
	return;
}

int main() {
	/*
	VEST_STREAM stream;
	stream.InitStdout();
	stream.Write("Hello,world!!!",sizeof("Hello,world!!!"));

    #define int VEST_INT
	int x;
	x = 10;
    #undef int
	*/
	ShellProc();

	return 0;
}