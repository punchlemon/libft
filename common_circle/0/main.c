
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include "libft/libft.h"

int check_isalpha(){
	for(int c = CHAR_MIN; c <= CHAR_MAX; c++){
		if(isalpha(c) != ft_isalpha(c)) {
			printf("ft_isalpha is error about %d\n", c);
			return (1);
		}
	}
	printf("ft_isalpha is all ok!\n");
	return (0);
}

int check_isdigit(){
	for(int c = CHAR_MIN; c <= CHAR_MAX; c++){
		if(isdigit(c) != ft_isdigit(c)) {
			printf("ft_isdigit is error about %d\n", c);
			return (1);
		}
	}
	printf("ft_isdigit is all ok!\n");
	return (0);
}

int check_isalnum(){
	for(int c = CHAR_MIN; c <= CHAR_MAX; c++){
		if(isalnum(c) != ft_isalnum(c)) {
			printf("ft_isalnum is error about %d\n", c);
			return (1);
		}
	}
	printf("ft_isalnum is all ok!\n");
	return (0);
}

int check_isascii(){
	for(int c = CHAR_MIN; c <= CHAR_MAX; c++){
		if(isascii(c) != ft_isascii(c)) {
			printf("ft_isascii is error about %d\n", c);
			return (1);
		}
	}
	printf("ft_isascii is all ok!\n");
	return (0);
}

int check_isprint(){
	for(int c = CHAR_MIN; c <= CHAR_MAX; c++){
		if(isprint(c) != ft_isprint(c)) {
			printf("ft_isprint is error about %d\n", c);
			return (1);
		}
	}
	printf("ft_isprint is all ok!\n");
	return (0);
}

int check_strlen(){
	char* a[] = {"hello", "\n", "", ""};
	for(int i = 0; i < 3; i++){
		if(strlen(a[i]) != ft_strlen(a[i])) {
			printf("ft_strlen is error about %d\n", i);
			return (1);
		}
	}
	if(strlen("world\n") != ft_strlen("world\n")) {
		printf("ft_strlen is error");
		return (1);
	}
	printf("ft_strlen is all ok!\n");
	return (0);
}

int check_memset(){
	int str_len = 5;
	char b[5];
	char ft_b[5];
	int len;
	int c = 'c';
	char *p = "hello";
	memcpy(b, p, str_len);
	memcpy(ft_b, p, str_len);
	len = 3;
	c = 'c';
	memset(b, c, len);
	ft_memset(ft_b, c, len);
	for(int i = 0; i < str_len; i++){
		if(b[i]!=ft_b[i]){
			printf("ft_memset is error about %d\n", i);
			return (1);
		}
	}
	memcpy(b, p, str_len);
	memcpy(ft_b, p, str_len);
	len = 6;
	// memset(b, c, len);  // lenが長くて入ってはいけない領域に入るとtrace trapをおこす
	ft_memset(ft_b, c, len);
	// for(int i = 0; i < str_len; i++){
	// 	if(b[i]!=ft_b[i]){
	// 		printf("ft_memset is error about %d\n", i);
	// 		return (1);
	// 	}
	// }
	memcpy(b, p, str_len);
	memcpy(ft_b, p, str_len);
	len = 3;
	c = -2147483648;
	memset(b, c, len);
	ft_memset(ft_b, c, len);
	for(int i = 0; i < len; i++){
		if(*(b+i)!=*(ft_b+i)){
			printf("ft_memset is error about %d\n", i);
			return (1);
		}
	}
	memcpy(b, p, str_len);
	memcpy(ft_b, p, str_len);
	c = 2147483647;
	memset(b, c, len);
	ft_memset(ft_b, c, len);
	for(int i = 0; i < len; i++){
		if(*(b+i)!=*(ft_b+i)){
			printf("ft_memset is error about %d\n", i);
			return (1);
		}
	}

	// memset("", c, len);
	// ft_memset("", c, len); どうやってtrace trapのエラーを出力するかわからない todo
	// memset(NULL, c, len);
	// ft_memset(NULL, c, len); segmentation faultどうやって検証するか
	printf("ft_memset is all ok!\n");
	return (0);
}

int check_bzero(){
	int str_len = 5;
	char b[5];
	char ft_b[5];
	int n;
	char *p = "hello";
	memcpy(b, p, str_len);
	memcpy(ft_b, p, str_len);
	n = 3;
	bzero(b, n);
	ft_bzero(ft_b, n);
	for(int i = 0; i < str_len; i++){
		if(b[i]!=ft_b[i]){
			printf("ft_bzero is error about %d\n", i);
			return (1);
		}
	}
	memcpy(b, p, str_len);
	memcpy(ft_b, p, str_len);
	n = 6;
	// bzero(b, c, len);  // lenが長くて入ってはいけない領域に入るとtrace trapをおこす
	ft_bzero(ft_b, n);
	// for(int i = 0; i < str_len; i++){
	// 	if(b[i]!=ft_b[i]){
	// 		printf("ft_bzero is error about %d\n", i);
	// 		return (1);
	// 	}
	// }

	// bzero("", n);
	// ft_bzero("", n); どうやってtrace trapのエラーを出力するかわからない todo
	// bzero(NULL, n);
	// ft_bzero(NULL, n); segmentation faultどうやって検証するか
	printf("ft_bzero is all ok!\n");
	return (0);
}

int check_memcpy(){
	int len = 0;
	char dst[10];
	char src[20];
	for(int i = 0; i < 10; i++){
		dst[i] = i + '0';
	}
	src[] = "hello";

	ft_memcpy(dst, NULL, len);
	for(int i = 0; i < 10; i++){
		write(1, dst + i, 1);
	}
}

// int check_strlcpy(){
// 	char* a[] = {"hello", "\n", "", ""};
// 	char str[] = "hello";
// 	str[4] = 040;
// 	a[3] = str;
// 	for(int i = 0; i < 3; i++){
// 		if(strlcpy(a[i]) != ft_strlcpy(a[i])) {
// 			printf("ft_strlcpy is error about %d\n", i);
// 			return (1);
// 		}
// 	}
// 	printf("ft_strlcpy is all ok!\n");
// 	return (0);
// }

int check_memmove(){
	int len = 0;
	char f[] = "0123456789";
	ft_memcpy(f, NULL, len);
	for(int i = 0; i < 10; i++){
		write(1, f + i, 1);
	}
}


int main(void){
	return (
		check_isalpha()
		|| check_isdigit()
		|| check_isalnum()
		|| check_isprint()
		|| check_strlen()
		|| check_memset()
		|| check_bzero()
		// || check_strlcpy()
	);
	// strlcpy("hello", "world", 0);
	// ft_strlcpy("hello", "world", 0);
}