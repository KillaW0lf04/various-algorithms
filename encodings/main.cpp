#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

enum Value {one=1, two=2, three=3};

void bits_to_string(unsigned char v, char *result) {
   for (int i=0; i < 8; i++)  {
        char bits = v << i;
        bits &= (char) 128;

        if (bits == (char) 128)
            result[i] = '1';
        else
            result[i] = '0';
   }
}

char *encode_data(Value *data, int length, int *encoding_length) {
    *encoding_length = ceil(length / 4.0);
    char *encoding = (char *) calloc(1, *encoding_length);

    for (int i=0; i < length; i++) {
        int index = i / 4;
        int position = i % 4;

        char bitmask;
        if (data[i] == one) {
            bitmask = 0x01;
        }
        if (data[i] == two) {
            bitmask = 0x02;
        }
        if (data[i] == three) {
            bitmask = 0x03;
        }

        bitmask <<= position * 2;
        encoding[index] |= bitmask;
    }

    return encoding;
}

Value *decode_data(char *encoding, int expected_length) {
    Value *data = (Value *) malloc(sizeof(Value) * expected_length);

    for (int i=0; i < expected_length; i++) {
        int index = i / 4;
        int position = i % 4;

        char bitmask = 0x03;
        char bits = encoding[index] >> position * 2;

        bits &= bitmask;

        if (bits == 0x01) {
            data[i] = one;
        }
        if (bits == 0x02) {
            data[i] = two;
        }
        if (bits == 0x03) {
            data[i] = three;
        }
    }

    return data;
}

#define BUFLEN 10

int main()
{
    char buffer[8];

    Value data[BUFLEN] = {
        one, two, three, one, one,
        three, three, two, one, two,
    };

    int encoding_length;
    char *encoding = encode_data(data, BUFLEN, &encoding_length);
    Value *new_data = decode_data(encoding, BUFLEN);

    cout << "Original Data: ";
    for (int i=0; i<BUFLEN; i++)
        cout << data[i];
    cout << endl;

    cout << "Encoding: ";
    for (int i=0; i < encoding_length; i++) {
        bits_to_string(encoding[i], buffer);
        cout << buffer;
    }
    cout << endl;

    cout << "Decoded Data: ";
    for (int i=0; i<BUFLEN; i++)
        cout << new_data[i];
    cout << endl;
}

