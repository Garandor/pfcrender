all:
	pdflatex thesis.tex
	makeglossaries thesis
	pdflatex thesis.tex
	pdflatex thesis.tex
