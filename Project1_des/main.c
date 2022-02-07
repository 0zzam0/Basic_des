#define _CRT_SECURE_NO_WARNINGS    // scanf 보안 경고로 인한 컴파일 에러 방지
#pragma warning(disable:4996)

#include "head.h"
#include <stdio.h>
#include <stdint.h>
#include <Windows.h>


int IP_table[] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17,  9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

int IP_inverter[] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25

};

int E_table[] = {
    32,  1,  2,  3,  4,  5,
    4,  5,  6,  7,  8,  9,
    8,  9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32,  1
};

int P_table[] = {
    16, 7, 20, 21, 29, 12, 28, 17,
    1, 15, 23, 26, 5, 18, 31, 10,
    2, 8, 24, 14, 32, 27, 3, 9,
    19, 13, 30, 6, 22, 11, 4, 25
};

int S1[4][16] = {
    14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
    0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
    4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
    15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13,
};

int S2[4][16] = {
    15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
    3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
    0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 5, 10, 14, 7,
    13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9
};

int S3[4][16] = {
    10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
    13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
    13, 6, 4, 9, 8, 15, 3, 0, 11, 11, 2, 12, 5, 0, 14, 7,
    1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12
};

int S4[4][16] = {
    7, 13, 14, 3, 0, 6, 0, 10, 1, 2, 8, 5, 11, 12, 4, 15,
    13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
    10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 4, 8, 4,
    3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14
};

int S5[4][16] = {
    2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
    14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
    4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
    11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3
};

int S6[4][16] = {
    12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
    10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
    9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
    4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13
};

int S7[4][16] = {
    4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
    13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
    1, 4, 11, 13, 12, 4, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
    6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 2, 12
};

int S8[4][16] = {
    13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
    1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
    7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
    2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11
};

int PC_1[56]= { 
    57, 49, 41, 33, 25, 17,  9,
    1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27,
    19, 11,  3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14,  6, 61, 53, 45, 37, 29,
    21, 13,  5, 28, 20, 12,  4 };

int PC_2[48]= { 
    14, 17, 11, 24,  1,  5,
    3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32 };

void strToHex(char text[], uint8_t* data) {
    //16진수로 변환

//long data = strtoul(plain_text, NULL, 16);  <---- 최대값 이상
//9보다 큰 경우 : 알파벳 문자 'A' 이상인 문자로, 'A'를 빼고 10을 더함.
//9이하인 경우 : 숫자 입력으로 '0'을 빼면 실제 값이 구해짐.
    int i = 0;

    for (i = 0; i < 16; i++) {
        if (text[i] > '9') {
            data[i] = text[i] - 'a' + 10;
        }
        else {
            data[i] = text[i] - '0';
        }
    }
    //hhx : uint8_t 자료형 출력
    //i = 0;
    //for (i = 0; i < 16; i++) {
    //    printf("%hhx", data[i]);
    //}

    return 0;
}

void initialPermutation(uint8_t* data)
{
    int index1 = 0;
    int bit1 = 0;
    int index2 = 0;
    int bit2 = 0;
    int temp1 = 0;
    int temp2 = 0;

    
    for (int i = 0; i < 64; i++) {
        //plain text의 58번째(7) 비트 값 mask로 추출하기
        //바꿀 비트 index
        index1 = (IP_table[i] - 1) / 4;
        bit1 = (IP_table[i] - 1)% 4;
        //바뀔 비트 index
        index2 = i / 4;
        bit2 = i % 4;
        //temp1 = 바꿀 비트 , temp2 = 바뀔 비트 값
        temp1 = (data[index1] & (0x08 >> bit1)) >> (3 - bit1);
        temp2 = (data[index2] & (0x08 >> bit2)) >> (3 - bit2);
        //plain text의 1번째 비트 값 추출해서 바꾸기

        //1은 OR 0은 AND
        if (temp1 != temp2) {
            if (temp1 == 1) {
                data[index2] |= (0x08 >> bit2);
            }
            else {
                data[index2] & (0x07 >> bit2);
            }
        }

    }
    return 0;
}

void makeBlock32(uint8_t* data, uint8_t* L, uint8_t* R) {
    int i = 0;
    for (i = 0; i < 16; i++) {
        if (i < 8 ){
            L[i] = data[i];
        }
        else {
            R[i-8] = data[i];
        }
    }

    //i = 0;
    //for (i = 0; i < 8; i++) {
    //    printf("%hhx", L[i]);
    //}
    //printf("\n");
    //i = 0;
    //for (i = 0; i < 8; i++) {
    //    printf("%hhx", R[i]);
    //}
}
void extensionPermutation(uint8_t* R, uint8_t* R_E) {
    int index1 = 0;
    int bit1 = 0;
    int index2 = 0;
    int bit2 = 0;
    int temp1 = 0;
    int temp2 = 0;


    for (int i = 0; i < 48; i++) {
        //바꿀 비트 index
        index1 = (E_table[i] - 1) / 4;
        bit1 = (E_table[i] - 1) % 4;
        //바뀔 비트 index
        index2 = i / 4;
        bit2 = i % 4;
        //temp1 = 바꿀 비트 , temp2 = 바뀔 비트 값
        temp1 = (R[index1] & (0x08 >> bit1)) >> (3 - bit1);
        temp2 = (R[index2] & (0x08 >> bit2)) >> (3 - bit2);
        //plain text의 1번째 비트 값 추출해서 바꾸기

        //1은 OR 0은 AND
        if (temp1 != temp2) {
            if (temp1 == 1) {
                R_E[index2] |= (0x08 >> bit2);
            }
            else {
                R_E[index2] & (0x07 >> bit2);
            }
        }

    }
    return 0;
}


void XOR(uint8_t* bits1, uint8_t* bits2, uint8_t* result, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        result[i] = bits1[i] ^ bits2[i];
    }
}

void s_box(uint8_t* R, uint8_t* bits) {

}

void changeBits(uint8_t* L, uint8_t* R) {
    int i = 0;
    int j = 0;
    int k = 0;
    uint8_t temp[8] = { 0 };
    for (i = 0; i < 8; i++) {
        temp[i] = L[i];
    }

    for (j = 0; j < 8; j++) {
        L[j] = R[j];
    }

    for (k = 0; k < 8; k++) {
        R[k] = temp[k];
    }
}
int main()
{

    char plain_text[20] = "02468aceeca86420";
    char key[20] = "0x0f1571c947d9e859";
    unsigned char block_text[8] = { 0 };
    char chiper_text[20];

    //초기화면, Input key
    //printf("Input chiper key : ");
    //scanf("%x", &key);
    //printf("%x", key);
    //Sleep(1000);
    //system("cls");                                   //키 입력 후 콘솔 초기화

    //input plainText
    //printf("Input plain text : \n");
    //scanf("%s", &plain_text);

    int  i = 0;
    //IP
    uint8_t text[16] = { 0 };
    uint8_t* data = text;                                       //포인터에 배열할당

    //쪼개기
    uint8_t L_block[10] = { 0 };
    uint8_t R_block[10] = { 0 };
    uint8_t* L = L_block ;
    uint8_t* R = R_block;

    //E
    uint8_t R_Extention[20] = { 0 };
    uint8_t* R_E = R_Extention;

    strToHex(plain_text, data);
    initialPermutation(data);
    makeBlock32(data, L, R);
    extensionPermutation(R,R_E);

    printf("\n");
    for (i = 0; i < 12; i++) {
        printf("%hhx", R_E[i]);
    }
    

    //IP


    return 0;

}


