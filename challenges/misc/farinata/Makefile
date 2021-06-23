.PHONY: all generate clean

all: clean generate

generate:
	python3 gen_flag.py
	sox columns/column*.wav out.wav

clean:
	-rm -r steps/ columns/ out.wav spectrogram.png

solve: clean generate
	sox out.wav -n spectrogram
	xdg-open spectrogram.png