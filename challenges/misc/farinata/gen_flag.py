#!/usr/bin/env python3

import os

flag = """
             ###                 ###                  #                     #                                    #          
     ####   #   #  ##### #####  #   #          #####  #    #  #      #      #    #          #      #    # #    # #    #     
    #      #     #   #     #   #     #         #    # #    #  #      #      #    #          #      #    # ##   # #    #     
     ####  #  #  #   #     #   #  #  #         #    # #    #  #      #      #    #          #      #    # # #  # #    #     
         # #     #   #     #   #     #         #    # ####### #      #      #######         #      #    # #  # # #######    
    #    #  #   #    #     #    #   #          #    #      #  #      #           #          #      #    # #   ##      #     
     ####    ###     #     #     ###           #####       #  ###### ######      #          ######  ####  #    #      #     
                                       #######                                      #######                                 
"""
min_freq, max_freq = 10_000, 15_000 # Hz
segment_length = 0.050 # s
filler_freq = 0 # Hz

print(
    f"Generating audio spectrum flag with frequencies from {min_freq} to {max_freq} Hz, " + 
    f"segment length of {segment_length}s, and filler freq of {filler_freq} Hz"
)

split_lines = list(filter(None, flag.splitlines()))
x_max = len(split_lines[0])
y_max = len(split_lines)

print("Generating segments matrix...")
matrix = [[' ' for y in range(y_max)] for x in range(x_max)]
for row in range(y_max):
    for column in range(len(split_lines[row])):
        matrix[column][row] = split_lines[row][column] == "#"

print("Calculating frequency steps...", end='\r')
rows_amt = len(matrix[0])
step_freq = int((max_freq - min_freq) / rows_amt)
print(f"Calculated frequency steps: {step_freq} Hz")

print("Generating single step waveforms...")
os.system("mkdir steps")
os.system(f"sox -r 48000 -n -b 16 -c 1 steps/step_.wav synth {segment_length} sin {filler_freq} vol -10db")
for i in range(rows_amt):
    os.system(f"sox -r 48000 -n -b 16 -c 1 steps/step{i}.wav synth {segment_length} sin {min_freq + (step_freq * i)} vol -10db")

print("Preparing columns...")
cmds = []
for col_n, column in enumerate(matrix):
    column_steps, step_files = ["_"], []
    col_str = str(col_n).zfill(len(str(len(matrix))))
    for row_n, row in enumerate(column):
        if row:
            column_steps.append((len(column) - 1) - row_n)
    for step in column_steps:
        step_files.append(f"steps/step{step}.wav")
    cmds.append(f"sox {'-m' if len(step_files) > 1 else '  '} {' '.join(step_files)} columns/column{col_str}.wav")

print("Generating columns...")
os.system("mkdir columns")
for cmd in cmds:
    #print(cmd)
    os.system(cmd)
print("Done: concatenate files in ./columns with sox")
