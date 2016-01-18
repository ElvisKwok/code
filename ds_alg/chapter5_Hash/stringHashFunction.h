typedef unsigned int Index;

// add up ASCII value of each char.
Index Hash1(const char *Key, int TableSize)
{
    Index HashVal = 0;
    while (*Key != '\0')
        HashVal += *Key++;
    return HashVal % TableSize;
}

// supposed string Key has at least 2 char.
Index Hash2(const char *Key, int TableSize)
{
    return (Key[0]+27*Key[1]+27*27*Key[2]) % TableSize;
}

// good.
// polynomial using Horner principle. H(i) = H(i-1) * 32 + key[i].
Index Hash1(const char *Key, int TableSize)
{
    Index HashVal = 0;
    while (*Key != '\0')
        HashVal = (HashVal << 5) + *Key++;
    return HashVal % TableSize;
}
