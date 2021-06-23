#!/usr/bin/env python3

import argparse

flag = "VECCHIAFAMA"
wpm = 5

alphabet = {
    "A": ".-",
    "B": "-...",
    "C": "-.-.",
    "D": "-..",
    "E": ".",
    "F": "..-.",
    "G": "--.",
    "H": "....",
    "I": "..",
    "J": ".---",
    "K": "-.-",
    "L": ".-..",
    "M": "--",
    "N": "-.",
    "O": "---",
    "P": ".--.",
    "Q": "--.-",
    "R": ".-.",
    "S": "...",
    "T": "-",
    "U": "..-",
    "V": "...-",
    "W": ".--",
    "X": "-..-",
    "Y": "-.--",
    "Z": "--..",
    "0": "-----",
    "1": ".----",
    "2": "..---",
    "3": "...--",
    "4": "....-",
    "5": ".....",
    "6": "-....",
    "7": "--...",
    "8": "---..",
    "9": "----.",
    "_": "..--.-"
}
lengths = {
    'short': int(1200/wpm),
    'long': int((1200/wpm)*3)
}

targets = ["arduino", "esp", "rp2040"]

def pre(target):
    if target == "arduino" or target == "esp":
        return ""
    elif target == "rp2040":
        return f"""
const uint32_t morse_short = clock * {lengths['short'] / 1000};
const uint32_t morse_long = clock * {lengths['long'] / 1000};\n
"""
    else:
        raise NotImplementedError(f"Unknown target '{target}'")

def post(target):
    if target == "arduino" or target == "esp":
        return "Serial.println();\ndelay(6000);"
    elif target == "rp2040":
        return "printf(\"\\n\");\nsleep_ms(12000);"
    else:
        raise NotImplementedError(f"Unknown target '{target}'")

def morse_short(target):
    if target == "arduino" or target == "esp":
        return f"Serial.print(\".\");\non();\ndelay({lengths['short']});\noff();\n"
    elif target == "rp2040":
        return "printf(\".\");\npush(pio, morse_short);\n"
    else:
        raise NotImplementedError(f"Unknown target '{target}'")

def morse_long(target):
    if target == "arduino" or target == "esp":
        return f"Serial.print(\"-\");\non();\ndelay({lengths['long']});\noff();\n"
    elif target == "rp2040":
        return "printf(\"-\");\npush(pio, morse_long);\n"
    else:
        raise NotImplementedError(f"Unknown target '{target}'")

def morse_pause(target):
    if target == "arduino" or target == "esp":
        return f"delay({lengths['long']});\n"
    elif target == "rp2040":
        return ""
    else:
        raise NotImplementedError(f"Unknown target '{target}'")

def morse_space(target):
    if target == "arduino" or target == "esp":
        return f"Serial.print(\" \");\noff();\ndelay({lengths['long'] * 2});\n"
    elif target == "rp2040":
        return "printf(\" \");\npush(pio, 0);\npush(pio, morse_long * 2);\n"
    else:
        raise NotImplementedError(f"Unknown target '{target}'")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Encode a morse flag into uC code.')
    parser.add_argument('target', choices=targets, help='the uC variant to target')
    args = parser.parse_args()

    morse_flag = ""
    for i, char in enumerate(flag.upper()):
        if char not in alphabet:
            raise NotImplementedError(f"'{char}' is not present in the morse alphabet")
        morse_flag += alphabet[char]
        if i < len(flag) - 1:
            morse_flag += " "

    print(f"{flag} => {morse_flag}")

    target_code = pre(args.target)
    for i, char in enumerate(morse_flag):
        if char == ".":
            target_code += morse_short(args.target)
        elif char == "-":
            target_code += morse_long(args.target)
        elif char == " ":
            target_code += morse_space(args.target)
        if i < len(morse_flag) - 1 and char != " ":
            target_code += morse_pause(args.target)
    target_code += post(args.target)
    print(f"=========\n{args.target} code:\n")
    print(target_code)