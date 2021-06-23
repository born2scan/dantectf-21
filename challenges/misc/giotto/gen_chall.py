#!/usr/bin/env python3

flag = "DANTE{c0m3_qu31_ch3_v4_d1_n0tt3}"
keywords = {
    "0": "GUELFI",
    "1": "GHIBELLINI"
}

keywords_rev = { value:key for key, value in keywords.items() }

def ascii2binary(s):
    """Convert a string of ASCII chars to binary, padding each char to be (multiples of) 8 bits long"""
    #return bin(int.from_bytes(s.encode(), 'big'))[2:]  # Doesn't account for padding
    b, buff = "", ""
    for c in s:
        buff = bin(ord(c))[2:]
        while len(buff) % 8 != 0:
            buff = "0" + buff
        b += buff
    return b


def binary2ascii(b):
    """Convert a binary string to ASCII chars, given that each char was encoded in (multiples of) 8 bits"""
    #n = int(f"0b{s}", 2)
    #return n.to_bytes((n.bit_length() + 7) // 8, 'big').decode()  # Doesn't account for padding
    s, buff, i = "", "", 0
    for char in b:
        buff += char
        i += 1
        if i % 8 == 0:
            s += chr(int(buff, 2))
            buff = ""
    return s

if __name__ == "__main__":
    # Initial flag
    print(f"-> Flag: {flag}")

    # Binary-encoded flag
    bits = ascii2binary(flag)
    print(f"-> CyberChef-compatible binary encoding:\n{bits}")

    print(f"-> Writing {keywords['0']}-{keywords['1']} encoded string to \"chall.txt\"")
    # Write PING-PONG encoded flag
    with open("chall.txt", "w") as f:
        for bit in bits:
            f.write(keywords[bit] + "\n")

    # Re-read and decode PING-PONG flag to binary
    read_flag = ""
    with open("chall.txt", "r") as f:
        lines = f.readlines()
        for line in lines:
            read_flag += keywords_rev[line.strip()]

    # Binary-decoded flag
    print(f"-> Decoded: {binary2ascii(read_flag)}")
