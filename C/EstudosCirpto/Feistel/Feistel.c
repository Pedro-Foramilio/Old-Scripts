#include <stdio.h>

unsigned int aplicar_feistel(unsigned int bloco, unsigned int key)
{
    // Mask for the lower half (4 least significant bits)
    unsigned int lowerHalfMask = 0b00001111;
    unsigned int lowerHalf = bloco & lowerHalfMask;

    // Mask for the upper half (4 most significant bits)
    unsigned int upperHalfMask = 0b11110000;
    unsigned int upperHalf = (bloco & upperHalfMask) >> 4;

    unsigned int partial = lowerHalf ^ key;

    unsigned int finalLower = upperHalf ^ partial;

    // Swap upper and lower halves
    unsigned int newUpperHalf = lowerHalf;
    unsigned int newLowerHalf = finalLower;

    // Combine upper and lower halves with left shift
    unsigned int result = (newUpperHalf << 4) | newLowerHalf;

    //printf("Original Binary: 0b%08b\n", bloco);
    //printf("Key:             0b%04b\n", key);
    //printf("Lower Half:      0b%04b\n", lowerHalf);
    //printf("Upper Half:      0b%04b\n", upperHalf);
    //printf("Partial:         0b%04b\n", partial);
    //printf("XOR Result:      0b%08b\n", result);
    return result;
}

unsigned int desaplicar_feistel(unsigned int bloco, unsigned int key)
{
    // Mask for the lower half (4 least significant bits)
    unsigned int lowerHalfMask = 0b00001111;
    unsigned int lowerHalf = bloco & lowerHalfMask;

    // Mask for the upper half (4 most significant bits)
    unsigned int upperHalfMask = 0b11110000;
    unsigned int upperHalf = (bloco & upperHalfMask) >> 4;

    // Swap upper and lower halves
    unsigned int newUpperHalf = lowerHalf;
    unsigned int newLowerHalf = upperHalf;

    // XOR the halves
    unsigned int partial = newLowerHalf ^ key;
    unsigned int finalUpper = newUpperHalf ^ partial;

    // Combine upper and lower halves with left shift
    unsigned int result = (finalUpper << 4) | newLowerHalf;

    //printf("Original Binary: 0b%08b\n", bloco);
    //printf("Key:             0b%04b\n", key);
    //printf("Lower Half:      0b%04b\n", lowerHalf);
    //printf("Upper Half:      0b%04b\n", upperHalf);
    //printf("Partial:         0b%04b\n", partial);
    //printf("XOR Result:      0b%08b\n", result);
    return result;
}

int main()
{
    unsigned int bin1 = 0b11000011;
    unsigned int key1 = 0b0110;
    unsigned int key2 = 0b1100;

    unsigned int cipher = aplicar_feistel(aplicar_feistel(bin1, key1), key2);
    unsigned int decipher = desaplicar_feistel(desaplicar_feistel(cipher, key2), key1);
    
    printf("Original: 0b%08b\n", bin1);
    printf("cipher:   0b%08b\n", cipher);
    printf("decipher: 0b%08b\n", decipher);

    return 0;

}
