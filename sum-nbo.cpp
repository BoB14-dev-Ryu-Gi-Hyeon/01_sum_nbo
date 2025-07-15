#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
	// 파일 불러오기, 읽기, 쓰기, 닫기
	FILE *thousand = fopen(argv[1], "r");
	uint32_t n1;
	fread(&n1, sizeof(n1), 2, thousand);
	fclose(thousand);

	FILE *five_hundred = fopen(argv[2], "r");
	uint32_t n2;
	fread(&n2, sizeof(n2), 2, five_hundred);
	fclose(five_hundred);

	FILE *two_hundred = fopen(argv[3], "r");
	uint32_t n3;
	fread(&n3, sizeof(n3), 2, two_hundred);
	fclose(two_hundred);

	// 출력순서 바꾸기 - htonl()
	n1 = htonl(n1);
	n2 = htonl(n2);
	n3 = htonl(n3);

	// 덧셈연산
	uint32_t res = n1+n2+n3;


	// 출력
	printf("1000(0x%08x) + 500(0x%08x) + 200(0x%08x)= 1700(0x%08x)\n",  n1, n2, n3, res);

	return 0;
}
